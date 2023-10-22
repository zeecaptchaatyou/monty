#include "monty.h"

/**
 * read_and_store_file - reads a file and stores its content
 * @filename: pointer to filename to be read and opened
 * Return: pointer to array in which the file's contets are stored
*/
char **read_and_store_file(const char *filename)
{
char line[MAX_LINE_SIZE], **lines = NULL;
size_t line_count = 0;
FILE *file = fopen(filename, "r"); /*open the file in read mode*/

if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", filename);
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
return (lines);
}
