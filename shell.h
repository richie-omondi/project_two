#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
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

/****** Prototypes *****/
void shell_loop(void);
char *read_input(void);
char **split_input(char *input);
int execute_commands(char **args);

/******* Print functions ********/
int print_string(char *s);

/******** String functions *******/
int str_len(char *string);

#endif
