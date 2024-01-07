#include "header.h"
#include <errno.h>

void execute_command(char *command) {
    pid_t pid, wpid;
    int status;

    pid = fork();

    if (pid == -1) {
        perror("Error fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {  /* Proceso hijo */
        char *argv[] = {NULL, NULL};
        argv[0] = command;

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
