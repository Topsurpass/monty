#include "monty.h"

/**
 * add_stack - add top 2 elements of the stack
 * @head: pointer to the top of the stack
 * @line_number: the line where error occured
 *
 * Return: nothing
 */
void add_stack(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%u: can't  add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n += (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;

}
/**
 * do_nothing - do nothing to the stack
 * @head: the pointer to the top of the stack
 * @line_number: the line where error occured
 *
 * Return: nothing
 */
void do_nothing(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
}
