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
	static ssize_t input;
	char *buffer;
	char delim;
	(void) n;

	if (input == 0)
		fflush(stream);
  
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
	strcpy(*lineptr, buffer);
	free(buffer);
  
	return (input);
}
