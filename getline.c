#include "monty.h"


/**
 * getline - reads an entire line from a stream
 * @lineptr: ....whatever
 * @stream: pffffttt
*/
ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
    size_t bytesRead = 0;
    ssize_t result;
    int ch;
    char *newptr;

    if (lineptr == NULL || n == NULL || stream == NULL) 
        return (-1);

    if (*lineptr == NULL || *n == 0)
    {
        *n = 128;
        *lineptr = (char *)malloc(*n);
        if (*lineptr == NULL)
            return (-1);
    }

    while (1) {
        ch = fgetc(stream);

        if (ch == EOF || ch == '\n') {
            (*lineptr)[bytesRead] = '\0';
            break;
        }

        (*lineptr)[bytesRead] = (char)ch;
        bytesRead++;

        if (bytesRead + 1 >= *n) {
            *n *= 2;
            newptr = (char *)realloc(*lineptr, *n);
            if (newptr == NULL) {
                free(*lineptr);
                *lineptr = NULL;
                return -1;
            }
            *lineptr = newptr;
        }
    }

    result = (ch == EOF && bytesRead == 0) ? -1 : (ssize_t)bytesRead;
    return (result);
}

