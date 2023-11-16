#include "monty.h"

extra_t treck = {NULL, NULL, 0, "stack"};
/**
 * main - entry point
 * @argc: argument count
 * @argv: argument value
 *
 * Return: 0 or exit error
 */
int main(int argc, char **argv)
{
	int num, j, i;
	char temp[1000];
	stack_t *head;
	unsigned int lines = 1;

	treck.buf = malloc(sizeof(char) * 100024);
	if (treck.buf == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i <= 100023; i++)
		treck.buf[i] = '\0';

	head = NULL;
	errors(argc, argv);

	num = read(treck.fd, treck.buf, sizeof(char) * 100024);
	if (num == -1)
	{
		free(treck.buf);
		return (0); }
	j = 0;
	while (treck.buf[j] != '\0')
	{
		i = 0;
		for (; treck.buf[j] != '\n' && treck.buf[j] != '\0'; j++, i++)
			temp[i] = treck.buf[j];
		temp[i] = '\0';
		if (temp[0] != '\0' && temp[0] != '\n')
		{
			run_comp(temp, &head, lines); }
		lines++;
		j++; }
	close(treck.fd);
	free_dlistint(head);
	free(treck.buf);
	return (0);
}

/**
 * errors - handle errors in main
 * @argc: argument count
 * @argv: argument value
 *
 * Return: 0 or exit error
 */
void errors(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free(treck.buf);
		exit(EXIT_FAILURE); }
	treck.fd = open(argv[1], O_RDONLY);
	if (!argv[1] || treck.fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free(treck.buf);
		exit(EXIT_FAILURE); }
}
