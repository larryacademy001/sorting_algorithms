#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/* Comparison direction macros for bitonic sort */
#define UP 0
#define DOWN 1

/**
 * enum bool - Enumeration of Boolean values.
 * @false: Equals 0.
 * @true: Equals 1.
 */
typedef enum bool
{
	false = 0,
	true
} bool;

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Printing helper functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting algoritms */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

/* other functions */
void swap_numbers(int *first_number, int *second_number);
void nodes_swap(listint_t **head, listint_t **first_node,
	listint_t *second_node);
int lomuto_partition_scheme(int *array, size_t size,
	int left_portion, int right_portion);
void lomuto_sort(int *array, size_t size,
	int left_portion, int right_portion);
void swap_node_ahead(listint_t **head, listint_t **tail,
	listint_t **node_swap);
void swap_node_behind(listint_t **head, listint_t **tail,
	listint_t **node_swap);
void sub_array_merge(int *sub_array, int *temp_buffer, size_t front_index,
	size_t mid_index, size_t back_index);
void recursive_merge_sort(int *sub_array, int *temp_buffer,
	size_t front_index, size_t back_index);
void max_heap_main(int *array, size_t size,
	size_t tree_base, size_t tree_root);
void heap_sort(int *array, size_t size);

#endif /* SORT_H */
