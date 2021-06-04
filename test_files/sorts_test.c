/*********************************FILE__HEADER*********************************\
* File:				sorts.c						 		  								
* Author:			Daniel Brodsky					  								
* Date:				02-06-2021
* Code Reviewer:							   								
* Version:			1.0					   								
* Description:		Sorts and searches algorithms implementations tests file.		 
\******************************************************************************/

/********************************* Inclusions *********************************/

#include <stddef.h>	/*	size_t						*/
#include <stdio.h>	/*	printf						*/
#include <stdlib.h>	/*	rand, srand					*/
#include <time.h>	/*	time						*/

#include "utils.h"	/*	PRINT_COLOR, COLOR			*/
#include "sorts.h"

/***************************** Macros Definitions *****************************/

/* generates random number from 1 to 100 			*/
#define RANDOM_NUM ((rand() % 100) + 1)	

/**************************** Forward Declarations ****************************/
static void BinarySearchIterTest();
static void PrintHeader();
/******************************************************************************/
/******************************* Main__Function *******************************/

int main()
{
	/*	Intializes a random number generator								*/
	srand(time(0));
	
	/*	Prints a beautiful header which will be on top of the tests results */
	PrintHeader();
	
	/*	Runs tests			*/
	BinarySearchIterTest();
	
	return (0);
}
/******************************************************************************/
void BinarySearchIterTest()
{
	int is_working_iterative = 1;
	int is_working_recursive = 1;
	
	const int sorted_arr[] = { 2, 4, 8, 10, 12};
	
	size_t arr_length = sizeof(sorted_arr) / sizeof(sorted_arr[0]), i = 0;
	
	int key_to_find = 0;
	
	int *iterative_res = NULL;
	int *recursive_res = NULL;
	
	for (i = 0; i < arr_length; ++i)
	{
		key_to_find = sorted_arr[i];
		
		iterative_res = BinarySearchIter(sorted_arr, key_to_find, arr_length);
		recursive_res = BinarySearchRec(sorted_arr, key_to_find, arr_length);
		
		is_working_iterative *= (iterative_res && key_to_find == *iterative_res);
		is_working_recursive *= (recursive_res && key_to_find == *recursive_res);
		
		if (!iterative_res || !recursive_res || key_to_find != *iterative_res || 
												key_to_find != *recursive_res)
		{
			printf(RED "Needs to find: %d\n But found:\n", key_to_find);
			iterative_res ? printf(CYAN "Iterative: %d\n", *iterative_res) : 
															printf("NULL\n");
			recursive_res ? printf(CYAN "Recursive: %d\n", *recursive_res) : 
															printf("NULL\n");
		}
	}
	
	printf(CYAN "Binary Search Iterative Test: " RESET_COLOR);
	
	is_working_iterative ? PRINT_SUCCESS : PRINT_FAILURE;
	
	printf(CYAN "Binary Search Recursive Test: " RESET_COLOR);
	
	is_working_recursive ? PRINT_SUCCESS : PRINT_FAILURE;
}
/******************************************************************************/

/******************************************************************************/
static void PrintHeader()
{
	printf("\n|-----------|\n|" RED  "%2sS" GREEN "o" YELLOW "r" BLUE "t" 
	PURPLE "i" CYAN "n" RED "g" RESET_COLOR "%2s|\n|" GREEN "%4s&" 
	RESET_COLOR "%6s|" YELLOW "\n","", "", "", "");
	
	printf(RESET_COLOR "|" RED "%1sS" GREEN "e" YELLOW "a" BLUE "r" PURPLE "c"
	CYAN "h" RED "i" GREEN "n" YELLOW "g" RESET_COLOR "%1s|\n|-----------|\n\n",
	 "", "");
}
/******************************************************************************/
