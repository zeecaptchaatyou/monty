#include "monty.h"

/**
 * _strdup - duplicates its argument string
 * @str: string to be duplicated
 * Return: pointer to new string if s isn't null, else NULL
*/
char *_strdup(const char *str)
{
char *new_str;
size_t len = 0;

if (str == NULL)
return (NULL);

len = strlen(str);
new_str = (char *)malloc((len + 1) * sizeof(char));
if (new_str == NULL)
return (NULL);

strcpy(new_str, str);
return (new_str);
}


/**
 * read_and_store_file - reads a file and stores its content
 * @filename: pointer to filename to be read and opened
 * Return: pointer to array in which the file's contets are stored
*/
char **read_and_store_file(const char *filename)
{
char dline[MAX_LINE_SIZE], **lines = NULL;
size_t line_count = 0;
FILE *file = fopen(filename, "r"); /*open the file in read mode*/

if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", filename);
exit(EXIT_FAILURE);
}

/*fegegegegegegegeg*/
while (fgets(dline, sizeof(dline), file))
{
/*removes the newline character and replaces it with null*/
dline[strcspn(dline, "\n")] = '\0';

/*remember to check malloc's return here*/
lines = (char **)realloc(lines, (line_count + 1) * sizeof(char *));
lines[line_count] = _strdup(dline);
line_count++;
}

/*now to properly null terminate it so it doesn't lead to*/
/*a segmentation fault*/
lines = realloc(lines, (line_count + 1) * sizeof(char *));
lines[line_count] = NULL;

fclose(file);
return (lines);
}

/**
 * create_token_node - creates a new node for a token
 * @token: token to be stored in created node
 * Return: pointer to the newly created node
*/
token_t *create_token_node(char *token)
{
token_t *new_node;


if (token == NULL)
return (NULL);

new_node = (token_t *)malloc(sizeof(token_t));
if (new_node == NULL)
return (NULL);


new_node->text = _strdup(token);
if (new_node->text == NULL)
{
free(new_node);
return (NULL);
}

/*if this function doesn't work properly, then maybe you should*/
/*come back and set the new_node->next to NULL.....it could help*/
new_node->next = NULL;
return (new_node);
}


/**
 * build_lines_of_tokens - builds lines of tokens
 * @lines: points to the first line gotten from read_and_store_file function
 * Return: pointer to a line_list_t structure
*/
line_list_t *build_lines_of_tokens(char **lines)
{
line_list_t *line_list = NULL;
line_t *prev_line = NULL, *current_line = NULL;
token_t *head_token = NULL, *ptr = NULL;
char *tk;

if (lines == NULL)
return (NULL);

line_list = (line_list_t *)malloc(sizeof(line_list_t));
if (line_list == NULL)
return (NULL);

line_list->head = NULL;
while (*lines)
{
head_token = NULL;
tk = strtok(*lines, " ");

while (tk)
{
if (head_token == NULL)
{
head_token = ptr = create_token_node(tk);
}
else
{ ptr->next = create_token_node(tk);
ptr = ptr->next; }
tk = strtok(NULL, " "); }

current_line = (line_t *)malloc(sizeof(line_t));
if (current_line == NULL)
return (NULL);

current_line->tokens = head_token;

if (prev_line == NULL)
line_list->head = current_line;
else
prev_line->next = current_line;
prev_line = current_line;
current_line->next = NULL;
lines++;
}

return (line_list); }


/**
 * identify - identifies what opcode the head_token contains
 * @head_token: head_token of a line of monty instructions
 * Return: pointer to the corresponding function
*/
void (*identify(token_t *head_token))(stack_t **, unsigned int)
{
size_t i = 0;
char *op = _strdup(head_token->text);
instruction_t instructions[] = {
{"push", push_element},
{"pop", pop},
{"pall", pall},
{"pint", pint},
{NULL, NULL}
};

while (instructions[i].opcode != NULL)
{
if (strcmp(op, instructions[i].opcode) == 0)
{
free(op);
return (instructions[i].f);
}
i++;
}
free(op);
return (NULL);
}

/**
 * push - pushes a number onto the stack
 * @stack: stack unto which a number is to be pushed
 * @line_number: literally the line number
*/
void push_element(stack_t **stack, unsigned int line_number)
{
token_t *token = NULL;
stack_t *new_node = NULL;
int element = 0;
char *element_str = NULL;

if (cur_line != NULL)
{
token = cur_line->tokens;
element_str = _strdup(token->next->text);
if (element_str == NULL)
malloc_error();

element = atoi(element_str);
if (element == 0) /*handle atoi's return*/
{ fprintf(stderr, "L%u: usage: push integer\n", line_number);
free (element_str);
exit(EXIT_FAILURE); }

new_node = (stack_t *)malloc(sizeof(stack_t));
if (new_node == NULL) /*handle malloc's return*/
{ free (element_str);
malloc_error(); }

new_node->n = element;
new_node->prev = NULL; /*debbug here if you have possible erros*/
new_node->next = *stack;

if (*stack != NULL)
(*stack)->prev = new_node;

*stack = new_node;
free(element_str); }}

/**
 * pop - pops an element off a stack_t stack
 * @stack: pointer of type stack_t stack
 * @line_number: literally the line number
*/
void pop(stack_t **stack, unsigned int line_number)
{
stack_t *temp;

if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}
(void)line_number;
temp = *stack;
*stack = temp->next;

if (*stack != NULL)
(*stack)->prev = NULL;

free(temp);
}

/**
 * pall - prints all values on the stack, starting from the top of the stack
 * @stack: pointer of type stack_t stack
 * @line_number: literally the line number
*/
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *current = *stack;

(void)line_number; /*suppresses the unused variable warning*/

while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
line_number++;
}

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer of type stack_t stack
 * @line_number: literally the line number
*/
void pint(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
(void)line_number; /*suppresses the unused variable warning*/

printf("%d\n", (*stack)->n);
line_number++;
}

void malloc_error()
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

/**
 * main - tests the read_and_store_file and build_lines_of_Tokens functions
 * @argc: argument count
 * @argv: array of argument vectors
 * Return: 0
*/
int main(int argc, char **argv)
{
char **file_contents = NULL;
line_list_t *lines_of_tokens = NULL;
line_t *cur_line = NULL;
token_t *token = NULL;
stack_t *stack = NULL;
void (*f_ptr)(stack_t **, unsigned int) = NULL;
size_t line_number = 0;

if (argc != 2)
{
fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
return (1);
}

file_contents = read_and_store_file(argv[1]);

lines_of_tokens = build_lines_of_tokens(file_contents);
cur_line = lines_of_tokens->head;
while (cur_line != NULL)
{
token = cur_line->tokens, f_ptr = identify(token);
if (f_ptr != NULL)
f_ptr(&stack, line_number);
else
{ fprintf(stderr, "L%lu: unknown instruction <opcode>\n", line_number);
exit(EXIT_FAILURE); }
cur_line = cur_line->next;
line_number++;
}
return (0);
}
