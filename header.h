#ifndef HEADER_H
#define HEADER_H


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

char *get_user_input(void);
char *remove_whitespace(char *str);
void remove_comments(char *input);
int main(void);
unsigned int is_delimiter(char c, const char *delimiters);
char *custom_strtok(char *str, const char *delimiters);
int change_directory(char **cmd, __attribute__((unused)) int status);
int display_environment(__attribute__((unused)) char **cmd, __attribute__((unused)) int status);
int execute_echo(char **cmd, int status);
int display_history(__attribute__((unused)) char **cmd, __attribute__((unused)) int status);
int is_builtin(char **command);
int execute_builtin(char **command, int status);
void exit_builtin(char **command, char *input_str, char **argv_list, int execution_count, int exit_status);
void display_all_help(void);
void display_alias_help(void);
void display_cd_help(void);
void display_exit_help(void);
void display_help_help(void);





#define PRINT(c) (write(STDERR_FILENO, c, _strlen(c)))
#define BUFSIZE 10240
#define DELIMITER " \t\r\n\a"


#endif /*HEADER_H*/

