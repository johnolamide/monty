#include "monty.h"

char **op_toks = NULL;
/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = 0;

	if (argc != 2)
		return (usage_err());
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (f_open_err(argv[1]));
	exit_code = run_monty(script_fd);
	fclose(script_fd);
	return (exit_code);
}
