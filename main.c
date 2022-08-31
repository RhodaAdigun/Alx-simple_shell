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
	ssize_t open_fd, read_fd;
	char *buffer;
	ssize_t line = 0;
	size_t len = READ_BUFSIZE;

	signal(SIGINT, sig_handler);
	buffer = malloc(sizeof(char) * len);

	if (argc > 1)
	{
		open_fd = non_interactive(argv);
		read_fd = read(open_fd, buffer, len);
		if (read_fd == -1)
			perror("Failed like butter");
		/*w = write(STDOUT_FILENO, buffer, read_fd);*/
	}

	while(line != -1)
	{
		if (isatty(STDIN_FILENO) && argc == 1)
		{
			_print("$ ", STDOUT_FILENO);
			fflush(stdout);

			line = get_line(&buffer, &len, stdin);
		}
		_print(buffer, STDOUT_FILENO);
		hsh(buffer,line);
		if (argc > 1)
			break;
	}
	free(buffer);
	close(open_fd);
	return(0);
}
