#include "lists.h"
/**
 * pop_listint- deletes the head of the node
 * @head : pointer to the address of the head 
 * Return : if empty 0 else node's data
 */

int pop_listint(listint_t **head)
{
	listint_t *f;
	int r;
		if ( *head  == NULL)
		{
		return (0);
		}else{
			f = *head;
			r = (*head ) -> n;
			*head = ( *head ) -> next;
			free (f);

		}
	return (r);
}

