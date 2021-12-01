#include "monty.h"
/**
 * stack_push - this function add a new node into doubly linked list
 * @head: Reference to the head of doubly linked list
 * @line_num: Reference to the line with an error
 */
void stack_push(stack_t **head, unsigned int line_num)
{
	int number = 0;
	int i = 0;

	if (!vars.stack)
	{
		dprintf(2, "L%u: ", line_num);
		dprintf(2, "usage: push integer\n");
		free_vars();
		exit(EXIT_FAILURE);
	}

	while (vars.stack[i] != '\0')
	{
		if ((!(isdigit(vars.stack[i]))) && vars.stack[i] != '-')
		{
			dprintf(2, "L%u: ", line_num);
			dprintf(2, "usage: push integer\n");
			free_vars();
			exit(EXIT_FAILURE);
		}
		i++;
	}
	number = atoi(vars.stack);
	if (vars.order == 1)
		add_dnodeint(head, number);
	else
		add_dnodeint_end(head, number);
}
/**
 * stack_pall - this function print all values on the doubly linked list
 * @head: reference to the head of doubly linked list
 * @line_num: reference to line we are reading
 */
void stack_pall(stack_t **head, unsigned int line_num)
{
	stack_t *tmp;
	(void)line_num;


	tmp = *head;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * stack_pint - prints only the value at the top of the doubly linked list
 * @head: reference to the head of doubly linked list
 * @line_num: reference to line number if there is an error
 * Return: no return
 */
void stack_pint(stack_t **head, unsigned int line_num)
{
	if (*head == NULL)
	{
		dprintf(2, "L%u: ", line_num);
		dprintf(2, "can't pint, stack empty\n");
		free_vars();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * stack_pop - removes only the top element of the doubly linked list
 * @head: reference to the head of doubly linked list
 * @line_num: reference to line number if there is an error
 * Return: no return
 */
void stack_pop(stack_t **head, unsigned int line_num)
{
	stack_t *tmp;

	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_num);
		free_vars();
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = (*head)->next;
	free(tmp);
}

/**
 * stack_swap - swaps only the two top elements of doubly linked list
 * @head: reference to the head of doubly linked list
 * @line_num: reference to line number if there is an error
 * Return: no return
 */
void stack_swap(stack_t **head, unsigned int line_num)
{
	int nel = 0;
	stack_t *tmp = NULL;

	tmp = *head;

	while (tmp != NULL)
	{
		nel++;
		tmp = tmp->next;
	}
	if (nel < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_num);
		free_vars();
		exit(EXIT_FAILURE);
	}

	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	tmp->prev = *head;
	(*head)->next = tmp;
	(*head)->prev = NULL;
}
