#include "monty.h"

/**
 * get_op_code_func - compare opcodes and perform its corresponding function
 * @toks: the opcode to be compared
 *
 * Return: a function to pointer
 */
void (*get_op_code_func(char *toks))(stack_t **stack, unsigned int line_number)
{
	instruction_t op_arr[] = {
		{"pall", pall_stack},
		{"pint", pint_stack},
		{"pop", pop_stack},
		{"add", add_stack},
		{"nop", do_nothing},
		{"swap", swap},
		{NULL, NULL}
	};

	int i = 0;

	while (op_arr[i].opcode != NULL)
	{
		if (strcmp(toks, op_arr[i].opcode) == 0)
		{
			return (op_arr[i].f);
		}
		i++;
	}
	return (NULL);
}

