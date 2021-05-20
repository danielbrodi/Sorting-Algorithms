/*********************************FILE__HEADER*********************************\
* File:				cmp_sort.h						 		  								
* Author:			Daniel Brodsky					  								
* Date:				12/05/2021							   												   								
* Description:		Sorting Algorithms implementations API.		 
\******************************************************************************/

#ifndef __CMP__SORT_H__
#define __CMP__SORT_H__

#include <stddef.h>		/*	size_t	*/

void BubbleSort(int *arr, size_t size);

void SelectionSort(int *arr, size_t size);

void InsertionSort(int *arr, size_t size);

#endif	/* __CMP__SORT_H__	*/
