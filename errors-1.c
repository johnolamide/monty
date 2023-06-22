#include "main.h"

/**
 * usage_err - prints usage error messages.
 * Return: EXIT_FAILURE
 */
int usage_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_err - preins malloc error messages
 * Return: EXIT_FAILURE
 */
int malloc_err(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_err - prints file opening erro message wih filename
 * @filename: name of the file that failed
 * Return: EXIT_FAILURE
 */
int f_open_err(char *filename)
{
	fprintf(stderr, "Error: can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_err - prints unknown instruction error message
 * @opcode: opcode where error occured
 * @line_number: line number where error occured
 * Return: EXIT_FAILURE
 */
int unknown_op_err(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_err - print invalid argument error message
 * @line_number: line number where erro occured
 * Return: EXIT_FAILURE
 */
int no_int_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
