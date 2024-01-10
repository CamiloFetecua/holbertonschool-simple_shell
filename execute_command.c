#include "header.h"
#include <errno.h>

void execute_command(char *command) {
    pid_t pid, wpid;
    char *argv[BUFFER_SIZE];  /* Usamos un array para almacenar los argumentos */
    int argc = 0;
    int status;
    char *token;

    /* Dividimos la línea de comandos en tokens */
    token = strtok(command, " ");
    while (token != NULL) {
        argv[argc++] = token;
        token = strtok(NULL, " ");
    }

    argv[argc] = NULL;  /* Añadimos NULL al final del array para indicar el fin de los argumentos */

    pid = fork();

    if (pid == -1) {
        perror("Error fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {  /* Proceso hijo */
        if (execvp(argv[0], argv) == -1) {
            perror("Error");
            exit(EXIT_FAILURE);
        }
    } else {  /* Proceso padre */
        do {
            wpid = waitpid(pid, &status, 0);
        } while (wpid == -1 && errno == EINTR);
    }
}
