#include "monty.h"

/**
 * _add - adds the two top vales of a stack_t list
 * @stack: pointer to the head node
 * @line_number: line number
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_err(short_stack_err(line_number, "add"));
		return;
	}
	(*stack)->next->next->n += (*stack)->next->n;
	_pop(stack, line_number);
}

/**
 * _sub - subtract the second value from the top of stack_t list
 * @stack: a pointer to the top node of the list
 * @line_number: line number
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_err(short_stack_err(line_number, "sub"));
		return;
	}
	(*stack)->next->next->n -= (*stack)->next->n;
	_pop(stack, line_number);
}

/**
 * _div - divides the second value from he top of a stack_t list
 * @stack: a pointer to the top node of the list
 * @line_number: line_number
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_err(short_stack_err(line_number, "div"));
		return;
	}
	if ((*stack)->next->n == 0)
	{
		set_op_tok_err(div_err(line_number));
		return;
	}
	(*stack)->next->next->n /= (*stack)->next->n;
	_pop(stack, line_number);
}

/**
 * _mul - multiply the second value with the top of the stack_t list
 * @stack: a pointer to the top node of the list
 * @line_number: line number
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_err(short_stack_err(line_number, "mul"));
		return;
	}
	(*stack)->next->next->n *= (*stack)->next->n;
	_pop(stack, line_number);
}

/**
 * _mod - compues the modulus of the second value from the stack_t list
 * @stack: a pointer to the top node of the list
 * @line_number: line number
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_err(short_stack_err(line_number, "mod"));
		return;
	}
	if ((*stack)->next->n == 0)
	{
		set_op_tok_err(div_err(line_number));
		return;
	}
	(*stack)->next->next->n %= (*stack)->next->n;
	_pop(stack, line_number);
}
