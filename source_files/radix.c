/*********************************FILE__HEADER*********************************\
* File:				radix.c
* Author:			Daniel Brodsky				 		  												  								
* Date:				23/05/2021
* Code Reviewer:	Danel				   								
* Version:			1.5   								
* Description:		Radix sort implementation. 
\******************************************************************************/

/********************************* Inclusions *********************************/

#include <assert.h>			/*	assert						*/
#include <limits.h>			/*	CHAR_BIT					*/
#include <stddef.h>			/*	size_t, NULL				*/
#include <stdlib.h>			/*	calloc, malloc, free		*/
#include <string.h>			/*	memset						*/

#include "utils.h"
#include "radix.h"

/******************************* Macros & enums *******************************/

/* 	The size of the key which being sorted. 
 *	May be change by clients request										*/
enum
{
	KEY_SIZE = sizeof(size_t)
};

/**************************** Structs  Definitions ****************************/

/*	define the structure of each element in an array of pairs				*/
typedef struct pair
{
	size_t key;
	void *element;
}pair_ty;

/**************************** Forward Declarations ****************************/

/* sorts by the bits found in range from_bit to to_bit of key 				*/
static void CountingSortIMP(pair_ty *dest, pair_ty *src, size_t num_of_pairs,
							size_t *histogram, size_t from_bit, size_t to_bit);

/*	Fills up a pairs array by extracting a data key from a given array		*/
static void FillPairSrcFromSrcIMP(pair_ty *dest, void *src,
			size_t num_of_elements, size_t element_size, ConvertFunc DataToKey);
			
/*	Fills up a sorted elements array by copying their order from an
 *	array which sorted them by their data key	 							*/
static void FillDestFromPairDestIMP(void *dest, pair_ty *src,
								size_t num_of_elements, size_t element_size);
								
/*	Creates an histogram of data that located in a specific range of bits
	of elements in a given array					 						*/
static void BuildHistogramIMP(pair_ty *src, size_t *histogram, 
						size_t num_of_pairs, size_t from_bit, size_t to_bit);
						
/*	Nullifies an histogram array											*/
static void WipeHistogramIMP(size_t *histogram, size_t size);

/*	Sets the value of each element as the cumulative sum of its previous	*/
static void CumulativeSumHistogramIMP(size_t *histogram, size_t size);

/*	Swaps the addresses that being pointed by two pointers with each other	*/
static void SwapPairPointersIMP(pair_ty **ptr1, pair_ty **ptr2);

/*	Sorts data keys in an array by their histogram 							*/
static void SortKeysIMP(pair_ty *dest, pair_ty *src, size_t *histogram,
						size_t num_of_pairs, size_t from_bit, size_t to_bit);
						
/*	Frees memory that is being used by given arrays							*/
static void FreeAllIMP(pair_ty *src, pair_ty *dest, size_t *histogram);

/*	Round up a given number to the nearest multiple of an other number		*/
static size_t RoundUpIMP(size_t num, size_t multiplation);

/************************* Functions  Implementations *************************/

int RadixSort(void *dest, void *src, size_t num_of_elements, size_t element_size,
					ConvertFunc DataToKey, size_t msb, size_t num_of_digits)
{
	pair_ty *src_pair = NULL, *dest_pair = NULL;
	
	size_t *histogram = NULL;
	
	size_t from_bit = 0, to_bit = 0, step = 0, RoundedMSB = 0;
	
	/*	histogram's array size is the base of the elements which need
	 *	to be sorted										*/
	size_t histogram_size = 1;	
	
	/*	asserts to assure the received parameters are valid					*/
	assert(dest);
	assert(src);
	assert(num_of_elements);
	assert(num_of_digits);
	assert(element_size);
	assert(DataToKey);
	
	RoundedMSB = RoundUpIMP(msb, num_of_digits);
	
	to_bit = RoundedMSB / num_of_digits;
	--to_bit; /*	move back one bit because bits start from 0				*/

	/* 	by how many bits to promote the bits each iteration to include only
	 *	one digit															*/
	step = to_bit - from_bit;
	++step;	/* incremet step by one to correct the range of bits			*/
	
	/*	calculates the base of the elements which need to be sorted			*/
	histogram_size = histogram_size << step;	
	
	/*	create an histogram array of size of the base of the src elements	*/
	/*	handle errors if any												*/
	/*	nullify histogram using calloc										*/
	histogram = (size_t *)calloc(histogram_size, sizeof(size_t));
	if (!histogram)
	{
		return (1);
	}
	
	/*	create 2 pair_ty arrays, handle errors if any						*/
	src_pair = (pair_ty *)malloc(sizeof(pair_ty) * num_of_elements);
	if (!src_pair)
	{
		free(histogram);
		histogram = NULL;
		
		return (1);
	}
	
	dest_pair = (pair_ty *)malloc(sizeof(pair_ty) * num_of_elements);
	if (!dest_pair)
	{
		free(src_pair);
		src_pair = NULL;
		
		free(histogram);
		histogram = NULL;
		
		return (1);
	}
	
	FillPairSrcFromSrcIMP(src_pair, src, num_of_elements, element_size,
																	DataToKey);
	
	while (num_of_digits)
	{
		WipeHistogramIMP(histogram, histogram_size);
		
		/*	call CountingSortIMP with current subset of bits				*/
		CountingSortIMP(dest_pair, src_pair, num_of_elements, histogram, 
															from_bit, to_bit);
															
		/*	switch src_pair and dest_pair ptrs								*/
		SwapPairPointersIMP(&src_pair, &dest_pair);
		
		/*	promote bit indexes to next subset								*/
		from_bit += step;
		to_bit += step;
		
		--num_of_digits;
	}
	
	FillDestFromPairDestIMP(dest, src_pair, num_of_elements, element_size);
	
	FreeAllIMP(src_pair, dest_pair, histogram);
	src_pair = NULL;
	dest_pair = NULL;
	histogram = NULL;
	
	return (0);
}
/******************************************************************************/
void CountingSortIMP(pair_ty *dest, pair_ty *src, size_t num_of_pairs,
							size_t *histogram, size_t from_bit, size_t to_bit)
{
	size_t histogram_size = 1;

	/*	asserts to assure the received parameters are valid					*/
	assert(dest);
	assert(src);
	assert(histogram);
	assert(num_of_pairs);
	assert(to_bit);
	
	/*	calculates the base of the elements which need to be sorted			*/
	histogram_size <<= (to_bit - from_bit + 1);

	BuildHistogramIMP(src, histogram, num_of_pairs, from_bit, to_bit);
	
	CumulativeSumHistogramIMP(histogram, histogram_size);
	
	SortKeysIMP(dest, src, histogram, num_of_pairs, from_bit, to_bit);
}
/******************************************************************************/
void FillPairSrcFromSrcIMP(pair_ty *dest, void *src, size_t num_of_elements,
									size_t element_size, ConvertFunc DataToKey)
{
	assert(dest);
	assert(src);
	assert(DataToKey);

	/*	for each element in src arr: 										*/
	/*	copy ptr and extracted key to src_pair array using DataToKey		*/
	while (num_of_elements)
	{
		dest->key = DataToKey(src);
		dest->element = src;
		
		src = (char *)src + element_size;
		++dest;
		
		--num_of_elements;
	}
}
/******************************************************************************/
void FillDestFromPairDestIMP(void *dest, pair_ty *src, 
									size_t num_of_elements, size_t element_size)
{
	assert(dest);
	assert(src);
	
	/*	copy src_pair to void* dest											*/
	while(num_of_elements)
	{
		memcpy(dest, src->element, element_size);
		
		dest = (char *)dest + element_size;
		++src;
		
		--num_of_elements;
	}
}
/******************************************************************************/
void BuildHistogramIMP(pair_ty *src, size_t *histogram, size_t num_of_pairs,
												size_t from_bit, size_t to_bit)
{
	size_t key = 0;
	
	assert(src);
	assert(histogram);
	assert(to_bit);
	
	/*	for each key in src:												*/
	while (num_of_pairs)
	{
		key = src->key;
		/*	shift the key to the right and to the left in order to 
	 	*	leave it only with the range of bits that should be sorted		*/
		key <<= (KEY_SIZE * (CHAR_BIT) - 1 - to_bit);
		key >>= (KEY_SIZE * (CHAR_BIT) - 1 - to_bit + from_bit);
	
		/*	incremet the corresponding index in histogram array				*/
		++histogram[key];
		
		++src;
		--num_of_pairs;
	}
}
/******************************************************************************/
void WipeHistogramIMP(size_t *histogram, size_t size)
{
	assert(histogram);
	assert(size);
	
	memset(histogram, 0, size * sizeof(size_t));
}
/******************************************************************************/
void CumulativeSumHistogramIMP(size_t *histogram, size_t size)
{
	size_t i = 0;
	
	assert(histogram);
	assert(size > 1);
	
	/*	for each index in histogram:										*/
	for (i = 1; i < size; ++i)
	{
		/*	sum the current value with the value before						*/
		histogram[i] += histogram[i - 1];
	}
}
/******************************************************************************/
void SwapPairPointersIMP(pair_ty **ptr1, pair_ty **ptr2)
{
	pair_ty *temp = NULL;
	
	assert(*ptr1);
	assert(*ptr2);
	
	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}
/******************************************************************************/
void SortKeysIMP(pair_ty *dest, pair_ty *src, size_t *histogram,
							size_t num_of_pairs, size_t from_bit, size_t to_bit)
{
	int i = 0, pairs = (int)num_of_pairs;
	
	size_t key = 0;
	
	assert(src);
	assert(dest);
	assert(histogram);
	assert(num_of_pairs);
	assert(to_bit);
	
	/*	for each key in src (run from the end of the array):				*/
	for (i = pairs - 1; i >= 0; --i)
	{
		key = src[i].key;
		
		/*	shift the key to the right and to the left in order to 
	 	*	leave it only with the range of bits that should be sorted		*/
		key <<= (KEY_SIZE * (CHAR_BIT) - 1 - to_bit);
		key >>= (KEY_SIZE * (CHAR_BIT) - 1 - to_bit + from_bit);
		
		/*	go to corresponding index in histogram array					*/
		/* decrement value													*/
		--(histogram[key]);
		
		/*	go to corresponding index to that value  
		 *	in dest array and insert the key								*/
		 dest[histogram[key]] = src[i];
	}
}
/******************************************************************************/
void FreeAllIMP(pair_ty *src, pair_ty *dest, size_t *histogram)
{
	free(src);
	free(dest);
	free(histogram);
}
/******************************************************************************/
size_t RoundUpIMP(size_t num, size_t multiplation)
{
	return (num + multiplation - 1 - (num + multiplation - 1) % multiplation);
}
/******************************************************************************/
