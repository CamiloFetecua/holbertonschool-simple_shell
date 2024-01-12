#include "header.h"

/**
 * main - Entry point of the program.
 * @ac: The number of parameters passed to the executable file. In the case
 * this variable will not be used.
 * @av: The name of the program.
 * Return: Always 0.
 */
int main(__attribute__((unused)) int ac, char **av)
{
	char *line;
	size_t size;
<<<<<<< HEAD
	int command_counter = 0;

	signal(SIGINT, SIG_IGN);
	do {
		command_counter++;	
=======
	int command_counter;

	command_counter = 0;
	signal(SIGINT, SIG_IGN);
	do {
		command_counter++;
>>>>>>> bb971df6ee3278a712d17adb697d47d38e863378
		line = NULL;
		size = 0;
		parse_line(line, size, command_counter, av);

	} while (1);

	return (0);
}
