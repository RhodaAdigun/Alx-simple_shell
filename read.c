#include "shell.h"

/**
 * readline - gets line and removes miscelleneous chars
 * @buffer: line read from stdin
 * @line: number of characters read by _getline
 * Return:
 */

int readline(char *buffer, ssize_t line)
{
	if (line > 0 || buffer != NULL)
	{
		remove_comment(buffer);
	}
	return(0);
}


/**
 * remove_comment - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 * Return: Always 0;
 */

void remove_comment(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
