#include "header.h"

/**
 * get_user_input - read input from standard input by the user
 * Return: the input in a buffer
 */
char *get_user_input(void)
{
	int i, buffer_size = 1024;
	char *input_buffer = (char *)malloc(buffer_size);

	if (input_buffer == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	for (i = 0; 1; i++)
	{
		int c = getchar();

		if (c == EOF || c == '\n')
		{
			input_buffer[i] = '\0';
			break;
		}

		input_buffer[i] = c;
		if (i >= buffer_size - 1)
		{
			buffer_size *= 2;
			input_buffer = (char *)realloc(input_buffer, buffer_size);
			if (input_buffer == NULL)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}
	}

	char *trimmed_input = remove_whitespace(input_buffer);
	free(input_buffer);
	remove_comments(trimmed_input);
	return trimmed_input;
}

/**
 * remove_whitespace - Modifies the input string to remove preceding whitespaces
 * @str: Input to be modified
 * Return: Returns the modified string
 */
char *remove_whitespace(char *str)
{
	int i = 0, j = 0;
	while (str[i] == ' ')
	{
		i++;
	}

	char *result_buffer = (char *)malloc(strlen(str) - i + 1);

	if (result_buffer == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	while (str[i] != '\0')
	{
		result_buffer[j] = str[i];
		i++;
		j++;
	}

	result_buffer[j] = '\0';
	return result_buffer;
}

/**
 * remove_comments - function that removes everything after '#'
 * @input: input buffer
 * Return: nothing
 */
void remove_comments(char *input)
{
	for (int i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == '#')
		{
			input[i] = '\0';
			break;
		}
	}
}

int main(void)
{
	char *user_input;
	while (1)
	{
		printf("Enter a line: ");
		user_input = get_user_input();
		printf("Processed input: \"%s\"\n", user_input);
		free(user_input);
	}
	return 0;
}

