#include "monty.h"
#include <string.h>

/**
 * putting a copy of this hereso I can come back to the realloc issue later.
*/
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

if (err_msg == NULL) {
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

int main(int argc, char *argv[])
{
 char **file_contents;
size_t i = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

file_contents = read_and_store_file(argv[1]);
    if (file_contents == NULL) {
        fprintf(stderr, "Failed to read and store the file\n");
        return 1;
    }

    for ( ; file_contents[i] != NULL; i++) {
        printf("Line %lu: %s\n", i + 1, file_contents[i]);
    }

    for (i = 0; file_contents[i] != NULL; i++) {
        free(file_contents[i]);
    }
    free(file_contents);

    return 0;
}

/*
*try to understand this alternative for the realloc function when you
* come back
*/
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10

typedef struct {
    void** data;
    size_t size;
    size_t capacity;
} DynamicArray;

DynamicArray* createDynamicArray() {
    DynamicArray* da = malloc(sizeof(DynamicArray));
    if (!da) {
        // Handle memory allocation failure
    }
    
    da->data = malloc(INITIAL_CAPACITY * sizeof(void*));
    if (!da->data) {
        free(da);
        // Handle memory allocation failure
    }

    da->size = 0;
    da->capacity = INITIAL_CAPACITY;
    return da;
}

void push(DynamicArray* da, void* element) {
    if (da->size == da->capacity) {
        // Expand the array
        da->capacity *= 2;
        da->data = realloc(da->data, da->capacity * sizeof(void*));
        if (!da->data) {
            // Handle memory allocation failure
        }
    }
    
    da->data[da->size] = element;
    da->size++;
}

void destroyDynamicArray(DynamicArray* da) {
    free(da->data);
    free(da);
}
