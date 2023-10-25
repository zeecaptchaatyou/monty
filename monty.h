#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \t\n\a\b"

/* GLOBAL OPCODE TOKENS */
extern char **op_toks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void (*identify(char *opcode))(stack_t**, unsigned int);

/*opcode functions*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);


/*random functions*/
void free_stack(stack_t **stack);
int stack_initiator(stack_t **stack);
int mode_checker(stack_t *stack);
void free_tokens(void);
unsigned int token_length_counter(void);
int sidekick(FILE *script_fd);
void lastTokenisAnError(int error_code);


char **strtow(char *str, char *delims);
char *get_int(int n);
int is_delim(char ch, char *delims);
int get_word_count(char *str, char *delims);
int get_word_length(char *str, char *delims);
int get_word_length(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/*functions from the error handling files*/
int usage_err(void);
int empty_stack_err(unsigned int line_number);
int short_stack_error(unsigned int line_number, char *op);
int invalid_opcode_err(char *opcode, unsigned int line_number);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);
int malloc_error(void);
int pint_error(unsigned int line_number);
int file_opening_err(char *filename);
int invalid_push_err(unsigned int line_number);
int invalid_line_checker(char *line, char *delims);

#endif /* __MONTY_H__ */
