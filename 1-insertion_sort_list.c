#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @head: A pointer to the head of the doubly-linked list.
 * @node1: A pointer to the first node to swap.
 * @node2: The second node to swap.
 */

void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	listint_t *node2_next, *node1_prev;

	node2_next = node2->next;
	(*node1)->next = node2_next;

	if (node2_next != NULL)
		node2_next->prev = *node1;

	node1_prev = (*node1)->prev;

	node2->prev = node1_prev;
	node2->next = *node1;

	if (node1_prev != NULL)
		node1_prev->next = node2;
	else
		*head = node2;

	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insertion, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (current = (*list)->next; current != NULL; current = temp)
	{
		temp = current->next;
		insertion = current->prev;
		while (insertion != NULL && current->n < insertion->n)
		{
			swap_nodes(list, &insertion, current);
			print_list((const listint_t *)*list);
		}
	}
}
