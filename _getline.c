#include "header.h"

/**
 * enter - Handles newline character input
 * @string: String to be handled
 *
 * Return: Pointer to an empty string
 */
char *enter(char *string)
{
	free(string);
	return ("\0");
}
