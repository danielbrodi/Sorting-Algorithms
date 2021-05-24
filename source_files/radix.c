/*********************************FILE__HEADER*********************************\
* File:				radix.c
* Author:			Daniel Brodsky				 		  												  								
* Date:				23/05/2021
* Code Reviewer:
* Pseudo Reviewer:	Danel					   								
* Version:			1.0   								
* Description:		Radix sort implementation. 
\******************************************************************************/
/********************************* Inclusions *********************************/

#include <assert.h>			/*	assert			*/
#include <stddef.h>			/*	size_t, NULL	*/
#include <stdlib.h>			/*	malloc, free	*/

#include "utils.h"
#include "radix.h"

/******************************* Macros & enums *******************************/

#define KEY_SIZE (sizeof(size_t))

/************************* Functions  Implementations *************************/

/* sorts by the bits found in range from_bit to to_bit of key 			*/
void CountingSortIMP(pair_ty *dest, pair_ty *src, size_t num_of_pairs,
							size_t *histogram, size_t from_bit, size_t to_bit)
{
	size_t key = 0, i = 0;
	size_t histogram_size = 1 << (to_bit - from_bit);
	
	/*	asserts to assure the received parameters are valid				*/
	assert(dest && src && histogram && num_of_pairs && to_bit);

/*	for each key in src:												*/
	while (src->element)
	{
		key = src->key;
		/*	shift the key to the right and to the left in order to 
	 	*	leave it only with the range of bits that should be sorted	*/
		key <<= KEY_SIZE - 1 - to_bit;
		key >>= KEY_SIZE - 1 - to_bit + from_bit;
	
		/*	incremet the corresponding index in histogram array			*/
		++histogram[key];
	}
	
	CumulativeSumHistogramIMP(histogram, histogram_size);

	/*	for each key in src (run from the end of the array):			*/
	for (i = num_of_pairs - 1; i >= 0; --i)
	{
		/*	go to corresponding index in histogram array	*/
		/* decrement value									*/
		--(histogram[i]);
		/*	go to corresponding index to that value  
		 *	in dest array and insert the pair				*/
		 dest[histogram[i]] = i;
	}
}
/******************************************************************************/
int RadixSort(void *dest, void *src, size_t num_of_elements, size_t element_size,
					ConvertFunc DataToKey, size_t msb, size_t num_of_digits)
{
	pair_ty *src_pair = NULL, *dest_pair = NULL;
	
	size_t *histogram = NULL;
	
	size_t from_bit = 0, to_bit = 0, step = 0;
	
	/*	base of the element that needs to be sorted							*/
	unsigned int base = 1;
	
	/*	asserts to assure the received parameters are valid					*/
	assert(dest && src && num_of_elements && num_of_digits && element_size);
	assert(DataToKey);
	
	/* TODO should make RoundUp func to make life easier */
	base = base << ((msb + 1) / num_of_digits);	
	/* TODO should make RoundUp func to make life easier and a correct var*/
	to_bit = ((msb + 1) / num_of_digits);	
	
	step = to_bit + 1;
	
	histogram = BuildHistogramIMP(base);
	if (!histogram)
	{
		return (1);
	}
	
	/*	create 2 pair_ty arrays, handle errors if any						*/
	/* TODO can make a func to make pair_ty array	*/
	src_pair = (pair_ty *)malloc(sizeof(element_size) * num_of_elements);
	if (!src_pair)
	{
		free(histogram);
		histogram = NULL;
		
		return (1);
	}
	
	dest_pair = (pair_ty *)malloc(sizeof(src_pair));
	if (!dest_pair)
	{
		free(src_pair);
		src_pair = NULL;
		
		free(histogram);
		histogram = NULL;
		
		return (1);
	}
	
	FIllPairSrcFromSrcIMP(src_pair, src, DataToKey);
	
	/*	for num_of_digits: 													*/
	while (num_of_digits)
	{
		WipeHistogramIMP(histogram, base);
		
		/*	call CountingSortIMP with current subset of bits	*/
		CountingSortIMP(dest_pair, src_pair, num_of_elements, histogram, 
															from_bit, to_bit);
															
		/*	switch src_pair and dest_pair ptrs					*/
		SwitchPtrs(src_pair, dest_pair);
		
		/*	promote bit indexes to next subset					*/
		from_bit += step;
		to_bit += step;
		
		--num_of_digits;
	}
	
	FillDestFromPairDestIMP(void *dest, pair_ty *src_pair, element_size);
	
	int (0);
}
/******************************************************************************/
void FIllPairSrcFromSrcIMP(pair_ty *dest, void *src, ConvertFunc DataToKey)
{
	assert (dest && src);
	assert(DataToKey);
	
	/*	for each element in src arr: 										*/
	/*	copy ptr and extracted key to src_pair array using DataToKey		*/
	while (src->element)
	{
		(*dest).key = DataToKey(src);
		src_pair->element = src;
		
		src += (char *)element_size;
		++dest;
	}
}
/******************************************************************************/
void FillDestFromPairDestIMP(void *dest, pair_ty *src, size_t element_size)
{
	assert(dest && src);
	
	/*	copy src_pair to void* dest											*/
	while(src_pair->element)
	{
		*dest = (*src_pair).element;
		
		++src_pair;
		dest += (char *)element_size;
	}
}
/******************************************************************************/
size_t *BuildHistogramIMP(unsigned int size)
{
	assert(size > 0);
	
	/*	create an histogram array of size of the base of the src elements	*/
	/*	handle errors if any												*/
	/*	nullify histogram using calloc										*/
	new_histogram = (size_t *)calloc((size_t)base, sizeof(size_t);
	if (!histogram)
	{
		return (NULL);
	}
	
	return (new_histogram);
}
/******************************************************************************/
void WipeHistogramIMP(size_t *histogram, unsigned int size)
{
	assert(histogram);
	
	memset(histogram, 0, size);
}
/******************************************************************************/
void CumulativeSumHistogramIMP(size_t *histogram, size_t size)
{
	size_t i = 0;
	
	assert(histogram, size > 1);
	
	/*	for each index in histogram:									*/
	for (i = 1; i < histogram_size; ++i)
	{
		/*	sum the current value with the value before					*/
		histogram[i] += histogram[i - 1];
	}
}
