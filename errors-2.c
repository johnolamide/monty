#include "main.h"

/**
 * pop_err - prints pop error message
 * @line_number: line number in script where error ocured
 * Return: EXIT_FAILURE
 */
int pop_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pint_err - prints pint error message
 * @line_number: line number where error occured
 * Return: EXIT_FAILURE
 */
int pint_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * short_stack_err - prints error message for stacks smaller than two nodes
 * @line_number: line number where error occured
 * @op: operation where error occured
 * Return: EXIT_FAILURE
 */
int short_stack_err(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * div_err - prints dision error message
 * @line_number: line number where error occured
 * Return: EXIT_FAILURE
 */
int div_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pchar_err - prints pchar error messaged for empty stack
 * @line_number: linee number where error occured
 * @message: the message to print
 * Return: EXIT_FAILURE
 */
int pchar_err(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
