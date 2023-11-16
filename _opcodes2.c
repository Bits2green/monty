#include "monty.h"


/**
 * push - function to add at the head
 * @head: head of list
 * @n: line num
 *
 * Return: 0 or error code
 */

void push(stack_t **head, unsigned int n)
{
	int num;
	unsigned int ensign = 1, i;

	if (treck.num_string)
	{
		for (i = 0; treck.num_string[i] != '\0'; i++)
		{
			if (treck.num_string[i] >= 48 &&
			    treck.num_string[i] <= 57)
				ensign = 0;
			else
				ensign = 1;
		}
		if (ensign == 0)
			num = atoi(treck.num_string);
		else
		{
			close(treck.fd);
			free(treck.buf);
			free_dlistint(*head);
			fprintf(stderr, "L%d: usage: push integer\n", n);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		close(treck.fd);
		free(treck.buf);
		free_dlistint(*head);
		fprintf(stderr, "L%d: usage: push integer\n", n);
		exit(EXIT_FAILURE);
	}

	if (strcmp(treck.opcode, "stack") == 0)
		add_dnodeint(head, num);
	else
		add_dnodeint_end(head, num);
}

/**
 * pall - function to print all
 * @head: head of list
 * @n: line num in 0
 *
 * Return: 0 or error code
 */

void pall(stack_t **head, unsigned int n)
{
	stack_t *h1;

	h1 = *head;
	(void) n;
	print_dlistint(h1);
}

/**
 * nop - function to do nothing
 * @head: head of list
 * @n: line num in 0
 *
 * Return: 0 or error code
 */

void nop(stack_t **head, unsigned int n)
{
	(void) n;
	(void) head;
}

/**
 * pint - function to print head
 * @head: head of list
 * @n: line num in 0
 *
 * Return: 0 or error code
 */
void pint(stack_t **head, unsigned int n)
{
	stack_t *h1;

	h1 = *head;
	if (!h1)
	{
		close(treck.fd);
		free(treck.buf);
		fprintf(stderr, "L%d: can't pint, stack empty\n", n);
		exit(EXIT_FAILURE);
	}
	print_head(h1);
}


/**
 * pop - function to pop head
 * @head: head of list
 * @n: line num in 0
 *
 * Return: 0 or error code
 */
void pop(stack_t **head, unsigned int n)
{
	stack_t *h1;

	h1 = *head;
	if (!h1)
	{
		close(treck.fd);
		free(treck.buf);
		fprintf(stderr, "L%d: can't pop an empty stack\n", n);
		exit(EXIT_FAILURE);
	}
	*head = (*head)->next;
	free(h1);
	if (*head)
		(*head)->prev = NULL;
}
