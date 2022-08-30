#include "shell.h"

/**
 * main - main function of hsh(shell)
 * @argc: no of arguments
 * @argv: arguments
 * Return: EXIT_FAILURE(1) ON failure 
 * returns EXIT_SUCCESS(0) on success
 */

int main(int argc, char **argv)
{
	int open_fd;

	if (argc > 1)
	{
		open_fd = non_interactive(argv);
		putchar(open_fd);
	}
	return(0);
}
