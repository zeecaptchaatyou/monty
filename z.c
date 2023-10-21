#include "monty.h"

/**
 * token_counter - counts possible number of tokens in a line
 * so as to aid memory allocation with malloc.
 * @line: line to whose tokens are to be counted
 * Return: number of tokens on @line.
*/
size_t token_counter(char *line) 
{
size_t count = 0;
char *token = strtok(line, " ");

while (token)
{
count++;
token = strtok(NULL, " ");
}

return (count);
}


int token_array_counter(char **lines);


char ***parser(char **lines)
{
size_t i = 0, j = 0, k = 0;
char *token;
char **tokens = NULL;
char ***tokens_array = NULL;
char **line;
size_t token_count = 0;

if (lines == NULL)
return (NULL);

line = lines;

for ( ; *line; line++)
{
j = 0;
token_count = token_counter(*line);
tokens = (char **)malloc(token_count * sizeof(char *));

token = strtok(*line, " ");
while (token)
{
printf("%s\n", token);
tokens[j] = token;
token = strtok(NULL, " "), j++;
}

tokens_array[i] = tokens, i++;

}


}


int main() {
    char str[] = "Zainab Ayomiposi Zeecaptcha Jimoh";
    char *token = strtok(str, " ");

    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
printf("token of 0 = %s\n", token);
    return 0;
}
