#include "lists.h"
/**
 * add_dnodeint- Insert new node at the beginnig
 * @head: Is the pointer to the direction of the head
 * @n:The data integer
 * Return: The new node
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *nw_mem;
	
	nw_mem = malloc(sizeof(dlistint_t));
	
	if (nw_mem == NULL)
		return (NULL);
	nw_mem->n = n;
	nw_mem->prev = NULL;
	nw_mem->next = *head;

	if (*head != NULL)
		(*head)->prev = nw_mem;
	*head = nw_mem;

	return (nw_mem);
}
