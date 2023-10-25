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
