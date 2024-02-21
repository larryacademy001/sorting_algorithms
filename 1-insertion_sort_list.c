#include "sort.h"

/**
 * nodes_swap - Swap two nodes in a listint_t doubly-linked list.
 * @head: A pointer to the head of the doubly-linked list.
 * @first_node: A pointer to the first node to swap.
 * @second_node: The second node to swap.
 */
void nodes_swap(listint_t **head, listint_t **first_node,
	listint_t *second_node)
{
	(*first_node)->next = second_node->next;
	if (second_node->next != NULL)
		second_node->next->prev = *first_node;
	second_node->prev = (*first_node)->prev;
	second_node->next = *first_node;
	if ((*first_node)->prev != NULL)
		(*first_node)->prev->next = second_node;
	else
		*head = second_node;
	(*first_node)->prev = second_node;
	*first_node = second_node->prev;
}

/**
 * prev_nodeion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the insertion sort algorithm
 * @list: a pointer to a pointer to a doubly linked list.
 *
 * Description:  Print the list after each time you swap two elements.
 */
void prev_nodeion_sort_list(listint_t **list)
{
	listint_t *current_node, *prev_node, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current_node = (*list)->next; current_node != NULL; current_node = temp)
	{
		temp = current_node->next;
		prev_node = current_node->prev;
		while (prev_node != NULL && current_node->n < prev_node->n)
		{
			nodes_swap(list, &prev_node, current_node);
			print_list((const listint_t *)*list);
		}
	}
}
