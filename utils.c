#include "stack.h"
/**
 * free_stack - Frees a stack
 * @stack: Double pointer to the stack
 *
 * This function frees all the nodes in a stack
 * and sets the stack pointer to NULL.
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*stack = NULL;
}
