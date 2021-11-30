#include "monty.h"
/**
 * get_opcode_func - get the option of char input to perform the opcode
 * @s: input opcode
 * Return: a pointer to the function given the opcode or NULL if not found
 */
void (*get_opcode_func(char *s))(stack_t **head, unsigned int line_num)
{
	int i = 0;
	instruction_t stack[] = {
		{"push", stack_push},
		{"pall", stack_pall},
		{"pint", stack_pint},
		{"swap", stack_swap},
		{"pop", stack_pop},
		{"add", stack_add},
		{"nop", stack_nop},
		{"sub", stack_sub},
		{"div", stack_div},
		{"mul", stack_mul},
		{"mod", stack_mod},
		{"queue", stack_queue},
		{"stack", order_stack},
		{"pchar", stack_pchar},
		{"pstr", stack_pstr},
		{NULL, NULL}
	};

	while (stack[i].opcode)
	{
		if (strcmp(stack[i].opcode, s) == 0)
			break;
		i += 1;
	}
	return (stack[i].f);
}
