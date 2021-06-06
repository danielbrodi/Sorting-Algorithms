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
	int *left_side_start = NULL, *right_side_start = NULL, *merged_arr = NULL;
	
	size_t left_side_size = 0, right_side_size = 0;

	assert(arr_to_sort);
	assert(num_of_elements);
	
	/*	base condition:	if only one elemenet in the array - return the array */
	if (1 == num_of_elements)
	{
		return (0); /*	array was successfully sorted						*/
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
	
	/*	create an array that will be the sorted array that includes
							 both halves. handle allocation errors if any	*/
	merged_arr = (int *)malloc(sizeof(int) * num_of_elements);
	if (!merged_arr)
	{
		return (1);	/*	allocation for merged array was failed				*/
	}
	
	/*	send 2	halves of the array to MergeArrIMP to merge them into the
	 *	previously created array											*/
	MergeArrIMP(left_side_start, left_side_size, right_side_start, 
												right_side_size, merged_arr);
	
	/* copy merged_arr elemenets to arr_to_sort and free merged_arr			*/					
	memcpy(arr_to_sort, merged_arr, sizeof(int) * num_of_elements);
	
	free(merged_arr);
	merged_arr = NULL;
	
	return (0);
}
/*----------------------------------------------------------------------------*/
void MergeArrIMP(int arr1[], size_t arr1_size, int arr2[], size_t arr2_size, 
															int merged_arr[])
{
	assert(arr1);
	assert(arr1_size);
	assert(arr2);
	assert(arr2_size);
	assert(merged_arr);
			
	/*	while both arrays have elements:								*/
	while (arr1_size && arr2_size)
	{
		/*	if arr1[0] > arr2[0]:								*/
		if (*arr1 > *arr2)
		{
			/*	add arr2[0] to the end of merged_arr	*/
			*merged_arr = *arr2;
			++merged_arr;
			/*	increment arr2 ptr						*/
			++arr2;
			--arr2_size;
		} 
		
		/*	if arr1[0] <= arr2[0]: 								*/
		else
		{
			/*	add arr1[0] to merged_arr				*/
			*merged_arr = *arr1;
			++merged_arr;
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
		++merged_arr;
		
		++arr1;
		--arr1_size;
	}
	
	while (arr2_size)
	{
		*merged_arr = *arr2;
		++merged_arr;
		
		++arr2;
		--arr2_size;
	}		
}
/******************************************************************************/
void QSort(void *base, size_t nmemb, size_t size, int (*compare)(const void *,
																const void *))
{
	void *left = NULL, *right = NULL, *pivot = NULL, *partition = NULL;
	
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
	
	/* choose pivot as the middle elemenet									*/
	pivot = left;
	
	SwapPtrsValues(pivot, left, size);
	
	/*	move pivot to be the leftest elemenet of the array 					*/
	partition = PartitionIMP(left, right, left, size, compare);
	
	if (partition > left)
	{
		QSort(left, ((char *)partition - (char *)left) / size, size, compare);
	}
	if (partition < right)
	{
		QSort((char *)partition + size, (((char *)right - ((char *)partition)) / size), size, compare);
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
		/*	while leftPointer <= pivot && still inside the array range 	*/
		while (cmp_func(LSideRunner, pivot) <= 0 && LSideRunner <= RSideRunner)
		{
			/*	increment left runner				*/
			LSideRunner = (char *)LSideRunner + size_of_elem;
		}
		
		/*	while rightPointer > pivot									*/
		while (cmp_func(RSideRunner, pivot) > 0)
		{
			/*	decrement right runner				*/
			RSideRunner = (char *)RSideRunner - size_of_elem;
		}
		
		/*	if leftPointer != rightPointer								*/
		if (LSideRunner < RSideRunner)
		{
			/*swap leftPointer,rightPointer			*/
			SwapPtrsValues(RSideRunner, LSideRunner, size_of_elem);
		}
	}
		
		/*   swap leftPointer,pivot											*/
		SwapPtrsValues(pivot, (char *)RSideRunner, size_of_elem);
		
		/*   return leftPointer												*/
		return (RSideRunner);
}
/*----------------------------------------------------------------------------*/
void SwapPtrsValues(void *ptr1, void *ptr2, size_t size_of_elem)
{
	char *ptr1_byte = NULL, *ptr2_byte = NULL;
	
	/*	asserts									*/
	assert(ptr1);
	assert(ptr2);
	assert(size_of_elem);
	
	ptr1_byte = ptr1;
	ptr2_byte = ptr2;
	
	if (ptr1_byte != ptr2_byte)
	{
		/*	while size_of_elem:						*/
		while(size_of_elem)
		{
			/*	look at both ptrs as (char *)	*/
			/*	xor swap between each char:		*/
			*ptr1_byte ^= *ptr2_byte;
			*ptr2_byte ^= *ptr1_byte;
			*ptr1_byte ^= *ptr2_byte;
			
			--size_of_elem;
			++ptr1_byte;
			++ptr2_byte;
		}
	}
}
/******************************************************************************/
