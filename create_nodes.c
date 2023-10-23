#include "monty.h"

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
