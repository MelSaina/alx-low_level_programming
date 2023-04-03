#include "lists.h"

/**
 * free_listint - Free a listint_t list
 * @head: pointer to the head
 */

void free_listint(listint_t *head)
{
	listint_t *f;

	while (head)
		{
			f =  head -> next;
			free ( head );
			head = f;
		}

}
