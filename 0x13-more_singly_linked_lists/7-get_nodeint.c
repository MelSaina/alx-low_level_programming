#include "lists.h"

/**
 * get_nodeint_at_index- Locates a given node of a listint_t linked list.
 * @head :  A pointer  to the head of the listint_t
 * @index: The index of the node to locate - indices start at 0.
 * Return : if empty 0 otherwise located node's data (n).
 *
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int n;

	for  (n = 0;  n < index; n++)
		if (head == NULL)
		{
			return (NULL);
		}
		else
		{
			head = head->next;
		}
	return (head);
}
