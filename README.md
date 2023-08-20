<h1 align ="center">Hell In A Shell 🔥</h1><br>
<p align="center">
<img src="https://iili.io/HgHDhDN.md.jpg" alt="Laptop on fire from Hell in a Shell!" border="0"></a>
</p>
<hr /> 

## Description

This repository contains the files to simulate a basic **Unix Shell** with its respective commands. It uses the `POSIX API` to implement many of the same functionalities of the first Ken Thompson's Shell and it's made to carry out the **0x16. C - Simple Shell** project at [ALX SE.](https://www.alxafrica.com/ "ALX Africa.")

The predominantly used system and function calls are `read`, `write`, `open`, `execve`, `exit`, `fflush`, `fork`, `free`, `malloc`, `getline`, `isatty`, `perror`, `strtok`, `wait`, and `waitpid`.

This simple shell is a Shell interface written in the `C` programming language that gives to the user a prompt `$` and executes a user-inputted command. The shell is used directly to interact with the Kernel that hosts the OS.

## General.

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 14.04 LTS
- Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
- All your files should end with a new line
- A `README.md` file, at the root of the folder of the project is mandatory
- Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl "betty-style.pl") and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl "betty-doc.pl")
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded

## Features:
* This program displays a prompt and waits for the user to type a command. A command line always ends with a new line (when the user pushes the *ENTER* key).
* The prompt is displayed again each time a command has been executed.
* When the user enters exit, *Hell shell* will end and returns the status 0.
* The user could stop the program using *Ctrl+D* (end of file).
* The shell handles the command lines with arguments and pathways.
* The program does not quit when the user inputs ^C (Ctrl+C).
* This program executes the most common shell commands as `ls`, `grep`, `find`, `pwd`, `rm`, `cp`, `mv`, `exit`, etc... with arguments.
* If an executable cannot be found, it prints an error message and displays the prompt again.
* This Shell does not support commentaries using `#`.
* This shell does not support pipes `|`, shell logical operators such as `&&` or `||`, neither commands separator `;`.

## Requirements:

* Operating System: [Ubuntu 14.04 LTS](http://releases.ubuntu.com/14.04/)

* Compiler: [GCC 4.8.4](https://gcc.gnu.org/gcc-4.8/)


## Process Description

The next steps are a brief description of how the shell works:

1. First, the parent process is created when the user runs the program.
2. Then, the `isatty()` function using the `STDIN_FILENO` file descriptor -`fd`- tests if there is an open file descriptor referring to a terminal. If `isatty()` returns 1, the prompt is shown using `write()` with `STDOUT_FILENO` as `fd` and waits for input from the user on the command line.
3. When the user types a command, the `getline()` function reads an entire line from the input stream, and `strtok()` function breaks the inputted command into a sequence of non-empty tokens.
4. Next, it creates a separate child process using `fork()` that performs the inputted command. Unless otherwise specified, the parent process waits for the child to exit before continuing.
5. After tokenizing the command, `execve()` executes it, and all allocated memory is freed using `free()`.
6. Finally, the program returns to `main()`, prints the prompt, and waits for another user input.


## Authors:

- Richard Orido - [@richie-omondi](https://github.com/richie-omondi) 
- Maxmillan Rutto - [@Maxrutto](https://github.com/Maxrutto)
