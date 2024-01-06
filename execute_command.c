#include "header.h"

void execute_command(char *command) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {  /* Proceso hijo */
        char **argv = malloc(2 * sizeof(char *));
        if (argv == NULL) {
            perror("Error");
            exit(EXIT_FAILURE);
        }
        
        argv[0] = command;
        argv[1] = NULL;

        if (execvp(argv[0], argv) == -1) {
            perror("Error");
            free(argv);  /* Liberar la memoria en caso de error*/
            exit(EXIT_FAILURE);
        }
        free(argv);  /*Liberar la memoria después de execvp (si se ejecuta correctamente)*/
    } else if (pid < 0) {
        perror("Error");
    } else {  /* Proceso padre */
        waitpid(pid, &status, 0);  /*Esperar al proceso hijo*/
    }
}
