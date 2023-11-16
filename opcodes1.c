#include "monty.h"

/**
 * add - function to pop head
 * @head: head of list
 * @n: line number in 0
 *
 * Return: 0 or error code
 */
void add(stack_t **head, unsigned int n)
{
	stack_t *hd1;

	hd1 = *head;
	if (!hd1 || !hd1->next)
	{
		close(treck.fd);
		free(treck.buf);
		fprintf(stderr, "L%d: can't add, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n += (*head)->n;

	pop(head, n);
}

/**
 * sub - function substraction
 * @head: head of list
 * @n: Line number
 *
 * Return: 0 or error code
 */
void sub(stack_t **head, unsigned int n)
{
	stack_t *hd1;

	hd1 = *head;
	if (!hd1 || !hd1->next)
	{
		close(treck.fd);
		free(treck.buf);
		fprintf(stderr, "L%d: can't sub, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n -= (*head)->n;

	pop(head, n);
}

/**
 * div_func - function to pop head
 * @head: head of list
 * @n: line number in 0
 *
 * Return: 0 or error code
 */
void div_func(stack_t **head, unsigned int n)
{
	stack_t *hd1;

	hd1 = *head;
	if (!hd1 || !hd1->next)
	{
		close(treck.fd);
		free(treck.buf);
		fprintf(stderr, "L%d: can't div, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	if (hd1->n == 0)
	{
		close(treck.fd);
		free(treck.buf);
		free_dlistint(*head);
		fprintf(stderr, "L%d: division by zero\n", n);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n /= (*head)->n;
	pop(head, n);
}


/**
 * mod - function to pop head
 * @head: head of list
 * @n: line number in 0
 *
 * Return: 0 or error code
 */
void mod(stack_t **head, unsigned int n)
{
	stack_t *hd1;

	hd1 = *head;
	if (!hd1 || !hd1->next)
	{
		close(treck.fd);
		free(treck.buf);
		fprintf(stderr, "L%d: can't mod, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	if (hd1->n == 0)
	{
		close(treck.fd);
		free(treck.buf);
		free_dlistint(*head);
		fprintf(stderr, "L%d: division by zero\n", n);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n %= (*head)->n;
	pop(head, n);
}

/**
 * pchar - function to pop head
 * @head: head of list
 * @n: line number in 0
 *
 * Return: 0 or error code
 */
void pchar(stack_t **head, unsigned int n)
{
	stack_t *hd1;

	hd1 = *head;
	if (!hd1)
	{
		close(treck.fd);
		free(treck.buf);
		fprintf(stderr, "L%d: can't pchar, stack empty\n", n);
		exit(EXIT_FAILURE);
	}
	if (hd1->n <= 64 || hd1->n >= 123)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", n);
		close(treck.fd);
		free(treck.buf);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (char)hd1->n);
}
