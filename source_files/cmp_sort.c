/*********************************FILE__HEADER*********************************\
* File:				cmp_sort.c						 		  								
* Author:			Daniel Brodsky					  								
* Date:				12/05/2021							   								
* Version:			1.0	(After Review)		
* Code Reviewer:	Danel						   								
* Description:		Implementations of sorting algorithms.		 
\******************************************************************************/

/********************************* Inclusions *********************************/
#include <assert.h>				/*	assert			*/
#include <stddef.h>				/*	size_t			*/

#include "cmp_sort.h"

/**************************** Forward Declarations ****************************/
/*	swap values of 2 given int pointers		*/
static void SwapIntsIMP(int *item_x, int *item_y);

/************************* Functions  Implementations *************************/
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
		while (sorted_items < size)
		{   
				/*	each loop will compare the items from the beginning		*/
				item_to_sort = 0;
				
				/*	each loop will place the biggest item on the right		*/
				while (item_to_sort < size - sorted_items - 1)
				{  
					/*	compare and swap item with its next if it's bigger	*/
					if (arr[item_to_sort] > arr[item_to_sort + 1])
					{
						SwapIntsIMP(&arr[item_to_sort], &arr[item_to_sort + 1]);
					}
					
					++item_to_sort;    
				}    
			
			++sorted_items; 
		}	
	}
}
/******************************************************************************/
void SelectionSort(int *arr, size_t size)
{
	size_t sorted_item = 0;    
	size_t curr_item = 0;
	size_t smallest_value_index = sorted_item; 
	
	/*	verify that the given array paramater is valid and not null.		*/
	assert(arr);
	/*	do nothing if there are no more than 1 item in the array			*/
	if (size > 1)
	{    
	
		/*	divide the array to "sorted" and "unsorted" parts				*/		
		while (sorted_item < size)
		{
			/*	the unsorted part of the array starts after the sorted		*/
			curr_item = sorted_item + 1;
			
			/* before each iteration set the smallest item as the first		*/
			smallest_value_index = sorted_item;
			
			while (curr_item < size)
			{
				/*	set the smallest item as the current one if its smaller	*/
				if (arr[curr_item] < arr[smallest_value_index])
				{
					smallest_value_index = curr_item;
				}
					
				++curr_item;
			}
			
			SwapIntsIMP(&arr[sorted_item], &arr[smallest_value_index]);
			++sorted_item;
		}		
	}
}
/******************************************************************************/
void InsertionSort(int *arr, size_t size)
{
	/*	split the array to sorted and unsorted parts. sorted items will
		be on the left side													*/
	size_t sorted_items = 0;    
	size_t item_to_sort = 0;
	
	/*	verify that the given array paramater  is valid and not null.		*/
	assert(arr);
	/*	do nothing if there are no more than 1 item in the array			*/
	if (size > 1)
	{    
	
		/*	iterate through the array from the first unsorted item
			until reaching the biggest item in the array because it gets
			sorted automatically while the smaller get sorted				*/
		while (sorted_items < size - 1)
		{
			item_to_sort = sorted_items + 1;

			/* compare an item to each of the items on its left				*/
			/* shift them to the right if the item fits in between them		*/
			while (item_to_sort > 0 && arr[item_to_sort - 1] > arr[item_to_sort])
			{
				/* swap items' places if the next of an item is smaller		*/
				SwapIntsIMP(&arr[item_to_sort - 1], &arr[item_to_sort]);
				--item_to_sort;
			}
			
			++sorted_items;
		}
	}
}
/******************************************************************************/
static void SwapIntsIMP(int *item_x, int *item_y)
{
    int temp = (assert(item_x), *item_x);
    
	assert(item_y);
	
    *item_x = *item_y;
    *item_y = temp;
}
/******************************************************************************/
