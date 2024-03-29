#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/**
 ** struct stack_s - doubly linked list representation of a stack (or queue)
 ** @n: integer
 ** @prev: points to the previous element of the stack (or queue)
 ** @next: points to the next element of the stack (or queue)
 **
 ** Description: doubly linked list node structure
 ** for stack, queues, LIFO, FIFO
 **/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 ** struct instruction_s - opcode and its function
 ** @opcode: the opcode
 ** @f: function to handle the opcode
 **
 ** Description: opcode and its function
 ** for stack, queues, LIFO, FIFO
 **/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#define MAX_LEN 128

stack_t *createNode(int value);
void process_file(char *filen, stack_t **head);
int is_valid_instruction(const char *instruction);
void _execute(char *opcode, stack_t **head, int line_number, char *argument);
void freeList(stack_t *head);
char *is_arg_integer(int line_number, char *argument);
void push(stack_t **top, int line_number, char *argument);
void pall(stack_t **top);
void pint(stack_t **head, int line_number);
void pop(stack_t **head, int line_number);
void swap(stack_t **head, int line_number);
void add(stack_t **head, int line_number);
void nop(stack_t **head, int counter);
void sub(stack_t **head, int line_number);
void division(stack_t **head, int line_number);
void mul(stack_t **head, int line_number);
void mod(stack_t **head, int line_number);
#endif

