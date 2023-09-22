#include "header.h"

/**
 * _getline - retrieve input from the user through the standard input
 * Return: the input on a buffer
 */
char *_getline()
{
	int x, red, bufsize = BUFSIZE;
	char c = 0, *buffer, *buf;

	buffer = malloc(bufsize);
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	for (x = 0; c != EOF && c != '\n'; x++)
	{
		fflush(stdin);
		red = read(STDIN_FILENO, &c, 1);
		if (red == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		buffer[x] = c;
		if (buffer[0] == '\n')
			return (enter(buffer));
		if (x >= bufsize)
		{
			buffer = realloc(buffer, (bufsize + 2));
			if (buffer == NULL)
			{
				free(buffer);
				return (NULL);
			}
		}
	}
	buffer[x] = '\0';
	buf = space(buffer);
	free(buffer);
	hashtag_handler(buf);
	return (buf);
}

/**
 * enter - manages input containing newline characters
 * @string: String to be handled
 * Return: Empty string
 */
char *enter(char *string)
{
	free(string);
	return ("\0");
}

/**
 * space - Alters the input string to eliminate leading white spaces
 * @str: Input to be modifies
 * Return: Returns the modified string
 */
char *space(char *str)
{
	int k, j = 0;
	char *buff;

	buff = malloc(sizeof(char) * (_strlen(str) + 1));
	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}
	for (k = 0; str[k] == ' '; k++)
		;
	for (; str[k + 1] != '\0'; k++)
	{
		buff[j] = str[k];
		j++;
	}
	buff[j] = '\0';
	if (buff[0] == '\0' || buff[0] == '#')
	{
		free(buff);
		return ("\0");
	}
	return (buff);
}

/**
 * hashtag_handler - eliminates all content following the '#' symbol
 * @buff: input buffer
 * Return: nothing
 */
void hashtag_handler(char *buff)
{
	int l;

	for (l = 0; buff[l] != '\0'; l++)
	{
		if (buff[l] == '#' && buff[l - 1] == ' ' && buff[l + 1] == ' ')
		{
			buff[l] = '\0';
		}
	}
}
