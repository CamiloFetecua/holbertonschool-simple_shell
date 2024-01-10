#include "header.h"

extern char **environ;

/**
 * handle_exit - Handles the 'exit' shell command by printing a message and exiting the shell.
 * This function takes no parameters.
 * Return: void
 */
void handle_exit() {
    printf("Exiting shell...\n");
    exit(EXIT_SUCCESS);
}

/**
 * handle_env - Handles the 'env' shell command by printing current environment variables.
 * This function takes no parameters.
 * Return: void
 */

void handle_env() {
    char **env_var = environ;
    while (*env_var) {
        printf("%s\n", *env_var);
        env_var++;
    }
}

/**
 * handle_command - Handles various shell commands.
 * @command: The command to handle.
 * Return: 1 if the command was handled, 0 otherwise.
 */
int handle_command(const char *command) {
    if (strcmp(command, "exit") == 0) {
        handle_exit();
        return 1; /* Indica que el comando fue manejado */
    } else if (strcmp(command, "env") == 0) {
        handle_env();
        return 1;  /*Indica que el comando fue manejado */
    }

    return 0;  /*Indica que el comando no fue manejado */
}
