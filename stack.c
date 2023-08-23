#include "stack.h"

/**
 * push - Pushes a value onto the stack
 * @value: The value to be pushed
 */
void push(int value)
{
	stack_t *temp = malloc(sizeof(stack_t));

	if (temp == NULL)
		return;
	temp->n = value;
	if (head == NULL)
	{
		head = temp;
		return;
	}
	head->prev = temp;
	temp->next = head;
	head = temp;
}

/**
 * pop - Pops the top value from the stack
 *
 * Return: The value of the popped element, or 0 if the stack is empty
 */
int pop(void)
{
	stack_t *temp = head;
	int lastValue;

	if (head == NULL)
		return (-1);
	lastValue = head->n;
	head = temp->next;
	if (head != NULL)
		head->prev = NULL;
	free(temp);
	return (lastValue);
}

/**
 * print_stack - Prints the values of the stack
 */
void print_stack(void)
{
	stack_t *temp = head;

	if (head == NULL)
		return;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
