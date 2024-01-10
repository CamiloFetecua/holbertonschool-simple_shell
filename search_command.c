#include "header.h"
#include <unistd.h>

/**
 * search_and_execute_command - Searches for and executes a command in the PATH.
 * @command: The command to search for and execute.
 * This function searches for the specified command in the directories listed in
 * the PATH environment variable. If the command is found, it is executed.
 * If the command is not found, an error message is printed.
 * Return: void
 */
void search_and_execute_command(char *command) {
    char *path = getenv("PATH");
    int status;
    char full_path[BUFFER_SIZE];
    char *token;
    if (path == NULL) {
        perror("Error getting PATH");
        exit(EXIT_FAILURE);
    }
    token = strtok(path, ": ");
   while (token != NULL) {
        snprintf(full_path, sizeof(full_path), "%s/%s", token, command);

        if (access(full_path, F_OK) == 0) {
            /* Puedes ejecutar el comando aquí si es necesario*/
            pid_t pid = fork();
            if (pid == -1) {
                perror("Error fork");
                exit(EXIT_FAILURE);
            }
             if (pid == 0) {  /* Proceso hijo */
                /* Código del proceso hijo...*/
                exit(EXIT_SUCCESS);
            } else {  /* Proceso padre */
                waitpid(pid, &status, 0);
            }

            exit(EXIT_SUCCESS);
        }

        token = strtok(NULL, ":");
    }
    /* Si llegamos aquí, el comando no se encontró en ninguna ruta de PATH*/
    fprintf(stderr, "%s: command not found\n", command);
    exit(EXIT_FAILURE);
}


