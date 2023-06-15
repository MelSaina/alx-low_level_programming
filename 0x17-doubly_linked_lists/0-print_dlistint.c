#include "lists.h"
/**
 * print_dlistint - Prints  the nodes
 * @h:pointer to node structure
 * Return: the amount of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	int nd_count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		nd_count++;
	}
	return (nd_count);
}
