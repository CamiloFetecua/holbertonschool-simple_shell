# Simple Shell (hsh)

## Description
The Simple Shell (hsh) is a basic command-line interpreter implemented in C for Unix/Linux operating systems. It provides a minimalistic shell environment that allows users to execute operating system commands.

## Features
* Executes standard operating system commands.
* Implements parent and child processes for command execution.
* Basic error handling for improved reliability.

## Requirements
* C Compiler (e.g., GCC)
* Unix/Linux Operating System

## Compilation Instructions
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## Usage
```bash
./hsh
```

## Testing
### Interactive Mode
```bash
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
### Non-Interactive Mode
```bash
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
### Error Handling
```bash
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```
## Known Issues
Currently, there are no known issues or limitations with the Simple Shell.

## Collaborators
* [Camilo Fetecua](https://github.com/CamiloFetecua)
* [Manuela Marin](https://github.com/Manuela220704)
