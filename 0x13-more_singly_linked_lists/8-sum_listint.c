#include "lists.h"
/**
 * sum_listint  - calculates the su of all the data (n) of a listint_t
 *@head pointer to the head of the listint-t
 *Return : if empty 0 otherwise sum of all the data
 */

int sum_listint(listint_t *head)
{
	int sum = 0;
		while (head)
		{
		sum += head -> n ;
		head  = head -> next;
		}	

	return (sum) ;

}
