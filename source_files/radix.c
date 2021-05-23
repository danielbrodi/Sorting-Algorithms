/*********************************FILE__HEADER*********************************\
* File:				radix.c
* Author:			Daniel Brodsky				 		  												  								
* Date:				23/05/2021
* Code Reviewer:	 						   								
* Version:			1.0   								
* Description:		Radix sort algorithm implementation pseudo code. 
\******************************************************************************/


/*************************** Functions  Pseudocodes ***************************/

/* sorts by the bits found in range from_bit to to_bit of key 	*/
void CountingSortIMP(pair_ty *dest, pair_ty *src, size_t num_of_pairs,
							size_t *histogram, size_t from_bit, size_t to_bit)
{
	/* */
}

/* returns non-zero if fail to allocate memory 					*/
/* space complexity of size O(n) 								*/
int RadixSort(void *dest, void *src, size_t num_of_elements, size_t element_size,
					ConvertFunc DataToKey, size_t msb, size_t num_of_digits)
{
	/*	assert*/

	/*	create histogram array of size of (msb + 1 / num_of_digits)			*/
	/*	handle errors if any												*/

	/*	create 2 pair_ty arrays, handle errors if any						*/

	/*	for each element in src arr: 										*/
	/*		copy ptr and extracted key to src_pair array					*/
	
	/*	for num_of_digits: 													*/
	/*		nullify histogram												*/
	/*		call CountingSortIMP with current subset of bits				*/
	/*		switch src_pair and dest_pair arrays							*/
	/*		promote bit indexes to next subset								*/
	
}
