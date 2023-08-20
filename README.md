<h1 align ="center">Hell In A Shell 🔥</h1><br>
<p align="center">
<img src="https://iili.io/HgHDhDN.md.jpg" alt="Laptop on fire from Hell in a Shell!" border="0"></a>
</p>
<hr /> 

## Description

This repository contains the files to simulate a basic **Unix Shell** with its respective commands. It uses the `POSIX API` to implement many of the same functionalities of the first Ken Thompson's Shell and it's made to carry out the **0x16. C - Simple Shell** project at [ALX SE.](https://www.alxafrica.com/ "ALX Africa.")

The predominantly used system and function calls are `read`, `write`, `open`, `execve`, `exit`, `fflush`, `fork`, `free`, `malloc`, `getline`, `isatty`, `perror`, `strtok`, `wait`, and `waitpid`.

This simple shell is a Shell interface written in the `C` programming language that gives to the user a prompt `$` and executes a user-inputted command. The shell is used directly to interact with the Kernel that hosts the OS.

## General

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 14.04 LTS
- Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
- All your files should end with a new line
- A `README.md` file, at the root of the folder of the project is mandatory
- Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl "betty-style.pl") and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl "betty-doc.pl")
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded

## Main Features
* This program displays a prompt and waits for the user to type a command. A command line always ends with a new line (when the user pushes the *ENTER* key).
* The prompt is displayed again each time a command has been executed.
* When the user enters exit, the shell will end and returns the status 0.
* The user could stop the program using *Ctrl+D* (end of file).
* The shell handles the command lines with arguments and pathways.
* The program does not quit when the user inputs ^C (Ctrl+C).
* This program executes the most common shell commands as `ls`, `grep`, `find`, `pwd`, `rm`, `cp`, `mv`, `exit`, etc... with arguments.
* If an executable cannot be found, it prints an error message and displays the prompt again.
* This Shell does not support commentaries using `#`.
* This shell does not support pipes `|`, shell logical operators such as `&&` or `||`, neither commands separator `;`.

## Requirements

* Operating System: [Ubuntu 14.04 LTS](http://releases.ubuntu.com/14.04/)

* Compiler: [GCC 4.8.4](https://gcc.gnu.org/gcc-4.8/)


## Program Execution Workflow

The next steps are a brief description of how the shell works:

1. First, the parent process is created when the user runs the program.
2. Then, the `isatty()` function using the `STDIN_FILENO` file descriptor -`fd`- tests if there is an open file descriptor referring to a terminal. If `isatty()` returns 1, the prompt is shown using `write()` with `STDOUT_FILENO` as `fd` and waits for input from the user on the command line.
3. When the user types a command, the `getline()` function reads an entire line from the input stream, and `strtok()` function breaks the inputted command into a sequence of non-empty tokens.
4. Next, it creates a separate child process using `fork()` that performs the inputted command. Unless otherwise specified, the parent process waits for the child to exit before continuing.
5. After tokenizing the command, `execve()` executes it, and all allocated memory is freed using `free()`.
6. Finally, the program returns to `main()`, prints the prompt, and waits for another user input.


## Implementation

To run this shell with its respective commands, clone this repository in your terminal.
- HTTPS:

```c
git clone https://github.com/richie-omondi/simple_shell.git
```

- SSH:

```
git clone git@github.com:richie-omondi/simple_shell.git
```

## Compilation

```
gcc -Wall -Wextra -Werror -pedantic -ggdb3 *.c -o hsh
```
## Debugging

- If you want to **debug** the shell, use valgrind:
```
valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./hsh
```
More info on Valgrind can be found here: https://valgrind.org/

- Or just **run** and try this shell using:
```
./hsh
```
## Examples

Here are shown some examples of the usage of the Shell:

- ls

```shell
($) ls
add_shell_data.c  debugging.txt  errors.c         free.c  memory_functions.c  print.c    shell.c  string_functions_2.c  Tasks.md   tokenize.c
AUTHORS           env.c          execute_shell.c  hsh     Notes.md            README.md  shell.h  string_functions.c    test_ls_2
```

```shell
($) /bin/ls
add_shell_data.c  debugging.txt  errors.c         free.c  memory_functions.c  print.c    shell.c  string_functions_2.c  Tasks.md   tokenize.c
AUTHORS           env.c          execute_shell.c  hsh     Notes.md            README.md  shell.h  string_functions.c    test_ls_2
```

```shell
($) ls -lat
total 108
-rwxr-xr-x 1 root root 23184 Aug 20 07:06 hsh
drwxr-xr-x 3 root root  4096 Aug 20 07:06 .
drwxr-xr-x 8 root root   220 Aug 20 07:06 .git
-rw-r--r-- 1 root root  3957 Aug 20 07:06 README.md
-rw-r--r-- 1 root root  2051 Aug 13 14:20 shell.h
-rw-r--r-- 1 root root  2727 Aug 13 14:20 shell.c
-rw-r--r-- 1 root root  1252 Aug 13 14:16 free.c
-rw-r--r-- 1 root root  2955 Aug 13 07:45 tokenize.c
drwxr-xr-x 1 root root   170 Aug 12 13:49 ..
-rw-r--r-- 1 root root  1667 Aug  9 06:20 string_functions_2.c
-rw-r--r-- 1 root root    16 Aug  9 06:20 test_ls_2
-rw-r--r-- 1 root root   773 Aug  9 06:20 add_shell_data.c
-rw-r--r-- 1 root root    81 Aug  9 06:20 AUTHORS
-rw-r--r-- 1 root root    79 Aug  9 06:20 debugging.txt
-rw-r--r-- 1 root root   957 Aug  9 06:20 env.c
-rw-r--r-- 1 root root   951 Aug  9 06:20 errors.c
-rw-r--r-- 1 root root   862 Aug  9 06:20 execute_shell.c
-rw-r--r-- 1 root root   636 Aug  9 06:20 memory_functions.c
-rw-r--r-- 1 root root  8624 Aug  9 06:20 Notes.md
-rw-r--r-- 1 root root   272 Aug  9 06:20 print.c
-rw-r--r-- 1 root root  2224 Aug  9 06:20 string_functions.c
-rw-r--r-- 1 root root  1574 Aug  9 06:20 Tasks.md
```
- pwd

```shell
($) pwd
/simple_shell
```
- echo

```shell
($) echo Hello World
Hello World
```
- *Ctrl+D*  and  *Ctrl+C* 

```shell
($) ^C
($)
vagrant@vagrant-ubuntu-trusty-64:~/ALX/simple_shell$ 
```
Note that in the second line the *Ctrl+D*  is typed

## Authors:

- Richard Orido - [@richie-omondi](https://github.com/richie-omondi) 
- Maxmillan Rutto - [@Maxrutto](https://github.com/Maxrutto)
