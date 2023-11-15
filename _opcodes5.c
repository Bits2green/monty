#include "monty.h"
/**
 * swap - swap the stack to the top
 * @head: head of list
 * @n: line number
 *
 * Return: 0 or error code
 */

void swap(stack_t **head, unsigned int n)
{
	stack_t *extra1, *extra2;

	if (*head == NULL || (*head)->next == NULL)
	{
		close(treck.fd);
		free(treck.buf);
		fprintf(stderr, "L%d: can't swap, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	else
	{
		extra1 = *head;
		extra2 = (*head)->next;
		*head = extra2;
		(*head)->prev = NULL;
		extra1->next = extra2->next;
		extra1->prev = *head;
		(*head)->next = extra1;
	}
}

/**
 * rotl - rotates the stack to the top
 * @head: head of list
 * @n: line number
 *
 * Return: 0 or error code
 */

void rotl(stack_t **head, unsigned int n)
{
	stack_t *extra1, *extra2;

	if (*head == NULL || (*head)->next == NULL)
		nop(head, n);
	else
	{
		extra1 = *head;
		*head = (*head)->next;
		(*head)->prev = NULL;
		extra2 = *head;
		while (extra2->next != NULL)
			extra2 = extra2->next;
		extra2->next = extra1;
		extra1->next = NULL;
		extra1->prev = extra2;
	}
}
