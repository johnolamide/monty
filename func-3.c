#include "main.h"

/**
 * _nop - does nothing
 * @stack: a pointer to the top node of the list
 * @line_number: line number
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _pchar - prints the character in the top node of the list
 * @stack: a pointer to the top node of the list
 * @line_number: line number
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_err(pchar_err(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_err(pchar_err(line_number, "value out of range"));
		return;
	}
	printf("%c\n", (*stack)->next->n);
}

/**
 * _pstr - prints the strings contaned in a stack_t list
 * @stack : a pointer to the top node of the list
 * @line_number: line number
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
	(void)line_number;
}
