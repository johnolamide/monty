#include "monty.h"

/**
 * strtow - separate the words from strings
 * @str: string
 * @delims: delimiter
 * Return: 2D array of pointers to each word
 */
char **strtow(char *str, char *delims)
{
	char **words = NULL;
	int wc, wordlen, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = get_word_count(str, delims);

	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (i < wc)
	{
		wordlen = get_word_length(str, delims);
		if (is_delim(*str, delims))
			str = get_next_word(str, delims);
		words[i] = malloc((wordlen + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordlen)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0';
		str = get_next_word(str, delims);
		i++;
	}
	words[i] = NULL;
	return (words);
}

/**
 * is_delim - checks if stream has delimiter char
 * @ch: character in stream
 * @delims: pointer to null terminate array of delimiters
 * Return: 1 for SUCCESS, 0 for FAILURE
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
 * get_word_length - gets the word length of current word in str
 * @str: string
 * @delims: delimiter
 * Return: word length of current word
 */
int get_word_length(char *str, char *delims)
{
	int wlen = 0, pending = 1, i = 0;

	while (*(str + 1))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
			wlen++;
		if (wlen > 0 && is_delim(str[i], delims))
			break;
		i++;
	}
	return (wlen);
}

/**
 * get_word_count - gets the word count of a string
 * @str: string
 * @delims: delimiter
 * Return: the word count of the string
 */
int get_word_count(char *str, char *delims)
{
	int wc = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		i++;
	}
	return (wc);
}

/**
 * get_next_word - get the next word
 * @str: string
 * @delims: delimiter
 * Return: pointer too first char of next word
 */
char *get_next_word(char *str, char *delims)
{
	int pending = 0;
	int i = 0;

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
