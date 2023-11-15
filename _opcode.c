#include "monty.h"

/**
 * stack - execute
 * @head: command line
 * @line: head of list
 *
 * Return: next line number
 */
void stack(stack_t **head, unsigned int line)
{
	(void) line;
	(void) head;

	treck.opcode = "stack";
}

/**
 * queue - execute
 * @head: command line
 * @line: head of list
 *
 * Return: next line number
 */
void queue(stack_t **head, unsigned int line)
{
	(void) line;
	(void) head;

	treck.opcode = "queue";
}

/**
 * add_dnodeint_end - add node at the end
 * @head: node
 * @n: string
 *
 * Return: number of nodes
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *ref;
	stack_t *nnode;

	if (!head)
		return (0);

	nnode = (stack_t *) malloc(sizeof(stack_t));

	if (!nnode)
	{
		close(treck.fd);
		free(treck.buf);
		free_dlistint(*head);
		exit(0);
	}
	nnode->n = n;
	nnode->next = NULL;
	if (!*head)
	{
		nnode->prev = NULL;
		*head = nnode;
		return (*head);
	}
	ref = *head;
	while (ref->next)
		ref = ref->next;
	ref->next = nnode;
	nnode->prev = ref;

	return (nnode);
}