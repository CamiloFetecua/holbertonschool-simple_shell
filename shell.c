#include "header.h"

int main(void) {
    char size_in[BUFFER_SIZE];
    char *newline_ptr;

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

        execute_command(size_in);
    }

    return EXIT_SUCCESS;
}

void display_prompt() {
    printf("👉 ");
}
