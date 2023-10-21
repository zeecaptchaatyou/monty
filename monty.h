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

void *_realloc(void *ptr, size_t old_size, size_t new_size);
char **read_and_store_file(const char *filename);
char *_strdup(const char *str);
char ***parse(char **lines);


typedef struct token token_t;
typedef struct line line_t;


/**
 * struct token - singly linked list for the tokens
 * @text: contains the tokens
 * @next: pointer to the next token
*/
typedef struct token
{
char *text;
token_t *next;
} token_t;

/**
 * struct line - singly linked structure for an entire line
 * @tokens: head node of an entire line of tokens
 * @next: pointer  to the next token
*/
typedef struct line
{
token_t *tokens; /*points to the first token on each line*/
line_t *next; /*points to the next line*/
} line_t;

/**
 * line_list - structure for the entire list of lines containng tokens
 * @head: head node to the first line in the list
*/
typedef struct line_list
{
line_t *head;
} line_list_t;




#endif /*MONTY_H*/
