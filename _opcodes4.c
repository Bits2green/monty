#include "monty.h"

/**
 * mul - function to multiply
 * @head: head of list
 * @n: line number
 *
 * Return: 0 or error code
 */
void mul(stack_t **head, unsigned int n)
{
	stack_t *h1;

	h1 = *head;
	if (!h1 || !h1->next)
	{
		close(treck.fd);
		free(treck.buf);
		fprintf(stderr, "L%d: cannot mul, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n *= (*head)->n;

	pop(head, n);
}

/**
 * pstr - function to print string
 * @head: head of list
 * @n: line number
 *
 * Return: 0 or error code
 */
void pstr(stack_t **head, unsigned int n)
{
	stack_t *h1;

	h1 = *head;
	(void) n;
	while (h1 != NULL)
	{
		if (h1->n >= 64 && h1->n <= 123)
			printf("%c", (char)h1->n);
		else
			break;
		h1 = h1->next;
	}
	printf("\n");
}

/**
 * rotr - function to print all
 * @head: head of list
 * @n: line number in 0
 *
 * Return: 0 or error code
 */

void rotr(stack_t **head, unsigned int n)
{
	stack_t *stop_gap;
	stack_t *last;



	if (*head == NULL || (*head)->next == NULL)
		nop(head, n);
	else
	{
		stop_gap = NULL;
		last = *head;
		while (last != NULL)
		{
			stop_gap = last;
			last = last->next;
		}
		stop_gap->prev->next = NULL;
		stop_gap->prev = NULL;
		stop_gap->next = *head;
		*head = stop_gap;
	}
}