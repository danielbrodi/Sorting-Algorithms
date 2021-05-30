/*********************************FILE__HEADER*********************************\
* File:				radix.h				 		  												  								
* Date:				22/05/2021							   								
* Version:			1.0						   								
* Description:		Radix sort algorithm API.
\******************************************************************************/

#ifndef __RADIX_H__
#define __RADIX_H__

#include <stddef.h>		/*	size_t								*/

/* a function to extract a sub-element 							*/
typedef size_t (*ConvertFunc)(void *element);


/* returns non-zero if fail to allocate memory 					*/
/* space complexity of size O(n) 								*/
int RadixSort(void *dest, void *src, size_t num_of_elements, size_t element_size,
					ConvertFunc DataToKey, size_t msb, size_t num_of_digits);



#endif	/*	__RADIX_H__	*/ 
