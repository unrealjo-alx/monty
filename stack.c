#include "stack.h"

/**
 * push - Pushes a value onto the stack
 * @value: The value to be pushed
 * Return: 0 on success, 1 on failure
 */
int push(int value)
{
	stack_t *temp = malloc(sizeof(stack_t));

	if (temp == NULL)
		return (1);
	temp->n = value;
	if (sharedState.head == NULL)
	{
		sharedState.head = temp;
		return (0);
	}
	sharedState.head->prev = temp;
	temp->next = sharedState.head;
	sharedState.head = temp;
	return (0);
}

/**
 * pop - Pops the top value from the stack
 *
 * Return: The value of the popped element, or 0 if the stack is empty
 */
int pop(void)
{
	stack_t *temp = sharedState.head;
	int lastValue;

	if (sharedState.head == NULL)
		return (-1);
	lastValue = sharedState.head->n;
	sharedState.head = temp->next;
	if (sharedState.head != NULL)
		sharedState.head->prev = NULL;
	free(temp);
	return (lastValue);
}

/**
 * print_stack - Prints the values of the stack
 */
void print_stack(void)
{
	stack_t *temp = sharedState.head;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
