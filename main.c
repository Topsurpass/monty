#include "monty.h"

/**
 * main - the entrance to our program
 * @argc: argument counter
 * @argv: argument vector
 *
 * Return: 0 (end of our program)
 */

int main(int argc, char **argv)
{
	int fd, pushed = 0;
	unsigned int line = 1;
	ssize_t no_of_byte;
	char *buffer, *token, *delim = "\n\t\a\r ;:";
	stack_t *head = NULL;


	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Cant open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buffer = malloc(sizeof(char) * 10000);
	if (buffer == NULL)
		return (0);

	no_of_byte = read(fd, buffer, 10000);

	if (no_of_byte == -1)
	{
		free(buffer);
		close(fd);
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, delim);
	while (token != NULL)
	{
		if (pushed == 1)
		{
			push_val(&head, line, token);
			pushed = 0;
			token = strtok(NULL, delim);
			line++;
			continue;
		}
		/**
		 * if (strcmp(token, "push") == 0)
		 * {
		 *	token = strtok(NULL, delim);
		 * 	push_val(&head, line, token);
		 * }
		 */
		else if (strcmp(token, "push") == 0)
		{
			pushed = 1;
			token = strtok(NULL, delim);
			continue;
		}
		else
		{
			if (get_op_code_func(token) != NULL)
				get_op_code_func(token)(&head, line);
			else
			{
				free_list(&head);
				printf("L%d: unknown instruction %s\n", line, token);
				exit(EXIT_FAILURE);
			}
		}
		line++;
		token = strtok(NULL, delim);
	}
	free_list(&head);
	free(buffer);
	close(fd);
	return (0);
}
