#include "monty.h"

int main(int argc, char **argv)
{
char **file_contents;
size_t i = 0;
if (argc != 2)
{
exit(2);
}

file_contents = read_and_store_file(argv[1]);

if (file_contents == NULL)
{
return (1);
}

for ( ; file_contents[i] != NULL; i++)
{
printf("Line %lu: %s\n", i + 1, file_contents[i]);
free(file_contents[i]);
}

free(file_contents);
return (0);
}
