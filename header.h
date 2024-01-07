#ifndef HEADER_H
#define HEADER_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <signal.h>



#define BUFFER_SIZE 1024

void display_prompt(void);
void execute_command(char *command);

#endif
