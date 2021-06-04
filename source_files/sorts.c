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

#include <assert.h>		/*	assert			*/
#include <stddef.h>		/*	size_t, NULL	*/
#include <stdlib.h>		/*	malloc, free	*/

#include "sorts.h"

/**************************** Forward Declarations ****************************/
static int *MergeArrIMP(int arr1[], int arr2[], size_t size1, size_t size2);

static void *PartitionIMP(void *left, void *right, void *pivot);

void SwapPtrsValues(void *ptr1, void *ptr2, size_t size_of_elem);
/************************* Functions  Implementations *************************/

int *BinarySearchIter(const int SortedArray[], int key, size_t length)
{
	/*	variables that will set the boundries of the searched area		*/
	int left_index = 0, right_index = 0, middle = 0;
	int *result = NULL;
	
	assert(SortedArray);
	assert(length);
	
	left_index = 0; 			/*	first elemenet in the array			*/
	right_index = length - 1;	/*	last elemenet in the  array			*/

	/* while only one elemenet is left in the searched area				*/
	while (left_index <= right_index)
	{
		/* split it to half												*/
		middle = (left_index + right_index) / 2;
		
		/*	if key greater, ignore left half, search only in right half	*/
		if (SortedArray[middle] < key)
		{
			left_index = middle + 1;
		}
		/*	if key smaller, ignore right half, search only in left half	*/
		else
		{
			right_index = middle;
		}
	}

	/*	if we reach here, then element is the key or was not found		*/
	result = (int *)SortedArray + middle;
			
	return (key == *result ? result : NULL);
}
/******************************************************************************/
int *BinarySearchRec(const int SortedArray[], int key, size_t length)
{
	int left_index = 0; 			/*  first elemenet of the array	*/
	int right_index = length - 1;	/* last elemenet in the array */	
	int middle_index = 0, is_bigger = 0;
	
	const int *start_of_the_arr = NULL;
	size_t new_arr_length = 0;
	
	assert(SortedArray);
	assert(length);
	
	/*	base condition: if one element in the array - check if equals to key */
	if (1 == length)	
	{
		return (key == *SortedArray ? (int *)SortedArray : NULL);
	}
	
	/* the middle element in the array 										*/
	middle_index = (left_index + right_index) / 2;	

	/* check whether the key is bigger than the middle element				*/
	is_bigger = (key > SortedArray[middle_index]);
	
	/* set the boundries of the new search area based on is_bigger result 	*/
	start_of_the_arr = SortedArray + ((middle_index + 1) * is_bigger);
	new_arr_length = is_bigger * (length - (length / 2) ) +
													!is_bigger * (length / 2);
	
	/* recursive call of the function with the new area to be searched 		*/ 
	return (BinarySearchRec(start_of_the_arr, key, new_arr_length));
}
/******************************************************************************/
int MergeSort(int arr_to_sort[], size_t num_of_elements)
{
	int left_index = 0, right_index = num_of_elements - 1;
	
	int *right_side_sorted = NULL, *left_side_sorted = NULL;
	
	size_t left_side_size = 0, right_side_size = 0;

	assert(arr_to_sort);
	assert(num_of_elements);
	
	/*	base condition:	if only one elemenet in the array - return the array */
	if (1 == num_of_elements)
	{
		return (0); /*	array was successfully sorted	*/
	}
	
	/*	left_array = left half of the array, size: num_of_elements/2		*/
	left_side_size = (left_index + right_index) / 2 + 1;
	/*	right_array = right half of the array,
								size: num_of_elements - size of left_array	*/
	right_side_size = num_of_elements - left_side_size;
	
	/*	sort each side of the array: 										*/
	left_side_sorted = MergeSort(arr_to_sort, left_side_size);
	right_side_sorted = MergeSort(arr_to_sort + left_side_size + 1, 
															right_side_size);
	
	/*	send 2 sorted arrays to MergeArrIMP to merge them					*/
	if (!MergeArrIMP(left_side_sorted, right_side_sorted, left_side_size,
															right_side_size))
	{
		return (1);	/* failed to merge the arrays							*/
	}
}
/*----------------------------------------------------------------------------*/
int *MergeArrIMP(int arr1[], int arr2[], size_t arr1_size, size_t arr2_size)
{
	assert(arr1);
	assert(arr2);
	assert(arr1_size);
	assert(arr2_size);
	
	/*	create an array that will be the sorted array that includes both arrays
				lets call it merged_arr , handle allocation errors if any	*/
	int *merged_arr = (int *)malloc(sizeof(int) * (arr1_size + arr2_size));
	if (!merged_arr)
	{
		/*	while both arrays have elements:								*/
		while (arr1_size && arr2_size)
		{
			/*	if arr1[0] > arr2[0]:								*/
			if (*arr > *arr2)
			{
				/*	add arr2[0] to the end of merged_arr	*/
				*merged_arr = *arr2;
				/*	increment arr2 ptr						*/
				++arr2;
				--arr2_size;
			} 
			
			/*	if arr1[0] < arr2[0]: 								*/
			if (*arr1 < *arr2)
			{
				/*	add arr1[0] to merged_arr				*/
				*merged_arr = *arr1;
				/*	increment arr1 ptr						*/
				++arr1;
				--arr1_size;
			}

		}
		
		/*	if either of the arrays still has elemenets, add them to the 
		 *	merged array 													*/
		while (arr1_size)
		{
			*merged_arr = *arr1;
			++arr1;
			--arr1_size;
		}
		
		while (arr2_size)
		{
			*merged_arr = *arr2;
			++arr2;
			--arr2_size;
		}		
	}
	
	return (merged_arr);
}
/******************************************************************************/
void QSort(void *base, size_t nmemb, size_t size, int (*compare)(const void *,
																const void *))
{
	void *left = NULL, *right = NULL, pivot = NULL, partition = NULL;
	
	assert(base);
	assert(nmemb);
	assert(size);
	assert(compare);

	/*	base case: if left side runner meets right side runner				*/
	if (left == right)
	{
		return;
	}

	left = base;
	right = left + nmemb - 1;

	pivot = (left + right) / 2; /* choose pivot as the middle elemenet		*/
	partition = PartitionIMP(left, right, pivot)
	QSort(left, partition - 1);
	QSort(partition + 1, right);
}
/*----------------------------------------------------------------------------*/
void *PartitionIMP(void *left, void *right, void *pivot)
{
	void *LSideRunner = left, *RSideRunner = right;
	
	assert(left);
	assert(right);
	assert(pivot);
	
	/*	while RSideRunner != LSideRunner									*/
	while (LSideRunner != RSideRunner)
	{
		/*	while leftPointer <= pivot && still inside the array range 	*/
		while (cmp_func(LSideRunner, pivot) <= 0 && LSideRunner <= right)
		{
			/*	increment left runner				*/
			++LSideRunner;
		}
		
		/*	while rightPointer > pivot									*/
		while (cmp_func(RSideRunner, pivot) > 0)
		{
			/*	decrement right runner				*/
			--RSideRunner;
		}
		
		/*	if leftPointer != rightPointer								*/
		if (LSideRunner != RSideRunner)
		{
			/*swap leftPointer,rightPointer			*/
			SwapPtrsValues(RSideRunner, LSideRunner, size_of_elem);
		}
	}
		
		/*   swap leftPointer,pivot											*/
		SwapPtrsValues(pivot, LSideRunner, size_of_elem);
		
		/*   return leftPointer												*/
		return (LSideRunner);
}
/*----------------------------------------------------------------------------*/
void SwapPtrsValues(void *ptr1, void *ptr2, size_t size_of_elem)
{
	/*	asserts									*/
	assert(ptr1);
	assert(ptr2);
	assert(size_of_elem);
	
	/*	while size_of_elem:						*/
	while(size_of_elem)
	{
		/*	look at both ptrs as (char *)	*/
		/*	xor swap between each char:		*/
		*(char *)ptr1 ^= *(char *)ptr2;
		*(char *)ptr2 ^= *(char *)ptr1;
		*(char *)ptr1 ^= *(char *)ptr2;	
	}
}
/******************************************************************************/
