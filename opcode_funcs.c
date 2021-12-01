#include "monty.h"
/**
 * stack_add - adds only the top two elements of the stack
 * @head: Reference to the head of doubly linked list
 * @line_num: Reference to the line we are checking in case of an error
 */
void stack_add(stack_t **head, unsigned int line_num)
{
	stack_t *tmp = NULL;
	int nel = 0;

	tmp = *head;
	while (tmp)
	{
		nel++;
		tmp = tmp->next;
	}
	if (nel < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_num);
		free_vars();
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	tmp->n += (*head)->n;
	stack_pop(head, line_num);
}
/**
 * stack_nop - Doesn't do anything
 * @head: Reference to the head of doubly linked list
 * @line_num: Reference to the line we are checking in case of an error
 */
void stack_nop(stack_t **head, unsigned int line_num)
{
	(void)head;
	(void)line_num;
}
/**
 * stack_sub - subtracts the top element of stack from the second element
 * @head: head to the stack
 * @line_num: Reference to the line we are checking in case of an error
 */
void stack_sub(stack_t **head, unsigned int line_num)
{
	stack_t *tmp = NULL;
	int nel = 0;

	tmp = *head;
	while (tmp)
	{
		nel++;
		tmp = tmp->next;
	}
	if (nel < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_num);
		free_vars();
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	tmp->n -= (*head)->n;
	stack_pop(head, line_num);
}
/**
 * stack_queue - sets the format of the data to a FIFO stack
 * @head: Reference to the head of doubly linked list
 * @line_num: Reference to the line we are checking in case of an error
 */
void stack_queue(stack_t **head, unsigned int line_num)
{
	(void)head;
	(void)line_num;

	vars.order = 0;
}

/**
 * order_stack - sets the format fo the data to a LIFO stack
 * @head: Reference to the head of doubly linked list
 * @line_num: Reference to the line we are checking in case of an error
 */
void order_stack(stack_t **head, unsigned int line_num)
{
	(void)head;
	(void)line_num;

	vars.order = 1;
}
