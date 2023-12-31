#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include "sort.h"
#include <stdlib.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer  stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);

void print_sort(int array[], size_t size, int init);

void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);

void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

void swap(int *a, int *b);
void heapify(int *array, int end, int start, size_t size);
void radix_sort(int *array, size_t size);
void count_sort_LSD(int *array, size_t size, size_t lsd);
void quick_sort_hoare(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void bitonic_recursion(int *array, int l, int r, int direction, size_t size);
void bitonic_merge(int *array, int l, int r, int direction);
void quick_recursion(int *array, int left, int right, size_t size);
int partition(int *array, int left, int right, size_t size);

#endif
