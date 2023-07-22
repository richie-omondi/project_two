#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
#define DELIMITERS " \t\r\n\a"

extern char **environ;

/******* Structs **********/

/**
 * struct data - struct for data fed to the shell
 * @exe: executable file
 * @input: pointer to the input
 * @command: pointer to a command typed by the user
 * @fd: file descriptor
 * @tokens: tokenized input
 * @env: environ
 */
typedef struct data
{
	char *exe;
	char *input;
	char *command;
	char **tokens;
	char *path;
	char **env;
	int fd;
} shell_data;

/****** Prototypes *****/
void shell_loop(shell_data *shell);
char *read_input(shell_data *shell);
char **split_input(shell_data *shell);
char **tokenize_path(shell_data *shell);
int check_file(char *path);
char *get_env_value(char *env_variable, shell_data *shell);
int find_executable(shell_data *shell);
int execute_commands(shell_data *shell);
void add_data_to_shell(shell_data *shell, int ac, char *av[], char **env);

/******* Print functions ********/
int print_string(char *s);

/****** Memory functions *******/
void *_calloc(unsigned int nmem, unsigned int size);
void free_shell_data(shell_data *shell);

/******** String functions *******/
int str_len(char *string);
char *str_dup(char *string);
char *str_cpy(char *dest, const char *src);
char *str_cat(char *str1, char *str2);
int _strncmp(char *str1, char *str2, size_t n);

#endif
