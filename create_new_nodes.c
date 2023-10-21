#include "monty.h"

/**
 * token_node - creates a new node for a token
 * @token: token to be stored in created node
 * Return: pointer to the newly created node
*/
token_t *token_node(char *token)
{
token_t *new_node;

if (token == NULL) /*check if this should be erased later, since this
token_node function is being called in a loop that runs on the condition that
the token isn't null, you gerrit? 😂😂*/
return (NULL);

new_node = (token_t *)malloc(sizeof(token_t));
if (new_node == NULL)
return (NULL);

new_node->text = token;

return (new_node);
}











/**
 * line_node - creates a new node for a line of tokens
 * @first_token: pointer to the first token of type token_t on line 1
 * Return: pointer to the first line
*/
line_t *line_node(token_t first_token);
{
line_t *new_node;

if (first_token == NULL)
return (NULL);

}
