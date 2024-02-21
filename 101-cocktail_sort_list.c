#include "sort.h"

/**
 * swap_node_ahead - function to swap a node in a doubly-linked list
 * with the node that comes after it.
 * @head : A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @node_swap: A pointer to the node that needs to be
 * swapped with the next node.
 */
void swap_node_ahead(listint_t **head, listint_t **tail, listint_t **node_swap)
{
	listint_t *temp = (*node_swap)->next;

	if ((*node_swap)->prev != NULL)
		(*node_swap)->prev->next = temp;
	else
		*head  = temp;
	temp->prev = (*node_swap)->prev;
	(*node_swap)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *node_swap;
	else
		*tail = *node_swap;
	(*node_swap)->prev = temp;
	temp->next = *node_swap;
	*node_swap = temp;
}

/**
 * swap_node_behind - function to swap a node in a doubly-linked list
 * with the node that comes before it.
 * @head: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @node_swap: A pointer to the node that needs to be
 * swapped with the previous node.
 */
void swap_node_behind(listint_t **head, listint_t **tail,
	listint_t **node_swap)
{
	listint_t *temp = (*node_swap)->prev;

	if ((*node_swap)->next != NULL)
		(*node_swap)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*node_swap)->next;
	(*node_swap)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *node_swap;
	else
		*head = *node_swap;
	(*node_swap)->next = temp;
	temp->prev = *node_swap;
	*node_swap = temp;
}

/**
 * cocktail_sort_list - function implements the Cocktail Shaker Sort algorithm
 * on a doubly-linked list, continuously iterating through forward and
 * backward passes until the list is sorted.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *node_swap;
	bool status = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (status == false)
	{
		status = true;
		for (node_swap = *list; node_swap != tail; node_swap = node_swap->next)
		{
			if (node_swap->n > node_swap->next->n)
			{
				swap_node_ahead(list, &tail, &node_swap);
				print_list((const listint_t *)*list);
				status = false;
			}
		}
		for (node_swap = node_swap->prev; node_swap != *list;
				node_swap = node_swap->prev)
		{
			if (node_swap->n < node_swap->prev->n)
			{
				swap_node_behind(list, &tail, &node_swap);
				print_list((const listint_t *)*list);
				status = false;
			}
		}
	}
}
