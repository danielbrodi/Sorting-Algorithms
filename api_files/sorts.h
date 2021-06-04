/*********************************FILE__HEADER*********************************\
* File:				sorts.h						 		  											  								
* Date:				02-06-2021							   												   								
* Description:		Sorts and Searches algorithms API.		 
\******************************************************************************/

#ifndef __SORTS_H__
#define __SORTS_H__

#include <stddef.h>		/*	size_t	*/

/* Recieves an array sorted from least to greatest 	*/
/* Returns NULL if the key is not found 			*/
int *BinarySearchIter(const int SortedArray[], int key, size_t length);

int *BinarySearchRec(const int SortedArray[], int query, size_t length);

/* Returns 0 on success and 1 on failure 			*/
int MergeSort(int arr_to_sort[], size_t num_of_elements);

void QSort(void *base, size_t nmemb, size_t size, int (*compar)(const void *,
																const void *));

#endif					/* __SORTS_H__ */
