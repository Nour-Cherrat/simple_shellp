#include "header.h"

/**
 * create_envi - Generates an array of environment variables
 * @envi: Array to store Enviroment Variables
 */

void create_envi(char **envi)
{
	int w;

	for (w = 0; environ[w]; w++)
		envi[w] = _strdup(environ[w]);
	envi[w] = NULL;
}

/**
 * free_env - Deallocates the memory used by the environment variables array
 * @env:  Array of Environment variables
 */
void free_env(char **env)
{
	int w;

	for (w = 0; env[w]; w++)
	{
		free(env[w]);
	}
}

