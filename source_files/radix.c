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
	/*
		Iterate the src array and find the maximum value present in it.
		Declare a new counting array of size max+1 with value 0.
		Count each and every element in the array and increment its value 
		at the right index in the counting array.
		Find cumulative sum is the counting array we adding curr and 
		prev frequency.
		Now the cumulative value actually signifies the actual location
		of the element in the sorted dest array.
		Start iterating counting array from 0 to max:
			Put 0 at the right index and reduce the count by 1, 
			which will signify the second position of the element if it
			exists in the input array.
		Now transfer array received in the above step in the dest input array.
	*/
}

/* returns non-zero if fail to allocate memory 					*/
/* space complexity of size O(n) 								*/
int RadixSort(void *dest, void *src, size_t num_of_elements, size_t element_size,
					ConvertFunc DataToKey, size_t msb, size_t num_of_digits)
{
	/*
		init src and dest arrays, lets call them input[] & output[]:
			create pair_ty arr of size of num_of_elements * element_size;
		
		
		
	*/
}
