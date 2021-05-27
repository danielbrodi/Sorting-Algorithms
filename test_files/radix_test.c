/*********************************FILE__HEADER*********************************\
* File:				radix_test.c
* Author:			Daniel Brodsky				 		  												  								
* Date:				23/05/2021				   								
* Version:			1.2 								
* Description:		Radix sort algorithm implementation tests file. 
\******************************************************************************/

/********************************* Inclusions *********************************/

#include <stddef.h>	/*	size_t						*/
#include <stdio.h>	/*	printf						*/
#include <stdlib.h>	/*	rand, srand					*/
#include <time.h>	/*	time						*/

#include "utils.h"	/*	PRINT_COLOR, COLOR			*/
#include "radix.h"

/***************************** Macros Definitions *****************************/

/* generates random number from 1 to 100 			*/
#define RANDOM_NUM ((rand() % 100) + 1)	

/**************************** Structs  Definitions ****************************/

typedef struct student
{
	char *name;
	size_t id;
	size_t grade;
}element_ty;

/**************************** Forward Declarations ****************************/

/* 	Fills up an ints array by random ints			*/
static void FillUpArray(element_ty *arr, size_t size);

static void PrintArray(element_ty arr[], size_t size, int is_sorted);

size_t DataToKey(void *element);
/******************************************************************************/
/******************************* Main__Function *******************************/

int main()
{	
	element_ty students[5] = {0};
	element_ty sorted_students[5] = {0};
	
	size_t msb = 7;
	size_t num_of_digits = 2;
	
	size_t size = sizeof(students)/sizeof(element_ty);
	
	/*	Intializes a random number generator		*/
	srand(time(0));
	
	FillUpArray(students, size);
	
	PrintArray(students, size, 0);
	
	if (RadixSort(sorted_students, students, size,
		 					sizeof(element_ty), DataToKey, msb, num_of_digits))
	{
		printf(RED "ERROR WITH RadixSort" RESET_COLOR);
		return (1);
	}
	
	PrintArray(sorted_students, size, 1);

	return (0);
}
/******************************************************************************/
static void PrintArray(element_ty arr[], size_t size, int is_sorted)
{
	size_t i = 0;
		
	is_sorted ? printf(GREEN "Radix sorted students by grade:\n\n" RESET_COLOR): 
						printf(GREEN "\nUnsorted students:\n\n" RESET_COLOR);
	for (i = 0; i < size; ++i)
	{
		printf(CYAN "Order: " RESET_COLOR "%ld\n\
				"PURPLE "Name: " RESET_COLOR "%s\n\
				"BLUE "ID: " RESET_COLOR  "%ld\n\
				"YELLOW "Grade: " RESET_COLOR  "%ld\n\
				\n", i, arr[i].name, arr[i].id, arr[i].grade);
	}
	
	printf("\n");
}
/******************************************************************************/
static void FillUpArray(element_ty *arr, size_t size) 
{
	size_t i = 0;
	char *names[5] = {"Peter Parker", "Uncle Ben", "Mary Jane", "Aunt May",
																"Harry Osborn"};
	for (i = 0; i < size; ++i)
	{
		arr[i].name = names[i];
		arr[i].id = RANDOM_NUM;
		arr[i].grade = RANDOM_NUM;
	}
}
/******************************************************************************/
size_t DataToKey(void *element)
{
	if (element)
	{
		return (((element_ty *)element)->grade);
	}
	
	printf(RED "ERROR - DataToKey" RESET_COLOR);
	return(-1);
}
/******************************************************************************/
