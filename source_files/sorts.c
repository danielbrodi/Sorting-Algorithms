/*********************************FILE__HEADER*********************************\
* File:				sorts.c
* Author:			Daniel Brodsky				 		  												  								
* Date:				02-06-2021
* Code Reviewer:	
* Pseudo Reviewer: 						   								
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
	/*	asserts												*/
	/*	check the middle of the array:*/
	/*	middle -> i = length / 2:*/
	/*	if query equals arr[i] then return arr+i.	*/
	/*while (middle elemenet != query && iterantion <= log(length))	*/
	/*{
	/*	if midde elemenet < query:		*/
	/*		update middle elemenet index to middle of the right half;	*/
	/*	else midde elemenet > query:	*/
	/*		update middle elemenet index to middle of the left half;*/
	
	/*	++iterantion;	*/
	/*}

	/*if a[i] == query:*/
	/*	return arr+i*/
	/*	*/
	/*return null.*/

}
/******************************************************************************/
int *BinarySearchRec(const int SortedArray[], int query, size_t length)
{

/*	start = sorted_arr; // first elemenet of the array	*/
/*	end = start + length; // last elemenet in the array	*/

/*	if length == 0		*/
/*	{
		return null
	}
/*		mid = start + length/2;	*/

/*		if mid equals query : return mid;	*/

/*		query > *mid ? return BinarySearchRec(sorted_arr+mid+1, query, length/2);	*/

/*		query < *mid ? return BinarySearchRec(sorted_arr, query, length/2);	*/
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
void QSort(void *base, size_t nmemb, size_t size, int (*compar)(const void *,
																const void *))
{
	asserts
	
	choose middle elemenet as a pivot:
		
}
/******************************************************************************/
