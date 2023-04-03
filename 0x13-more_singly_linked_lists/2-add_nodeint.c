#include "lists.h"

/**
 * add_nodeint -  Adds a new node at the beginning of a listint_t list.
 * @head:  pointer to the address of the head
 * @n:  The int for the new node
 * Return : On failure -NULL else the address of the new element
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *a;
	a =  malloc(sizeof(listint_t));
		if ( a == NULL )
			{
				return (NULL);
			} 
			else
				{
					a -> n = n;
					a -> next = *head;
					*head = a;
				}
	return (a);

			
}
