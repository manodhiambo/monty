#include "monty.h"

global_t vars;

/**
 * init - initialize all variables into the struct global_t
 * and keep values while the program finish
 * @fd: - file descriptor of file opened
 * Return: No return
 */
void init(FILE *fd)
{
	vars.order = 1;
	vars.fd = fd;
	vars.cline = 1;
	vars.buffer = NULL;
	vars.stack = NULL;
	vars.head = NULL;
}

/**
 * check_open - validate if the argument represent a file or not
 * @argc: Counter of arguments
 * @argv: Pointer with the reference to arguments
 * Return: File descriptor of file opened or -1 is not exists
 */
FILE *check_open(int argc, char **argv)
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

/**
 * main - this function evaluates the input to execute the
 * functions
 * @argc: Counter of arguments
 * @argv: Pointer to arguments
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	FILE *fd;
	size_t size = 128;
	ssize_t line_num = 0;
	char *args[2] = {NULL, NULL};
	void (*f)(stack_t **head, unsigned int line_number);

	fd = check_open(argc, argv);
	init(fd);
	line_num = getline(&vars.buffer, &size, fd);
	while (line_num != -1)
	{
		args[0] = strtok(vars.buffer, " \n\t");
		if (args[0][0] != '#' && args[0])
		{
			f = get_opcode_func(args[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", vars.cline);
				dprintf(2, "unknown instruction %s\n", args[0]);
				free_vars();
				exit(EXIT_FAILURE);
			}
			vars.stack = strtok(NULL, " \n\t");
			f(&vars.head, vars.cline);
		}
		line_num = getline(&vars.buffer, &size, fd);
		vars.cline++;
	}

	free_vars();
	return (0);
}
