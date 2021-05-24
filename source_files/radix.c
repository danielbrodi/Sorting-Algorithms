/*********************************FILE__HEADER*********************************\
* File:				radix.c
* Author:			Daniel Brodsky				 		  												  								
* Date:				23/05/2021
* Code Reviewer:
* Pseudo Reviewer:	Danel					   								
* Version:			1.0   								
* Description:		Radix sort algorithm implementation pseudo code. 
\******************************************************************************/


/*************************** Functions  Pseudocodes ***************************/

/* sorts by the bits found in range from_bit to to_bit of key 				*/
void CountingSortIMP(pair_ty *dest, pair_ty *src, size_t num_of_pairs,
							size_t *histogram, size_t from_bit, size_t to_bit)
{
/*	assert*/

/*	for each key in src:													*/
/*		"shake" all other bits other than from_bit and to_bit by shifting right and left */
/*		incremet the corresponding index in histogram array					*/

/*	for each index in histogram:											*/
/*		sum the current value with the value before							*/
/*		promote key															*/

/*	for each key in src (run from the end of the array):					*/
/*		go to corresponding index in histogram array: decrement value		*/
/*		go to corresponding index to that value in dest array and 
														insert the pair	*/
	
}

/* returns non-zero if fail to allocate memory 								*/
/* space complexity of size O(n) 											*/
int RadixSort(void *dest, void *src, size_t num_of_elements, size_t element_size,
					ConvertFunc DataToKey, size_t msb, size_t num_of_digits)
{
	/*	assert*/

	/*	create histogram array of size of the base of the src array elements*/
	/*	handle errors if any												*/
	/*	nullify histogram													*/

	/*	create 2 pair_ty arrays, handle errors if any						*/

	/*	for each element in src arr: 										*/
	/*		copy ptr and extracted key to src_pair array using DataToKey	*/
	
	/*	for num_of_digits: 													*/
	/*		call CountingSortIMP with current subset of bits				*/
	/*		switch src_pair and dest_pair ptrs								*/
	/*		promote bit indexes to next subset								*/
	
	/*	copy src_pair to void* dest											*/
}c	
