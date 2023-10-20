#include "monty.h"
#include <string.h>

/**
 * read_and_store_file - reads a file and stores its content
 * @filename: pointer to filename to be read and opened
 * Return: pointer to array in which the file's contets are stored
*/
char **read_and_store_file(const char *filename)
{
char line[MAX_LINE_SIZE], **lines = NULL;
size_t err_msg_len, line_count = 0;
FILE *file = fopen(filename, "r"); /*open the file in read mode*/
char *err_msg = malloc(MAX_ERR_MSG_SIZE);

if (err_msg == NULL)
{
fprintf(stderr, "Error: Failed to allocate memory for error message\n");
exit(EXIT_FAILURE);
}

strcat(err_msg, filename);
strcat(err_msg, "\n");

err_msg_len = strlen(err_msg);
if (file == NULL)
{
write(2, err_msg, err_msg_len);
exit(EXIT_FAILURE);
}

/*fegegegegegegegeg*/
while (fgets(line, sizeof(line), file))
{
/*removes the newline character and replaces it with null*/
line[strcspn(line, "\n")] = '\0';

lines = (char **)realloc(lines, (line_count + 1) * sizeof(char *));
lines[line_count] = _strdup(line);
line_count++;
}

/*now to properly null terminate it so it doesn't lead to*/
/*a segmentation fault*/
lines = realloc(lines, (line_count + 1) * sizeof(char *));
lines[line_count] = NULL;

fclose(file);
free(err_msg);
return (lines);
}

/**
 * parser - parses sha
 * @lines: data to parse
 * Return: parserd data, oti sunnmiiiiiii
*/
char ***parser(char **lines)
{
char ***tokens_arr = NULL, **tokens = NULL, *token;
char **line = lines;
size_t line_len = 0, i = 0;
size_t token_count = 0;

if (lines == NULL)
return (NULL);

for ( ; *line; line++)
line_len++;

tokens_arr = (char ***)malloc((line_len + 1) * sizeof(char **));
if (tokens_arr == NULL)
return (NULL);

for (line = lines; *line; line++)
{
token = strtok(*line, " ");
while (token)
{
token_count++;
tokens = (char **)realloc(tokens, (token_count + 1) * sizeof(char *));
tokens[token_count - 1] = strdup(token);
token = strtok(NULL, " ");
}

tokens_arr[i] = tokens;
i++;
}

tokens_arr[i] = NULL;
return (tokens_arr);
}
