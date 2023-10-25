#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_LINES 100
#define MAX_TOKENS 10
#define MAX_ERR_MSG_SIZE 1024

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct token - singly linked list for the tokens
 * @text: contains the tokens
 * @next: pointer to the next token
*/
typedef struct token
{
char *text;
struct token *next;
} token_t;

/**
 * struct line - singly linked structure for an entire line
 * @tokens: head node of an entire line of tokens
 * @next: pointer  to the next token
*/
typedef struct line
{
struct token *tokens; /*points to the first token on each line*/
struct line *next; /*points to the next line*/
} line_t;

extern line_t *cur_line;

/**
 * line_list - structure for the entire list of lines containng tokens
 * @head: head node to the first line in the list
*/
typedef struct line_list
{
struct line *head;
} line_list_t;


void *_realloc(void *ptr, size_t old_size, size_t new_size);
char *_strdup(const char *str);
char ***parse(char **lines);

token_t *create_token_node(char *token);
line_list_t *build_lines_of_tokens(char **lines);
char **read_and_store_file(const char *filename);

/*freeing functions*/
void free_token(token_t *token);
void free_line(line_t *line);
void free_line_list(line_list_t *lines);
void f_token(line_t *line, line_list_t *line_list);
void f_line(token_t *token, line_list_t *line_list);
void f_line_list();

/*error handling functions*/
void malloc_error();

/*opcodes functions*/
void push_element(stack_t **stack, unsigned int line_number);
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


void (*identify(token_t *head_token))(stack_t **, unsigned int);



#endif /*MONTY_H*/
