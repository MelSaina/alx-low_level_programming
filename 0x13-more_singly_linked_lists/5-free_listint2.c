#include "lists.h"

/**
 *free_listint2 -  will  frees a listint_t list.
 *@head : A pointer to the address of the head.
 *Setting the head to NULL.
 */

void free_listint2(listint_t **head)
{
	listint_t *f;
		if (head  == NULL)
		{
		return;
		}
		else
		{
			while (*head)
			{
			f = (*head)->next;
			free(*head);
			*head = f;
			}
		head =  NULL;
		}
}
