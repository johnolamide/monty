#include "monty.h"
/**
 * free_stack - frees a stack_t stack
 * @stack: pointer to the head node
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * init_stack - initializes a stack_t stack
 * @stack: pointer to the head node
 * Return: EXIT_FAILURE if error, EXIT_SUCESS otherwise
 */
int init_stack(stack_t **stack)
{
	stack_t *s = malloc(sizeof(stack_t));

	if (s == NULL)
		return (malloc_err());
	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;
	*stack = s;
	return (EXIT_SUCCESS);
}

/**
 * check_mode - checks if a stack_t list is in stack or queue mode
 * @stack: pointer to the head node
 * Return: 0 if in stack mode, 1 if in queue mode, 2 otherwise
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
