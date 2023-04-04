#include "lists.h"

/**
 * insert_node_at_index - Inserts a new node
 * @head: Apointer to the assress of the head of the lists
 *@ idx: the index of the listint
 *@n : int for the new node
 * Return : if the function fails NULL OTHERWISE address of the new node
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *a, *c = *head;
	unsigned int nd;
	a = malloc(sizeof(listint_t));
       if (a == NULL)
       {
       		return (NULL);
       }else{
       		a -> n = n;
		if ( idx == 0 )
		{ a -> next = c;
		  *head = a;
		return (a);
		}else
		{	for (nd = 0; nd < (idx - 1); nd ++)
				if ( c == NULL || c -> next == NULL)
				{
				return (NULL);
				}else{
				c =  c -> next;
				}
		}
        a -> next = c -> next;
	c -> next  = a;
       }

       return (a);


}
