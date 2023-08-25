#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "monty.h"

#define MAX_BUFFER_SIZE 524

global_v sharedState;

/**
 * main - Monty bytecode interpreter
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	char buffer[MAX_BUFFER_SIZE];
	char *opcode, *arg;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	sharedState.file = fopen(argv[1], "r");
	if (sharedState.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (fgets(buffer, sizeof(buffer), sharedState.file))
	{
		line_number++;

		opcode = strtok(buffer, " \t\n");
		if (opcode == NULL || opcode[0] == '#')
			continue;

		arg = strtok(NULL, " \t\n");

		process_instruction(opcode, arg, line_number);
	}

	fclose(sharedState.file);
	free_stack(&sharedState.head);

	return (EXIT_SUCCESS);
}

/**
 * process_instruction - Process a Monty bytecode instruction
 * @opcode: the opcode
 * @arg: the argument (if any)
 * @line_number: the line number of the instruction
 */
void process_instruction(char *opcode, char *arg, unsigned int line_number)
{
	if (!strcmp(opcode, "push"))
	{
		if (arg == NULL)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			fclose(sharedState.file);
			free_stack(&sharedState.head);
			exit(EXIT_FAILURE);
		}
		if (push(atoi(arg)))
		{
			fclose(sharedState.file);
			free_stack(&sharedState.head);
			exit(EXIT_FAILURE);
		}
	}
	else if (!strcmp(opcode, "pall"))
	{
		print_stack();
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		fclose(sharedState.file);
		free_stack(&sharedState.head);
		exit(EXIT_FAILURE);
	}
}
