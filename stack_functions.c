#include "monty.h"

/**
 * push_val - Push values to the top of stack
 * @head: the pointer to the end of stack
 * @line_number: the line number where error occured
 * @n: the integer to be added to stack
 *
 * Return: nothing
 */
void push_val(stack_t **head, unsigned int line_number, char *n)
{
	int rtr_val;

	if (head == NULL)
		return;

	/* if n is not integer(digit) or no argument passed */
	if ((atoi(n) == 0 && *n != '0') || isdigit(atoi(n)) != 0)
	{
		printf("L%u: usage: push integer\n", line_number);
		free_list(head);
		exit(EXIT_FAILURE);
	}
	else
	{
		rtr_val = add_node_to_end(head, atoi(n));
		if (rtr_val == -1)
		{
			free_list(head);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * pall_stack - print all the values on the stack, from top
 * of the stack to bottom
 * @head: the pointer to the end of the stack
 * @line_number: the line number where error occured
 *
 * Return: nothing
 */

void pall_stack(stack_t **head, unsigned int line_number)
{
	(void) line_number;
	print_all_node(head);
}

/**
 * pint_stack - print all the values on the stack, from
 * top of the stack
 * @head: the pointer to the end of the stack
 * @line_number: the line number where error occured
 *
 * Return: nothing
 */
void pint_stack(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || head == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
/**
 * pop_stack - remove the top element from the stack
 * @head: the pointer to the top element of the stack
 * @line_number: the line number containing the error
 *
 * Return: nothing
 */
void pop_stack(stack_t **head, unsigned int line_number)
{
	stack_t *del = NULL;

	/* if no doubly linked list or if the doubly linked list is empty */
	if (head == NULL || *head == NULL)
	{
		printf("L%u: can't pop and empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* if there's just one node in the doubly linked list */
	else
	{
		del = *head;
		if ((*head)->next == NULL)
		{
			*head = NULL;
			free(del);
		}
		else
		{
			*head = (*head)->next;
			(*head)->prev = NULL;
			free(del);
		}
	}
}
/**
 * swap - swaps the top two elements of the stack
 * @line_number: the line where error occur
 * @head: the pointer to the top of the stack
 *
 * Return: nothing
 */
void swap(stack_t **head, unsigned int line_number)
{
	stack_t *holder = NULL;

	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	holder = (*head)->next;
	/* if more than 2 elements in stack */
	if (holder->next != NULL)
	{
		(*head)->next = holder->next;
		(*head)->next->prev = *head;
	}
	else
	{
		holder->prev->prev = holder;
		holder->prev->next = NULL;
	}
	holder->prev = NULL;
	holder->next = *head;
	(*head) = holder;
}
