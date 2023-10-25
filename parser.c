#include "monty.h"

/**
 * strtow - your typical strtow string
 * @str: string to seperate into words
 * @delims: string delimeters
 * Return: 2D array of pointers to each word
 */
char **strtow(char *str, char *delims)
{
char **words = NULL;
int word_count, word_len, j, i = 0;

if (str == NULL || !*str)
return (NULL);
word_count = get_word_count(str, delims);


if (word_count == 0)
return (NULL);
words = malloc((word_count + 1) * sizeof(char *));
if (words == NULL)
return (NULL);
while (i < word_count)
{
word_len = get_word_length(str, delims);
if (is_delim(*str, delims))
str = get_next_word(str, delims);

words[i] = malloc((word_len + 1) * sizeof(char));
if (words[i] == NULL)
{
while (i >= 0)
{
i--;
free(words[i]); }
free(words);
return (NULL);
}
j = 0;
while (j < word_len)
{
words[i][j] = *(str + j);
j++; }
words[i][j] = '\0';
str = get_next_word(str, delims);
i++; }
words[i] = NULL;
return (words); }


/**
 * is_delim - checks if a chracter is contained in a delimeter string
 * @ch: character in stream
 * @delims: Pointer to null terminated array of delimitors
 * Return: 1 (success) 0 (failure)
 */

int is_delim(char ch, char *delims)
{
int i = 0;

while (delims[i])
{
if (delims[i] == ch)
return (1);
i++;
}
return (0);
}

/**
 * get_word_length - gets the word length of cur word in str
 *
 * @str: string to get word length from current word
 * @delims: delimitors to use to delimit words
 *
 * Return: word length of current word
 */

int get_word_length(char *str, char *delims)
{
int wLen = 0, pending = 1, i = 0;

while (*(str + i))
{
if (is_delim(str[i], delims))
pending = 1;
else if (pending)
wLen++;

if (wLen > 0 && is_delim(str[i], delims))
break;
i++; }
return (wLen);
}

/**
 * get_word_count - gets the word count of a string
 *
 * @str: string to get word count from
 * @delims: delimitors to use to delimit words
 *
 * Return: the word count of the string
 */

int get_word_count(char *str, char *delims)
{
int word_count = 0, pending = 1, i = 0;

while (*(str + i))
{
if (is_delim(str[i], delims))
pending = 1;
else if (pending)
{
pending = 0;
word_count++;
}
i++;
}
return (word_count);
}

/**
 * get_next_word - gets the next word in a string
 *
 * @str: string to get next word from
 * @delims: delimitors to use to delimit words
 *
 * Return: pointer to first char of next word
 */

char *get_next_word(char *str, char *delims)
{
int pending = 0, i = 0;

while (*(str + i))
{
if (is_delim(str[i], delims))
pending = 1;
else if (pending)
break;
i++;
}
return (str + i);
}
