#include "header.h"
#include <errno.h>

/**
 * main - Entry point for the simple shell program.
 * This function initializes the shell and handles user input.
 * Return: EXIT_SUCCESS upon successful completion.
 */
int main(void) {
    char size_in[BUFFER_SIZE];
    char *newline_ptr;
    pid_t pid;

    while (1) {
        display_prompt();

        if (fgets(size_in, BUFFER_SIZE, stdin) == NULL) {
            printf("\n");
            break;
        }

        newline_ptr = strchr(size_in, '\n');
        if (newline_ptr != NULL) {
            *newline_ptr = '\0';

            /* Ignorar líneas vacías */
            if (size_in[0] == '\0') {
                continue;
            }
        }

	/* Llamar a la función handle_command */
        if (handle_command(size_in)) {
            continue;  /* Si el comando fue manejado, continúa con el siguiente ciclo*/
        }

        pid = fork();

        if (pid == 0) {  /* Proceso hijo*/
            execute_command(size_in);
            exit(EXIT_SUCCESS);
        } else if (pid < 0) {
            perror("Error fork");
            exit(EXIT_FAILURE);
        } else {  /* Proceso padre*/
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return EXIT_SUCCESS;
}

/**
 * display_prompt - Displays the shell prompt.
 * This function takes no parameters.
 * Return: void
 */
void display_prompt() {
    printf("👉 ");
    fflush(stdout);
}
