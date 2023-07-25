#include "sort.h"


/**
 * swap_behind - Swap a node in a listint_t doubly-linked
 * list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @swapper: A pointer to the current swapping node of the cocktail swapper
 */
void swap_behind(listint_t **list, listint_t **tail, listint_t **swapper)
{
	listint_t *tmp = (*swapper)->prev;

	if ((*swapper)->next != NULL)
		(*swapper)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*swapper)->next;
	(*swapper)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *swapper;
	else
		*list = *swapper;
	(*swapper)->next = tmp;
	tmp->prev = *swapper;
	*swapper = tmp;
}


/**
 * swap_ahead - Swap a node in a listint_t doubly-linked list
 * list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @swapper: A pointer to the current swapping node of the cocktail swapper.
 */
void swap_ahead(listint_t **list, listint_t **tail, listint_t **swapper)
{
	listint_t *tmp = (*swapper)->next;

	if ((*swapper)->prev != NULL)
		(*swapper)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*swapper)->prev;
	(*swapper)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *swapper;
	else
		*tail = *swapper;
	(*swapper)->prev = tmp;
	tmp->next = *swapper;
	*swapper = tmp;
}


/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail swapper algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *swapper;
	bool shaken = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken == false)
	{
		shaken = true;
		for (swapper = *list; swapper != tail; swapper = swapper->next)
		{
			if (swapper->n > swapper->next->n)
			{
				swap_ahead(list, &tail, &swapper);
				print_list((const listint_t *)*list);
				shaken = false;
			}
		}
		for (swapper = swapper->prev; swapper != *list;
				swapper = swapper->prev)
		{
			if (swapper->n < swapper->prev->n)
			{
				swap_behind(list, &tail, &swapper);
				print_list((const listint_t *)*list);
				shaken = false;
			}
		}
	}
}

