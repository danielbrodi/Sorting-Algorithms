/*********************************FILE__HEADER*********************************\
* File:				cmp_sort_test.c						 		  								
* Author:			Daniel Brodsky					  								
* Date:				12/05/2021							   								
* Version:			1.0	(Before Review)					   								
* Description:		Sorting Algorithms implementations testing file.		 
\******************************************************************************/

#include <stddef.h>				/*	size_t, NULL	*/
#include <stdio.h>

#include "cmp_sort.h"

/* Function to print an array */
void printArray(int arr[], size_t size)
{
	int i;
	for (i=0; i < (int)size; i++)
	printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr1[] = {64, 34, 25, 12, 22, 11, 25, 90, 0, -2};
	int arr2[] = {64, 34, 25, 12, 22, 11, 25, 90, 0, -2};
/*	int arr3[] = {64, 34, 25, 12, 22, 11, 90};*/

	size_t n = sizeof(arr1)/sizeof(arr1[0]);

	printf("Original array: ");
	printArray(arr1, n);

	BubbleSort(arr1, n);
	SelectionSort(arr2,n);
/*	InsertionSort(arr3,n);*/


	printf("Bubble Sort:    ");
	printArray(arr1, n);

	printf("Selection Sort: ");
	printArray(arr2, n);

/*	printf("Insertion Sort:");*/
/*	printArray(arr3, n);*/

	return 0;
}
