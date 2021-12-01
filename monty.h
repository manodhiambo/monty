#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_variables - all global variables to initialize
 * @order: Stablish the order of the stack, when is a queue or stack
 * @fd: File wil be open
 * @cline: Counter of lines into file
 * @buffer: this pointer allocate the data of each line of the file
 * @stack: Reference to the stack will be added
 * @head: Reference the head of doubly linked list
 * Description: keeps all variables expecting for a value
 */
typedef struct global_variables
{
	int order;
	FILE *fd;
	unsigned int cline;
	char *buffer;
	char *stack;
	stack_t *head;
} global_t;

extern global_t vars;
void (*get_opcode_func(char *s))(stack_t **head, unsigned int line_number);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_vars(void);
void free_stack(stack_t *head);
void stack_push(stack_t **head, unsigned int line_num);
void stack_pall(stack_t **head, unsigned int line_num);
void stack_pint(stack_t **head, unsigned int line_num);
void stack_pop(stack_t **head, unsigned int line_num);
void stack_add(stack_t **head, unsigned int line_num);
void stack_swap(stack_t **head, unsigned int line_num);
void stack_nop(stack_t **head, unsigned int line_num);
void stack_sub(stack_t **head, unsigned int line_num);
void stack_div(stack_t **head, unsigned int line_num);
void stack_mul(stack_t **head, unsigned int line_num);
void stack_mod(stack_t **head, unsigned int line_num);
void stack_pchar(stack_t **head, unsigned int line_num);
void stack_pstr(stack_t **head, unsigned int line_num);
void stack_queue(stack_t **head, unsigned int line_num);
void order_stack(stack_t **head, unsigned int line_num);
FILE *check_open(int argc, char **argv);
void init(FILE *fd);
#endif /* #ifndef MONTY_H */
