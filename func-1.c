#include "main.h"

/**
 * _push - push a node to a stack_t list
 * @stack: a pointer to the head node
 * @line_number: line number
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int n;
	char *n_str;

	n_str = strtok(NULL, DELIMS);
	if (n_str == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(n_str);
	if (n == 0 && *n_str != '0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * _pall - print all values in a stack
 * @stack: pointer to thr head node
 * @line_number: line number
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * _pint - print the value at the top of the stack
 * @stack: pointer to the head node
 * @line_number: line number
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		pint_err(line_number);
	printf("%d\n", (*stack)->n);
}

/**
 * _pop - remove top element of the stack
 * @stack: pointer to the head node
 * @line_number: line number
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
		pop_err(line_number);
	tmp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * _swap - swap the two top element of the stack
 * @stack: pointer to the head node
 * @line_number: line number
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	 tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
