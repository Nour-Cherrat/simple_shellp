#include "header.h"

/**
 * check_delim - Function that verifies whether a character matches any other character
 * @c: character to check
 * @str: string of delimiters
 * Return: 1 on success, 0 on failure
 */
unsigned int check_delim(char c, const char *str)
{
	unsigned int m;

	for (i = 0; str[m] != '\0'; m++)
	{
		if (c == str[m])
			return (1);
	}
	return (0);
}

/**
 * _strtok - Function that retrieves tokens from a string
 * @str: string
 * @delim: delimiter
 * Return: pointer to the next token or NULL
 */
char *_strtok(char *str, const char *delim)
{
	static char *tokens;
	static char *new_token;
	unsigned int u;

	if (str != NULL)
		new_token = str;
	tokens = new_token;
	if (tokens == NULL)
		return (NULL);
	for (u = 0; tokens[u] != '\0'; u++)
	{
		if (check_delim(tokens[u], delim) == 0)
			break;
	}
	if (new_token[u] == '\0' || new_token[u] == '#')
	{
		new_token = NULL;
		return (NULL);
	}
	tokens = new_token + u;
	new_token = tokens;
	for (u = 0; new_token[u] != '\0'; u++)
	u
		if (check_delim(new_token[u], delim) == 1)
			break;
	}
	if (new_token[u] == '\0')
		new_token = NULL;
	else
	{
		new_token[u] = '\0';
		new_token = new_token + u + 1;
		if (*new_token == '\0')
			new_token = NULL;
	}
	return (tokens);
}

