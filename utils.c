#include "stack.h"
#include <ctype.h>
#include <string.h>
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
/**
 * trim_string - Trims leading and trailing whitespace from a string,
 * @s: The string to be trimmed.
 */
void trim_string(char *s)
{
	size_t len;
	char *end, *start = s;

	while (*start && isspace((unsigned char)*start))
		++start;

	len = strlen(start);
	memmove(s, start, len + 1);

	end = s + len - 1;
	while (end >= s && isspace((unsigned char)*end))
		--end;
	*(end + 1) = '\0';
}
