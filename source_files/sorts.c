/*********************************FILE__HEADER*********************************\
* File:				sorts.c
* Author:			Daniel Brodsky				 		  												  								
* Date:				02-06-2021
* Code Reviewer:	Eran
* Pseudo Reviewer: 	Ariel/Eran				   								
* Version:			1.0   								
* Description:		Sorts and searches algorithms implementations. 
\******************************************************************************/

/********************************* Inclusions *********************************/

#include <assert.h>		/*	assert	*/


/******************************* Macros & enums *******************************/



/**************************** Structs  Definitions ****************************/



/**************************** Forward Declarations ****************************/



/************************* Functions  Implementations *************************/

int *BinarySearchIter(const int SortedArray[], int query, size_t length)
{

}
/******************************************************************************/
int *BinarySearchRec(const int SortedArray[], int query, size_t length)
{

/*	begin = sorted_arr; // first elemenet of the array	*/
/*	last = begin + length - 1; // last elemenet in the array	*/

/*	if length == 1		*/
/*	{
		return (query == *sorted_arr ? *sorted_arr : NULL);
	}
/*		mid = (begin + last) / 2;	*/

/*	isBigger = query > *mid;*/
	
/*	return BinarySearchRec(sorted_arr+(mid + 1)*IsBigger, query, isBigger * (length - length /2 ) + !isbigger*(length/2))*/
/*	
}
/******************************************************************************/
int *MergeArrIMP(int arr1[], int arr2[], size_t arr1_size, size_t arr2_size)
{
/*	asserts*/
	/*	create an array that will be the sorted array of the size of arr1_size + arr2_size */
	/*	lets call it sorted_arr , handle allocation errors if any*/
	/*	*/
	/*	while both arrays have elements:*/
	/*		if arr1[0] > arr2[0]:*/
	/*			add arr2[0] to the end of sorted_arr*/
	/*			increment arr2 ptr*/
	/*		else*/
	/*			add arr1[0] to sorted_arr*/
	/*			increment arr1 ptr*/
	/*			*/
	/*	while either of the array has elemenets:*/
	/*		add each elemenet from that array to sorted_arr and increment ptr*/
	/*		*/
	
	/*	return sorted_arr*/
}

int MergeSort(int arr_to_sort[], size_t num_of_elements)
{
/*	asserts*/
	/*	base condition:*/
	/*	if only one elemenet in the array */
	/*		return array*/
	/*	*/
	/*	left_array = left half of the array, size: num_of_elements/2*/
	/*	right_array = right half of the array, size: num_of_elements - size of left_array*/
	/*	sort each side of the array 		*/
	/*	left_side_sorted = MergeSort(left_array)*/
	/*	right_side_sorted = MergeSort(right_array)*/
	/*	send 2 sorted arrays to MergeArrIMP to merge them	*/
	/*	return MergeArrIMP(left_side_sorted, right_side_sorted, left_array size, right_array size)*/
}
/******************************************************************************/
void SwapPtrValues(void *ptr1, void *ptr2, size_t size_of_elem)
{
/*	asserts*/
/*	while size_of_elem:*/
/*			look at both ptrs as (char *)		*/
/*			xor swap between each char:*/
/*				*(char *)ptr1 ^= *(char *)ptr2;*/
/*				*(char *)ptr2 ^= *(char *)ptr1;*/
/*				*(char *)ptr1 ^= *(char *)ptr2;*/
/*	end while*/
}

void *PartitionIMP(void *left, void *right, void *pivot)
{
/*	assert*/
	/*   leftPointer = left */
	/*   rightPointer = right */
	/*	while rightPointer != leftPointer	*/
			/*      while leftPointer <= pivot && still inside the array range */
			/*         ++leftPointer            */
			/*      end while*/
			/*		*/
			/*      while rightPointer > pivot: */
			/*         ++rightPointer         */
			/*      end while*/
			/*		*/
			/*      if leftPointer != rightPointer*/
			/*         swap leftPointer,rightPointer*
					/*      end if*/
	/*   end while */
	/*	*/
	/*   swap leftPointer,pivot*/
	/*   return leftPointer*/
	/*	*/
	/*end function*/
}
void QSort(void *base, size_t nmemb, size_t size, int (*compar)(const void *,
																const void *))
{
	/*asserts*/

	/*left = base*/
	/*right = base + nmemb - 1;*/

	/*if right == left:*/
	/*return*/


	/*pivot = (base + right) / 2; // middle element in the array*/
	/*partition = PartitionIMP(left, right, pivot)*/
	/*quickSort(left,partition-1)*/
	/*quickSort(partition+1,right)    */
	/*end if	*/
		
}
/******************************************************************************/
