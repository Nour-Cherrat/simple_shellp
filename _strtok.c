#include "header.h"

/**
 * is_delimiter - checks if a character is a delimiter
 * @c: character to check
 * @delimiters: string of delimiters
 * Return: 1 if character is a delimiter, 0 otherwise
 */
unsigned int is_delimiter(char c, const char *delimiters)
{
    unsigned int i;

    for (i = 0; delimiters[i] != '\0'; i++)
    {
        if (c == delimiters[i])
            return 1;
    }
    return 0;
}

/**
 * custom_strtok - extracts tokens from a string
 * @str: string to tokenize
 * @delimiters: string of delimiters
 * Return: pointer to the next token or NULL
 */
char *custom_strtok(char *str, const char *delimiters)
{
    static char *tokens;
    static char *next_token;
    unsigned int i;

    if (str != NULL)
        next_token = str;
    tokens = next_token;

    if (tokens == NULL)
        return NULL;

    for (i = 0; tokens[i] != '\0'; i++)
    {
        if (is_delimiter(tokens[i], delimiters) == 0)
            break;
    }

    if (next_token[i] == '\0' || next_token[i] == '#')
    {
        next_token = NULL;
        return NULL;
    }

    tokens = next_token + i;
    next_token = tokens;

    for (i = 0; next_token[i] != '\0'; i++)
    {
        if (is_delimiter(next_token[i], delimiters) == 1)
            break;
    }

    if (next_token[i] == '\0')
        next_token = NULL;
    else
    {
        next_token[i] = '\0';
        next_token = next_token + i + 1;
        if (*next_token == '\0')
            next_token = NULL;
    }

    return tokens;
}

