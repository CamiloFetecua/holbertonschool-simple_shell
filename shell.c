#include "header.h"
#include <errno.h>

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

void display_prompt() {
    printf("👉 ");
    fflush(stdout);
}
