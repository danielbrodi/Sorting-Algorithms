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
	const int sorted_arr[] = { 2, 4, 8, 10, 12 };
	
	size_t arr_length = sizeof(sorted_arr) / sizeof(sorted_arr[0]);
	
	int key_to_find = 8;
	
	int  *result = BinarySearchIter(sorted_arr, key_to_find, arr_length);
	
	printf(CYAN "Binary Search Iterative Test: " RESET_COLOR);
	
	(result && key_to_find == *result) ? PRINT_SUCCESS : PRINT_FAILURE;
}
/******************************************************************************/

/******************************************************************************/
static void PrintHeader()
{
	printf("\n|-----------|\n|" RED  "%2sS" GREEN "o" YELLOW "r" BLUE "t" PURPLE "i"
	CYAN "n" RED "g" RESET_COLOR "%2s|\n|" GREEN "%4s&"  RESET_COLOR "%6s|"
	YELLOW "\n","", "", "", "");
	
	printf(RESET_COLOR "|" RED "%1sS" GREEN "e" YELLOW "a" BLUE "r" PURPLE "c"
	CYAN "h" RED "i" GREEN "n" YELLOW "g" RESET_COLOR "%1s|\n|-----------|\n\n",
	 "", "");
}
/******************************************************************************/
