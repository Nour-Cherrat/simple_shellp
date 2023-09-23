#ifndef HEADER_H
#define HEADER_H

#define PRINT(c) (write(STDERR_FILENO, c, _strlen(c)))
#define BUFSIZE 10240
#define DELIMITER " \t\r\n\a"
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
#include <stddef.h>

char *_strncpy(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);
void _puts(char *str);
int _strlen(char *s);
int _putchar(char c);
int _atoi(char *s);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void array_rev(char *arr, int len);
int intlen(int num);
char *_itoa(unsigned int n);
void treat_file(char *line, int count, FILE *fp, char **argv);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);
void free_env(char **env);
void hashtag_handler(char *buff);
void *fill_an_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void free_all(char **input, char *line);
char *_getline();
char *space(char *str);
char *enter(char *string);
void prompt(void);
unsigned int check_delim(char c, const char *str);
char *_strtok(char *str, const char *delim);
int history(char *input);
char **separator(char *input);
void read_file(char *file, char **argv);
void exit_bul_for_file(char **cmd, char *line, FILE *fd);
char **parse_cmd(char *input);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int handle_builtin(char **cmd, int er);
int check_cmd(char **cmd, char *input, int c, char **argv);
void signal_to_handle(int sig);
void print_error(char *input, int counter, char **argv);
void _prerror(char **argv, int c, char **cmd);
void error_file(char **argv, int c);
extern char **environ;
void print_number(unsigned int n);
void print_number_int(int n);
void help_setenv(void);
int print_echo(char **cmd);
int path_cmd(char **cmd);
char *build(char *token, char *value);
char *_getenv(char *name);
void help_env(void);
void help_unsetenv(void);
void help_history(void);
void help_all(void);
void help_alias(void);
void help_cd(void);
void help_exit(void);
int echo_bul(char **cmd, int st);
void help_help(void);
int display_help(char **cmd, __attribute__((unused))int st);
int check_builtin(char **cmd);
void create_envi(char **envi);
void free_env(char **env);
void exit_bul(char **cmd, char *input, char **argv, int c, int stat);
int change_dir(char **cmd, __attribute__((unused))int st);
int dis_env(__attribute__((unused)) char **cmd,
	    __attribute__((unused)) int st);
int history_dis(__attribute__((unused))char **c,
		__attribute__((unused)) int st);
int handle_builtin(char **cmd, int st);
/**
 * struct _builtin - Defineing a structure conatining built-in cmd with implementaion fcts
 * @command: - Built-in command
 * @function: - Pointer to custom functions that have
 */
typedef struct _builtin
{
	char *command;
	int (*function)(char **line, int st);
} builtin;

#endif /*HEADER_H*/
