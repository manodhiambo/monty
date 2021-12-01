#include "monty.h"
/**
 * stack_div - divides the second top element of stack from the top element
 * @head: head to the stack
 * @line_num: Reference to the line we are checking in case of an error
 */
void stack_div(stack_t **head, unsigned int line_num)
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
		dprintf(2, "L%u: can't div, stack too short\n", line_num);
		free_vars();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_num);
		free_vars();
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	tmp->n = (int)(tmp->n) / (*head)->n;
	stack_pop(head, line_num);
}
/**
 * stack_mul - multiplies the top two elements of the stack
 * @head: head to the stack
 * @line_num: Reference to the line we are checking in case of an error
 */
void stack_mul(stack_t **head, unsigned int line_num)
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
		dprintf(2, "L%u: can't mul, stack too short\n", line_num);
		free_vars();
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	tmp->n *= (*head)->n;
	stack_pop(head, line_num);
}
/**
 * stack_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @head: head to the stack
 * @line_num: Reference to the line we are checking in case of an error
 */
void stack_mod(stack_t **head, unsigned int line_num)
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
		dprintf(2, "L%u: can't mod, stack too short\n", line_num);
		free_vars();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_num);
		free_vars();
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	tmp->n = (int)(tmp->n) % (*head)->n;
	stack_pop(head, line_num);
}
/**
 * stack_pchar - print the top ASCII character of linked list
 * @head: head to the stack
 * @line_num: Reference to the line we are checking in case of an error
 */
void stack_pchar(stack_t **head, unsigned int line_num)
{
	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_num);
		free_vars();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_num);
		free_vars();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}
/**
 * stack_pstr - prints all values of linked list in ASCII until find a zero
 * or another character that doesn't have an ASCII representation
 * @head: head to the stack
 * @line_num: Reference to the line we are checking in case of an error
 */
void stack_pstr(stack_t **head, unsigned int line_num)
{
	stack_t *tmp;
	(void)line_num;

	tmp = *head;
	while (tmp && tmp->n > 0 && tmp->n < 128)
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");
}
