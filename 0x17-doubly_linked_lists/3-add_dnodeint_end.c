#include "lists.h"
/**
 * add_dnodeint_end - Add a node in the tail
 * @head: Pointer to direction of the head
 * @n: The data integer
 * Return: The direction of the tail node
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *nw_mem, *lst_dir;
	nw_mem = malloc(sizeof(dlistint_t));
	
	if (nw_mem == NULL)
		return (NULL);
	
	nw_mem->n = n;
	nw_mem->next = NULL;
	nw_mem->prev = NULL;
	if (*head == NULL)
	{
		*head = nw_mem;
		return (nw_mem);
	}
	lst_dir = *head;
	
	while (lst_dir->next != NULL)
		lst_dir = lst_dir->next;
	lst_dir->next = nw_mem;
	nw_mem->prev = lst_dir;

	return (nw_mem);
}
