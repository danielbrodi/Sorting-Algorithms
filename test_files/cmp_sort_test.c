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
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    size_t n = sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
