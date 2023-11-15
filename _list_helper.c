#include "monty.h"

/**
 * print_dlistint - print all nodes
 * @h: node
 *
 * Return: number of nodes
 */
size_t print_dlistint(const stack_t *h)
{
	int marker;

	if (!h)
		return (0);
	for (marker = 0; h; marker++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	return (marker);
}

/**
 * print_head - print Top node
 * @h: node
 *
 * Return: number of nodes
 */
size_t print_head(const stack_t *h)
{
	if (!h)
		return (0);
	printf("%d\n", h->n);
	return (0);
}


/**
 * add_dnodeint - add node at the begginning
 * @head: node
 * @n: integer
 *
 * Return: addres of new element
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
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
	nnode->next = *head;
	nnode->prev = NULL;
	if (*head)
		(*head)->prev = nnode;
	*head = nnode;

	return (nnode);
}

/**
 * free_dlistint - free nodes
 *@head: node
 *
 * Return: 0
 */
void free_dlistint(stack_t *head)
{
	stack_t *stop_gap;

	if (!head)
		return;
	while (head)
	{
		stop_gap = head->next;
		free(head);
		head = stop_gap;
	}
}

/**
 * delete_dnodeint_at_index - delete at index
 * @head: head of node
 * @index: index to delete
 *
 * Return: 1 if success -1 else
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	unsigned int i;
	stack_t *stop_gap;

	if (!head || !*head)
		return (-1);
	stop_gap = *head;
	if (index == 0)
	{
		*head = stop_gap->next;
		if (*head)
			(*head)->prev = NULL;
		free(stop_gap);
		return (1);
	}
	for (i = 0; i < index; i++)
	{
		if (!stop_gap)
			return (-1);
		stop_gap = stop_gap->next;
	}
	stop_gap->prev->next = stop_gap->next;
	if (stop_gap->next)
		stop_gap->next->prev = stop_gap->prev;

	free(stop_gap);
	return (1);
}