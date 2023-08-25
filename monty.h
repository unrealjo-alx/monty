#ifndef MONTY_H
#define MONTY_H

#include "stack.h"

void process_instruction(char *opcode, char *arg, unsigned int line_number);
void free_stack(stack_t **stack);
void cleanup_and_exit();

#endif /* MONTY_H */