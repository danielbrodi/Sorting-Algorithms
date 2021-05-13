/*********************************FILE__HEADER*********************************\
* File:				cmp_sort_test.c						 		  								
* Author:			Daniel Brodsky					  								
* Date:				12/05/2021							   								
* Version:			1.0	(Before Review)					   								
* Description:		Sorting Algorithms implementations testing file.		 
\******************************************************************************/

/********************************* Inclusions *********************************/
#include <stddef.h>	/*	size_t						*/
#include <stdio.h>	/*	printf						*/
#include <stdlib.h>	/*	rand, srand					*/
#include <time.h>	/*	time						*/

#include "utils.h"	/*	PRINT_COLOR, COLOR			*/
#include "cmp_sort.h"

/***************************** Macros Definitions *****************************/
/* generates random number from -99 to 99 			*/
#define RANDOM_NUM ((rand() % 200 - 100))	

/**************************** Forward Declarations ****************************/
static void PrintArray(int arr[], size_t size);
/* 	Fills up an ints array by random ints			*/
static void FillUpArray(int *arr, size_t size);
/*	Copies size values of arr2 items to arr 1 items	*/
static void CopyArray(int *arr1, int *arr2, size_t size);

/******************************************************************************/
/******************************* Main__Function *******************************/

int main()
{	
	int arr1[10] = {0};
	int arr2[10] = {0};
	int arr3[10] = {0};
	
	size_t size = sizeof(arr1)/sizeof(arr1[0]);
	
	/*	Intializes a random number generator		*/
	srand(time(0));
	
	FillUpArray(arr1, size);
	
	CopyArray(arr1, arr2, size);
	CopyArray(arr1, arr3, size);
	
	printf("\nOriginal array: ");
	PrintArray(arr1, size);

	BubbleSort(arr1, size);
	SelectionSort(arr2,size);
	InsertionSort(arr3,size);


	PRINT_CYAN;
	printf("\nBubble Sort:    ");
	PrintArray(arr1, size);
	
	PRINT_GREEN;
	printf("Selection Sort: ");
	PrintArray(arr2, size);

	PRINT_RED;
	printf("Insertion Sort: ");
	PrintArray(arr3, size);

	printf(RESET_COLOR "\n");
	
	return 0;
}
/******************************************************************************/
static void PrintArray(int arr[], size_t size)
{
	size_t i = 0;
	
	for (i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	
	printf("\n");
}
/******************************************************************************/
static void FillUpArray(int *arr, size_t size) 
{
	size_t i = 0;
	
	for(i = 0; i < size; ++i)
	{
		arr[i] = RANDOM_NUM;
	}
}
/******************************************************************************/
static void CopyArray(int *arr1, int *arr2, size_t size)
{
	size_t i = 0;
	
	for(i = 0; i < size; ++i)
	{
		arr2[i] = arr1[i];
	}
}
/******************************************************************************/
