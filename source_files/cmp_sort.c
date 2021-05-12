/*********************************FILE__HEADER*********************************\
* File:				cmp_sort.c						 		  								
* Author:			Daniel Brodsky					  								
* Date:				12/05/2021							   								
* Version:			1.0	(Before Review)		
* Code Reviewer:	Danel						   								
* Description:		Implementations of sorting algorithms.		 
\******************************************************************************/

/********************************* Inclusions *********************************/
#include <assert.h>				/*	assert			*/
#include <stddef.h>				/*	size_t, NULL	*/

#include "cmp_sort.h"

/**************************** Forward Declarations ****************************/
/*	swap values of 2 given pointers		*/
void Swap(int *item_x, int *item_y);

/*************************** Functions Pseudo Codes ***************************/
void BubbleSort(int *arr, size_t size)
{
	size_t sorted_items = 0;    
	size_t item_to_sort = 0;
	
	/*	verify that the given array paramater is valid and not null.		*/
	assert(arr);
	/*	do nothing if there are no more than 1 item in the array			*/
	if (size > 1)
	{    
		/*	Loop through the array and compare each item to its next		*/
		while (sorted_items <= size - 1)
		{   
				/*	each loop will compare the items from the beginning		*/
				item_to_sort = 0;
				
				/*	each loop will place the biggest item on the right		*/
				while (item_to_sort < size - sorted_items - 1)
				{   
					/*	compare and swap item with its next if it's bigger	*/
					if (arr[item_to_sort] > arr[item_to_sort + 1])
					{
						Swap(&arr[item_to_sort], &arr[item_to_sort + 1]);
					}
					
					++item_to_sort;    
				}    
			
			++sorted_items; 
		}	
	}
}
/******************************************************************************/

void Swap(int *item_x, int *item_y)
{
    int temp = *item_x;
    *item_x = *item_y;
    *item_y = temp;
}
/******************************************************************************/
