#include "lists.h"

/**
 * delete_nodeint_at_index -Deletes a node at a given index of listint_t
 * @head:  pointer to the address of the head 
 * @index : index of the node to be deleted  
 * Return on success 1 on failure - -1
 *
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{ 
	 listint_t *f , *c =  *head ; 
	 unsigned int nd;
	 	if ( c== NULL)
		{
		return ( -1);
		}
		else
		{
			if ( index == 0 )
			{
			*head = (*head) -> next;
			free(c);
			return (1);
			}
			else
			{
				for (nd = 0; nd < (index -1); nd++  )
				{
					if ( c -> next == NULL)
					{
				  		return (-1);	
					}
					else
					{
					c = c-> next;
					}
				}
			f = c -> next;
			c -> next = f -> next;
			free(f);
			return (1);

			}


		}

}
