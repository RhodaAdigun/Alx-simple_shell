#include "shell.h"

/**
 * get_line - reads an entire line from stream
 * @lineptr: pointer to buffer containing text read from stream
 * @n: size of lineptr
 * @stream: stream to read from
 * Return: returns the no. of characters read on success
 * returns -1 on failure to read a line
 */

ssize_t get_line(char **lineptr, size_t *n , FILE *stream)
{
	int i;
	ssize_t input;
	char *buffer;
	char delim;
	(void) n;
	(void) stream;

	input = 0;

	buffer = malloc(sizeof(char) * READ_BUFSIZE);
	if (buffer == 0)
	{
		perror("Failed to allocate memory");
		return (-1);
	}

	for (delim = 'c'; delim != '\n';)
	{
		i = read(STDIN_FILENO, &delim, 1);
		if (i == -1 || (i == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (i == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= READ_BUFSIZE)
			buffer = _realloc(buffer, input, input + 1);
		buffer[input] = delim;
		input++;
	}
	
	buffer[input] = '\0';
	_strcpy(*lineptr, buffer);
	free(buffer);
  
	return (input);
}


/**
 * non_interactive - runs when the shell is in non-interactive mode
 * @argv: the second argument of the main function to read from
 * Return: file descriptor returned when open() was called
 * exits on failure
 */

int non_interactive(char **argv)
{
	int open_fd;

	open_fd = open(argv[1], O_RDONLY);
	if (open_fd == -1)
	{
		_print(argv[0], STDERR_FILENO);
		_print(": 0: ", STDERR_FILENO);
		_print(argv[1], STDERR_FILENO);
		_print(": not found\n",STDERR_FILENO);
		exit(98);
	}
	return (open_fd);
}

