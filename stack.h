#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>

/* Struct Definition */
/**
 * struct stack_s - A stack node structure
 * @n: The value stored in the stack node
 * @prev: Pointer to the previous node in the stack
 * @next: Pointer to the next node in the stack
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/* Global Variable */
/*  Globales */
typedef struct global
{
	FILE *file;
	stack_t *head;
} global_v;
extern global_v sharedState;

/* Function Prototypes */
int push(int value);
int pop(void);
void print_stack(void);
#endif /* STACK_H */
