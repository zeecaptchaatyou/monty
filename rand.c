#include "monty.h"

/**
 * _strdup - duplicates its argument string
 * @str: string to be duplicated
 * Return: pointer to new string if s isn't null, else NULL
*/
char *_strdup(const char *str)
{
char *new_str;
size_t i = 0, len = 0;

if (str == NULL)
return (NULL);

len = strlen(str);
new_str = (char *)malloc((len + 1) * sizeof(char));
if (new_str == NULL)
return (NULL);

for ( ; str[i]; i++)
new_str[i] = str[i];

new_str[i] = '\0';

return (new_str);

}

char ***parse(char **lines)
{
    char ***tokens_arr = NULL;
    char *token;
    size_t line_count = 0;

    if (lines == NULL)
        return NULL;

    for (char **line = lines; *line; line++) {
        size_t token_count = 0;
        char **tokens = NULL;

        token = strtok(*line, " ");
        while (token) {
            token_count++;
            tokens = (char **)realloc(tokens, (token_count + 1) * sizeof(char *));
            tokens[token_count - 1] = _strdup(token);
            token = strtok(NULL, " ");
        }

        tokens = (char **)realloc(tokens, (token_count + 1) * sizeof(char *));
        tokens[token_count] = NULL;  // Terminate tokens with a NULL pointer

        tokens_arr = (char ***)realloc(tokens_arr, (line_count + 2) * sizeof(char **));
        tokens_arr[line_count] = tokens;
        line_count++;
    }

    tokens_arr[line_count] = NULL;
    return tokens_arr;
}

#include "monty.h"

int main(void)
{
    char **lines = malloc(3 * sizeof(char *));
    lines[0] = "push 1";
    lines[1] = "pop";
    lines[2] = "push 3";

    char ***tokens = parse(lines);

    if (tokens == NULL)
    {
        fprintf(stderr, "Parsing failed\n");
        return 1;
    }

    size_t i = 0, j = 0;

    while (tokens[i] != NULL)
    {
        j = 0;
        while (tokens[i][j] != NULL)
        {
            printf("Line %lu, Token %lu: %s\n", i + 1, j + 1, tokens[i][j]);
            j++;
        }
        i++;
    }

    // Free the dynamically allocated memory when done
    for (i = 0; tokens[i] != NULL; i++)
    {
        j = 0;
        while (tokens[i][j] != NULL)
        {
            free(tokens[i][j]);
            j++;
        }
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}
