/*********************************FILE__HEADER*********************************\
* File:				sorts.c
* Author:			Daniel Brodsky				 		  												  								
* Date:				02-06-2021
* Code Reviewer:	Eran
* Pseudo Reviewer: 	Ariel/Eran				   								
* Version:			1.5   								
* Description:		Sorts and searches algorithms implementations. 
\******************************************************************************/

/********************************* Inclusions *********************************/

#include <assert.h>		/*	assert			*/
#include <stddef.h>		/*	size_t, NULL	*/
#include <stdlib.h>		/*	malloc, free	*/
#include <string.h>		/*	memcpy			*/

#include "sorts.h"

/**************************** Forward Declarations ****************************/
static void MergeSortIMP(int arr_to_sort[], size_t num_of_elements,
															int merged_arr[]);

static void MergeArrIMP(int arr1[], size_t arr1_size, int arr2[], 
											size_t arr2_size, int merged_arr[]);

void *PartitionIMP(void *left, void *right, void *pivot, size_t size_of_elem, 
									int (*compare)(const void *, const void *));

static void SwapPtrsValues(void *ptr1, void *ptr2, size_t size_of_elem);
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
	while (left_index < right_index)
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

	/*	if we reach here, left_index equals right_index  which means
	 *	there is only one elemenet that is left. Update the pointer
	 *	to point at it, and check whether it equals the key or not		*/
	result = (int *)SortedArray + right_index;
			
	return (key == *result ? result : NULL);
}
/******************************************************************************/
int *BinarySearchRec(const int SortedArray[], int key, size_t length)
{
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
	middle_index = (length) / 2;	

	/* check whether the key is bigger than the middle element				*/
	is_bigger = (key >= SortedArray[middle_index]);
	
	/* set the boundries of the new search area based on is_bigger result 	*/
	start_of_the_arr = SortedArray + (middle_index) * is_bigger;
	new_arr_length = is_bigger * (length - length/2) + !is_bigger * (length/2);
	
	/* recursive call of the function with the new area to be searched 		*/ 
	return (BinarySearchRec(start_of_the_arr, key, new_arr_length));
}
/******************************************************************************/
int MergeSort(int arr_to_sort[], size_t num_of_elements)
{
	int *merged_arr = NULL;
	
	assert(arr_to_sort);
	assert(num_of_elements);
	
	/*	create an array that will be the sorted array.						*/
	/*	handle allocation errors if any.									*/
	merged_arr = (int *)malloc(sizeof(int) * num_of_elements);
	if (!merged_arr)
	{
		return (1);	/*	allocation for merged array was failed				*/
	}
	
	MergeSortIMP(arr_to_sort, num_of_elements, merged_arr);
	
	free(merged_arr);
	merged_arr = NULL;
	
	return (0);
}
/*----------------------------------------------------------------------------*/
static void MergeSortIMP(int arr_to_sort[], size_t num_of_elements,
															int merged_arr[])
{	
	int *left_side_start = NULL, *right_side_start = NULL;
	
	size_t left_side_size = 0, right_side_size = 0;

	assert(arr_to_sort);
	assert(num_of_elements);
	
	/*	base condition:	if only one elemenet in the array - return the array */
	if (1 == num_of_elements)
	{
		return; /*	array was successfully sorted							*/
	}
	
	/*	left half of the array												*/
	left_side_start = arr_to_sort;
	left_side_size = num_of_elements / 2;
	/*	right half of the array												*/
	right_side_start =	left_side_start + left_side_size;
	right_side_size = num_of_elements - left_side_size;
	
	/*	sort each side of the array: 										*/
	MergeSort(left_side_start, left_side_size);
	MergeSort(right_side_start, right_side_size);
	
	/*	send 2	halves of the array to MergeArrIMP to merge them into the
	 *	previously created array											*/
	MergeArrIMP(left_side_start, left_side_size, right_side_start, 
												right_side_size, merged_arr);
												
	/* 	copy merged_arr elemenets to arr_to_sort and free merged_arr		*/					
	memcpy(arr_to_sort, merged_arr, sizeof(int) * num_of_elements);
}
/*----------------------------------------------------------------------------*/
void MergeArrIMP(int arr1[], size_t arr1_size, int arr2[], size_t arr2_size, 
															int merged_arr[])
{
	/* create runners for each array to not run on the parameters		*/
	int *arr1_runner = arr1, *arr2_runner = arr2, *merged_runner = merged_arr;
	
	/*	create pointers which indicate on the end of each array 		*/ 
	int *arr1_end = arr1 + arr1_size, *arr2_end = arr2 + arr2_size;
	
	assert(arr1);
	assert(arr1_size);
	assert(arr2);
	assert(arr2_size);
	assert(merged_arr);
	
	/*	while both arrays have elements:								*/
	while (arr1_runner < arr1_end && arr2_runner < arr2_end)
	{
		/*	if arr1[0] > arr2[0]:								*/
		if (*arr1_runner > *arr2_runner)
		{
			/*	add arr2[0] to the end of merged_arr	*/
			*merged_runner = *arr2_runner;
			++merged_runner;
			/*	increment arr2 ptr						*/
			++arr2_runner;
		} 
		
		/*	if arr1[0] <= arr2[0]: 								*/
		else
		{
			/*	add arr1[0] to merged_arr				*/
			*merged_runner = *arr1_runner;
			++merged_runner;
			/*	increment arr1 ptr						*/
			++arr1_runner;
		}

	}
	
	/*	if either of the arrays still has elemenets, add them to the 
	 *	merged array 													*/
	/*	call for 2 memcpys, and the compiler will discard one (or both)
	 *	of them because of optimisation if no elements are left			*/
	memcpy(merged_runner, arr1_runner, sizeof(int) * (arr1_end - arr1_runner));
	memcpy(merged_runner, arr2_runner, sizeof(int) * (arr2_end - arr2_runner));
}
/******************************************************************************/
void QSort(void *base, size_t nmemb, size_t size, int (*compare)(const void *,
																const void *))
{
	void *left = NULL, *right = NULL, *partition = NULL;
	
	void *left_side_start = NULL, *right_side_start = NULL;
	
	size_t left_side_nmemb = 0, right_side_nmemb = 0;
	
	assert(base);
	assert(nmemb);
	assert(size);
	assert(compare);

	left = base;
	right = (char *)left + (nmemb) * size - size;
	
	/*	base case: if left side runner meets right side runner				*/
	if (1 == nmemb)
	{
		return;
	}
	
	/*	set the leftest elemenet as the pivot								*/
	partition = PartitionIMP(left, right, left, size, compare);
	
	/*	set boundries for the new area to be searched:
	 *	left and right sides of the pivot.									*/
	left_side_start = left;
	left_side_nmemb =  ((char *)partition - (char *)left) / size;
	
	right_side_start = (char *)partition + size;
	right_side_nmemb = ((char *)right - (char *)partition) / size;
	
	/*	check if returned partition's left side is still in the array		*/
	if (partition > left)
	{
		QSort(left_side_start, left_side_nmemb, size, compare);
	}
	
	/*	check if returned partition's right side is still in the array		*/
	if (partition < right)
	{
		QSort(right_side_start, right_side_nmemb, size, compare);
	}
}
/*----------------------------------------------------------------------------*/
void *PartitionIMP(void *left, void *right, void *pivot, size_t size_of_elem, 
								int (*cmp_func )(const void *, const void *))
{
	void *LSideRunner = left, *RSideRunner = right;
	
	assert(left);
	assert(right);
	assert(pivot);
	
	/*	while RSideRunner != LSideRunner									*/
	while (LSideRunner < RSideRunner)
	{
		/*	while LeftSidePointer <= pivot && still inside the array range 	*/
		while (cmp_func(LSideRunner, pivot) <= 0 && LSideRunner <= RSideRunner)
		{
			/*	increment left runner				*/
			LSideRunner = (char *)LSideRunner + size_of_elem;
		}
		
		/*	while RightSidePointer > pivot									*/
		while (cmp_func(RSideRunner, pivot) > 0)
		{
			/*	decrement right runner				*/
			RSideRunner = (char *)RSideRunner - size_of_elem;
		}
		
		/*	if LeftSidePointer is not equal RightSidePointe					*/
		if (LSideRunner < RSideRunner)
		{
			/*swap LeftSidePointer,RightSidePointer	*/
			SwapPtrsValues(RSideRunner, LSideRunner, size_of_elem);
		}
	}
		
		/*   swap RightSidePointer,pivot									*/
		SwapPtrsValues(pivot, (char *)RSideRunner, size_of_elem);
		
		/*   return RightSidePointer										*/
		return (RSideRunner);
}
/*----------------------------------------------------------------------------*/
void SwapPtrsValues(void *ptr1, void *ptr2, size_t size_of_elem)
{
	char *ptr1_byte = NULL, *ptr2_byte = NULL, *end_byte = NULL;
	
	/*	asserts									*/
	assert(ptr1);
	assert(ptr2);
	assert(size_of_elem);
	
	ptr1_byte = ptr1;
	ptr2_byte = ptr2;
	end_byte = ptr1_byte + size_of_elem;
	
	if (ptr1_byte != ptr2_byte)
	{
		/*	while ptr1 didn't reach the end 	*/
		while(ptr1_byte < end_byte)
		{
			/*	look at both ptrs as (char *)	*/
			/*	xor swap between each char:		*/
			*ptr1_byte ^= *ptr2_byte;
			*ptr2_byte ^= *ptr1_byte;
			*ptr1_byte ^= *ptr2_byte;
			
			++ptr1_byte;
			++ptr2_byte;
		}
	}
}
/******************************************************************************/
