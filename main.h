#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void execute_cmd(char *command, char *argv[]);
pid_t create_child(void);

#endif
