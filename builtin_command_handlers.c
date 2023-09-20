#include "header.h"

/**
 * is_builtin - Checks if the parsed command is a built-in
 * @command: Parsed command to be checked
 * Return: 1 if it's a built-in, 0 otherwise
 */
int is_builtin(char **command)
{
    Builtin builtins[] = {
        {"cd", NULL},
        {"help", NULL},
        {"echo", NULL},
        {"env", NULL},
        {"history", NULL},
        {NULL, NULL}
    };
    int index = 0;

    if (*command == NULL)
    {
        return 0;
    }

    while (builtins[index].name)
    {
        if (_strcmp(command[0], builtins[index].name) == 0)
        {
            return 1;
        }
        index++;
    }

    return 0;
}

/**
 * execute_builtin - Executes predefined built-in commands
 * @command: Array of parsed command strings
 * @status: Status of last execution
 * Return: -1 on failure, 0 on success
 */
int execute_builtin(char **command, int status)
{
    Builtin builtins[] = {
        {"cd", change_directory},
        {"env", display_environment},
        {"help", display_help},
        {"echo", execute_echo},
        {"history", display_history},
        {NULL, NULL}
    };
    int index = 0;

    while (builtins[index].name)
    {
        if (_strcmp(command[0], builtins[index].name) == 0)
        {
            return (builtins[index].function(command, status));
        }
        index++;
    }

    return -1;
}

/**
 * exit_builtin - Handles exit status for built-in commands
 * @command: Array of parsed command strings
 * @input_str: Input received from the user (to be freed)
 * @argv_list: Arguments before program starts (argv[0] == Shell Program Name)
 * @execution_count: Shell execution count
 * @exit_status: Exit status
 */
void exit_builtin(char **command, char *input_str, char **argv_list, int execution_count, int exit_status)
{
    int status, i = 0;

    if (command[1] == NULL)
    {
        free(input_str);
        free(command);
        exit(exit_status);
    }

    while (command[1][i])
    {
        if (_isalpha(command[1][i++]) != 0)
        {
            print_error(argv_list, execution_count, command);
            free(input_str);
            free(command);
            exit(2);
        }
        else
        {
            status = _atoi(command[1]);
            if (status == 2)
            {
                print_error(argv_list, execution_count, command);
                free(input_str);
                free(command);
                exit(status);
            }
            free(input_str);
            free(command);
            exit(status);
        }
    }
}

