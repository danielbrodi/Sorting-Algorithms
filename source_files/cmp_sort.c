/*********************************FILE__HEADER*********************************\
* File:				cmp_sort.c						 		  								
* Author:			Daniel Brodsky					  								
* Date:				12/05/2021							   								
* Version:			1.0	(Before Review)		
* Code Reviewer:	Danel						   								
* Description:		Implementations of sorting algorithms.		 
\******************************************************************************/


/*************************** Functions Pseudo Codes ***************************/

void BubbleSort(int *arr, size_t size)
{
	/*
	
	assert and verify that the given array paramater is valid and not null.

	check if the size of the array is bigger than one. if it's not, do nothing.

	size_t sorted_items;    
	size_t item_to_sort;    

	we want to loop through the array and go on each item and compare it each
	to a different item until it fines an item with a bigger value.

	sorted_items = 0;    

	item_to_sort = 0; #item_to_sort will always be compared to the next item

	while (sorted_items <= size - 1): 
	(which means till it reaches the end of the array and finished sorting it)
	{     
		item_to_sort = 0;    
		while (item_to_sort < size - sorted_items - 1):
		{     
			loop through all the items and compare each to its next.
			if (item_to_sort > item_to_sort + 1):
					Swap them.
			
			++item_to_sort;    
		}    
	}	
	++sorted_items; 
	
	*/   
}
/******************************************************************************/

void SelectionSort(int *arr, size_t size)
{

}

/******************************************************************************/

void InsertionSort(int *arr, size_t size)
{

}

/******************************************************************************/
