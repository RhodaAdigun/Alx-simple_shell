#include "main.h"

/**
 * bring_line - assigns the line var for get_line
 * @lineptr: Buffer that store the input str
 * @buffer: str that is been called to line
 * @n: size of line
 * @j: size of buffer
 */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j)
{

	if (*lineptr == NULL)
	{
		if  (j > BUFSIZE)
			*n = j;

		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else if (*n < j)
	{
		if (j > BUFSIZE)
			*n = j;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}


/**
 * get_line - reads an entire line from stream
 * @lineptr: pointer to buffer containing text read from stream
 * @n: size of lineptr
 * @stream: stream to read from
 * Return: returns the no. of characters read on success
 * returns -1 on failure to read a line
 */
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	int i;
  ssize_t input;
	ssize_t retval;
	char *buffer;
	char delim;
  
	input = 0;

	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == 0)
		return (-1);
  
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
		buffer[input] = t;
		input++;
	}
	buffer[input] = '\0';
	bring_line(lineptr, n, buffer, input);
  
	return (input);
}
