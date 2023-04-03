#include "lists.h"

/**
 * add_nodeint_end-Adds a new node at the end of a listint_t list
 * @h: A pointer to the address of the head of the listint_t list
 * @i: the integer for the new node
 * Return On failure Null else the address of the element
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *a, *l;
	a = malloc(sizeof (listint_t));
		if (a ==NULL)
		{
			return (NULL);
		}else {
	 		a -> n = n;
			a ->next = NULL;
				
				if (*head == NULL)
					*head = a;
				else
					{
					l = *head;
					while  ( l -> next != NULL)
					  l= l -> next;
					l -> next  = a;	
					}

			}
	return (*head);
}
