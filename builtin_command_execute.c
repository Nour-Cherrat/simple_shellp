#include "header.h"

/**
 * change_directory - Changes the current working directory
 * @cmd: Parsed command
 * @status: Status of the last command executed
 * Return: 0 on success, 1 if failed (Always 0 if no OLDPWD)
 */
int change_directory(char **cmd, __attribute__((unused)) int status)
{
	int result = -1;
	char current_directory[PATH_MAX];

	if (cmd[1] == NULL)
		result = chdir(getenv("HOME"));
	else if (_strcmp(cmd[1], "-") == 0)
	{
		result = chdir(getenv("OLDPWD"));
	}
	else
		result = chdir(cmd[1]);

	if (result == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (result != -1)
	{
		getcwd(current_directory, sizeof(current_directory));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", current_directory, 1);
	}
	return (0);
}

/**
 * display_environment - Display environment variables
 * @cmd: Parsed command
 * @status: Status of the last command executed
 * Return: Always 0
 */
int display_environment(__attribute__((unused)) char **cmd, __attribute__((unused)) int status)
{
	size_t i;
	int length;

	for (i = 0; environ[i] != NULL; i++)
	{
		length = _strlen(environ[i]);
		write(1, environ[i], length);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * execute_echo - Execute echo command with special cases
 * @status: Status of the last command executed
 * @cmd: Parsed command
 * Return: Always 1 or execute normal echo
 */
int execute_echo(char **cmd, int status)
{
	char *path;
	unsigned int parent_pid = getppid();

	if (_strncmp(cmd[1], "$?", 2) == 0)
	{
		print_number_int(status);
		PRINT("\n");
	}
	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		print_number(parent_pid);
		PRINT("\n");
	}
	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		PRINT(path);
		PRINT("\n");
		free(path);
	}
	else
		return (print_normal_echo(cmd));

	return (1);
}

/**
 * display_history - Display history of user input in the simple shell
 * @cmd: Parsed command
 * @status: Status of the last command executed
 * Return: 0 on success, -1 if fail
 */
int display_history(__attribute__((unused)) char **cmd, __attribute__((unused)) int status)
{
	char *filename = ".simple_shell_history";
	FILE *file_ptr;
	char *line = NULL;
	size_t length = 0;
	int counter = 0;
	char *error_msg;

	file_ptr = fopen(filename, "r");
	if (file_ptr == NULL)
	{
		return (-1);
	}
	while ((getline(&line, &length, file_ptr)) != -1)
	{
		counter++;
		error_msg = _itoa(counter);
		PRINT(error_msg);
		free(error_msg);
		PRINT(" ");
		PRINT(line);
	}
	if (line)
		free(line);
	fclose(file_ptr);
	return (0);
}

