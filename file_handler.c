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
 * parse - parses sha
 * @lines: data to parse
 * Return: parserd data, oti sunnmiiiiiii
*/
char ***parse(char **lines)
{
char ***tokens_arr = NULL, **tokens = NULL, *token;
char **line = lines;
size_t line_count = 0, i = 0;
size_t token_count = 0;

if (lines == NULL)
return (NULL);

for ( ; *line; line++) /*count the number of lines*/
line_count++;

tokens_arr = (char ***)malloc((line_count + 1) * sizeof(char **));
if (tokens_arr == NULL)
return (NULL);

for (line = lines; *line; line++) /*parse each line into tokens*/
{
token = strtok(*line, " ");
while (token)
{
token_count++;
tokens = (char **)realloc(tokens, (token_count + 1) * sizeof(char *));
tokens[token_count - 1] = _strdup(token);
token = strtok(NULL, " ");
}

tokens_arr[i] = tokens;
i++;
}

tokens_arr[i] = NULL;
return (tokens_arr);
}

/**
 * main - tests the parse function
 * Return: 0
*/
int main(void)
{
char **lines = malloc(4 * sizeof(char *));
size_t i = 0, j = 0;
char ***tokens = NULL;

lines[0] = "push 1";
lines[1] = "pop";
lines[2] = "push 3";
lines[3] = NULL;

tokens = parse(lines);
if (tokens == NULL)
{
fprintf(stderr, "Parsing failed\n");
return 1;
}


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

/*Free the dynamically allocated memory when done*/
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
