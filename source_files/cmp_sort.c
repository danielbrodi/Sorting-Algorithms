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
		/*
	
	assert and verify that the given array paramater is valid and not null.

	check if the size of the array is bigger than one. if it's not, do nothing.
	
	run through the array and divide it to "sorted" part and "unsorted" part.
	The "sorted" part starts at index 0, promote this index by one.
	Each iteration will swap the smallest item in the "unsorted" part with
	the item that currently located at the "sorted" index.

	size_t sorted_item = 0;    
	size_t unsorted_item = 0;
	size_t smallest_value = arr[sorted_item]; # stores index of smallest item
	
	while (sorted_item <= size - 1):
		unsorted_item = sorted_item + 1;
		
		while (unsorted_item < size):
				if (arr[unsorted_item] < arr[smallest_value]):
					arr[smallest_value] = arr[unsorted_item];
				++unsorted_item;
				
		arr[sorted_item] = arr[smallest_value];
		++sorted_item;
		
			
	*/   
}

/******************************************************************************/

void InsertionSort(int *arr, size_t size)
{

}

/******************************************************************************/
