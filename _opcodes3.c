#include "monty.h"

/**
 * run_comp - runute
 * @tmp: cmd line
 * @head: head of list
 * @line: line number
 * Return: next line number
 */
void run_comp(char *tmp, stack_t **head, unsigned int line)
{
	char *cmd;
	void (*run)(stack_t **head, unsigned int n);

	cmd = strtok(tmp, " ");
	treck.num_string = strtok(NULL, " ");
	if (cmd && cmd[0] != '#')
	{
		run = get_op_func(cmd);
		if (run == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n"
				, line, cmd);
			close(treck.fd);
			free(treck.buf);
			free_dlistint(*head);
			exit(EXIT_FAILURE);
		}
		run(head, line);
	}
}

/**
 * get_op_func - get the op function
 * @cmd: opcode
 *
 * Return: No -  0 if fail or call the function
 */
void (*get_op_func(char *cmd))(stack_t **head, unsigned int line)
{
	instruction_t run_ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"sub", sub},
		{"div", div_func},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"nop", nop},
		{"#", nop},
		{"swap", swap},
		{"rotl", rotl},
		{"pstr", pstr},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL}
	};
	int i, length;

	length = strlen(cmd);
	for (i = 0; run_ops[i].opcode; i++)
	{
		if (strncmp((run_ops[i].opcode), cmd, length) == 0)
			return (run_ops[i].f);
	}

	return (run_ops[i].f);
}