#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stddef.h>

#define BUFFER_SIZE 1024

void display_prompt(void);
void execute_command(char *command);

#endif 

