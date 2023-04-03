#include "lists.h"
#include  <stdio.h>

/**
 * listint_len -  Returns  the  no of elements in a linkinked listint_t list
 * @h: pointer to the head  of the listint_t list
 * Return: The number of elements
 */

size_t listint_len(const listint_t *h)
{
	size_t nd =  0;
	while   (h)
		{
		       nd++;
	       		h  =  h-> next;	       
		}
	return (nd);

}
