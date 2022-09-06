#include "shell.h"

/**
 * readline - gets line and removes miscelleneous chars
 * @buffer: line read from stdin
 * @line: number of characters read by _getline
 * Return:
 */

int readline(char *buffer, ssize_t line)
{
	char **tok;
	line_t *head;

	head = NULL;

	if (line > 0 || buffer != NULL)
	{
		remove_comment(buffer);
	}
	

	tok = _strtok(buffer, "\n");
		while(tok != NULL)
		{
			add_line_node(&head, *tok);
		}
	print_list(head);
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


