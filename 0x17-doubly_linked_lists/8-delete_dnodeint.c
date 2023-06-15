#include "lists.h"
/**
 * delete_dnodeint_at_index - Delete node at nth
 * @head: Pointer to direction of the head
 * @index: The position in de ll
 * Return: 1 if it succeeded or -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *p, *rs_mem = *head;
	unsigned int count = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = rs_mem->next;
		if (rs_mem->next == NULL)
			return (-1);
		rs_mem->next->prev = NULL;
		free(rs_mem);
		return (1);
	}

	while (count < index)
	{
		if (rs_mem->next == NULL)
			return (-1);
		rs_mem = rs_mem->next;
		count++;
	}
	rs_mem->prev->next = rs_mem->next;
	if (rs_mem->next)
		rs_mem->next->prev = rs_mem->prev;
	if (rs_mem->next == NULL)
	{
		p = rs_mem->prev;
		p->next = NULL;
		free(rs_mem);
		return (1);
	}
	free(rs_mem);
	return (1);
}
