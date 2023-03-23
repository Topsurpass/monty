#include "monty.h"

/**
 * add_node_to_end - add node at the end of doubly linked list
 * @head: the head node
 * @n: the integer data
 *
 * Return: 0 if successful and -1 if failed
 */
int add_node_to_end(stack_t **head, const int n)
{
	stack_t *new;

	if (head == NULL)
		return (-1);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		return (-1);
	}
	new->n = n;

	/* if linked list is empty */
	if (*head == NULL)
	{
		*head = new;
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		new->next = *head;
		(*head)->prev = new;
		*head = new;
	}
	return (0);
}

/**
 * print_all_node - print all the node in doubly linked list
 * from tail node to head
 * @head: the pointer to the head node
 *
 * Return: nothing
 */

void print_all_node(stack_t **head)
{
	stack_t *traverse;

	if (*head == NULL || head == NULL)
		return;
	traverse = *head;

	while (traverse != NULL)
	{
		printf("%d\n", traverse->n);
		traverse = traverse->next;
	}

}

/**
 * free_list - free doubly linked list
 * @head: pointer to the head node
 *
 * Return: nothing
 */
void free_list(stack_t **head)
{
	if (head == NULL || *head == NULL)
		return;

	while (*head != NULL && (*head)->next != NULL)
	{
		*head = (*head)->next;
		free((*head)->prev);
	}
	free(*head);
}
