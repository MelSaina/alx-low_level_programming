#include "lists.h"
/**
 * insert_dnodeint_at_index - Insert a node in the postion
 * @h: Pointer to direction of the head
 * @n: The data integer
 * @idx: Position at the insert the new node
 * Return: The direction of the new node
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *nw_mem, *rs_mem = *h;
	/* unsigned int counter = 0 */

	if (idx == 0)
		return (add_dnodeint(h, n));

	for (; idx != 1; idx--)
	{
		if (rs_mem == NULL)
			return (NULL);
		rs_mem = rs_mem->next;
	}

	if (rs_mem->next == NULL)
		return (add_dnodeint_end(h, n));

	nw_mem = malloc(sizeof(dlistint_t));

	if (nw_mem == NULL)
		return (NULL);

	nw_mem->n = n;
	nw_mem->next = rs_mem->next;
	nw_mem->prev = rs_mem;
	rs_mem->next->prev = nw_mem;
	rs_mem->next = nw_mem;

	return (nw_mem);
}
