/*********************************FILE__HEADER*********************************\
* File:				radix.c
* Author:			Daniel Brodsky				 		  												  								
* Date:				23/05/2021
* Code Reviewer:
* Pseudo Reviewer:	Danel					   								
* Version:			1.0   								
* Description:		Radix sort algorithm implementation pseudo code. 
\******************************************************************************/
/********************************* Inclusions *********************************/

#include <assert.h>			/*	assert			*/
#include <stddef.h>			/*	size_t, NULL	*/
#include <stdlib.h>			/*	malloc, free	*/

#include "utils.h"
#include "radix.h"

/************************* Functions  Implementations *************************/

/* sorts by the bits found in range from_bit to to_bit of key 				*/
void CountingSortIMP(pair_ty *dest, pair_ty *src, size_t num_of_pairs,
							size_t *histogram, size_t from_bit, size_t to_bit)
{
	/*	asserts to assure the received parameters are valid					*/
	assert(dest && src && histogram && num_of_pairs && to_bit);

/*	for each key in src:													*/
	while (src->element)
	{
	/*		"shake" all other bits other than from_bit and to_bit by shifting right and left */
	/*		incremet the corresponding index in histogram array					*/
	}
/*	for each index in histogram:											*/
/*		sum the current value with the value before							*/
/*		promote key															*/

/*	for each key in src (run from the end of the array):					*/
/*		go to corresponding index in histogram array: decrement value		*/
/*		go to corresponding index to that value in dest array and 
														insert the pair	*/
	
}
/******************************************************************************/
/* returns non-zero if fail to allocate memory 								*/
/* space complexity of size O(n) 											*/
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
	
	/*	create an histogram array of size of the base of the src elements	*/
	/*	handle errors if any												*/
	/*	nullify histogram using calloc										*/
	/* TODO can make a func to make size_t nullified array	*/
	histogram = (size_t *)calloc((size_t)base, sizeof(size_t);
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
	
	/*	for each element in src arr: 										*/
	/*	copy ptr and extracted key to src_pair array using DataToKey		*/
	while (src)
	{
		(*src_pair).key = DataToKey(src);
		(*src_pair).element = src;
		
		src += (char *)element_size;
		++src_pair;
	}
	
	/*	for num_of_digits: 													*/
	while (num_of_digits)
	{
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
	
	/*	copy src_pair to void* dest											*/
	/* 	TODO maybe create a func that copies arrays? but they are from different types.. so maybe not 	*/
	while(src_pair->element)
	{
		*dest = (*src_pair).element;
		
		++src_pair;
		dest += (char *)element_size;
	}
	
	int (0);
}
