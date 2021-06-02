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
	/*	asserts*/
	/*	*/
	/*	go to the middle of the array*/
	/*	return if equals to query*/
	/*	if not:*/
	/*		while value in the array is not equal to query:*/
	/*			if query is smaller than the value in the array:*/
	/*				move to the middle of the left side and check again.*/
	/*			else:*/
	/*				move to the middle of the right side and check again.*/
	/*				*/
	/*			return found index.*/
}

/******************************************************************************/
int *BinarySearchRec(const int SortedArray[], int query, size_t length)
{
	/*	asserts*/
	/*	*/
	/*	if arr[i] equals query*/
	/*	return i*/
	/*	*/
	/*	if query < arr[i]*/
	/*		go to middle of the left side which means index i/2*/
	/*	*/s
	/*	if query > arr[i]*/
	/*		go to middle of the right side which means length-i/2*/
	/*	*/
	/*	recursivly run the func*/
}

/******************************************************************************/
int MergeSort(int arr_to_sort[], size_t num_of_elements)
{
	
}


/******************************************************************************/
