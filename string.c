#include "shell.h"

/**
 * _strlen: returns the lenght of string passed to it
 * @str: the string to find the lenght of
 * Returns: NULL on failure, string lenght on sucess
 *
 */

int _strlen(char *str)
{
	int i;

	for (i = 0; str[i];)
		i++;
	return (i);
}

/**
 * _print - prints the content of the variable passed to it
 * @var: string to print
 * Return: string
 */

int _print(char *var, int fd)
{
	return (write(fd, var, _strlen(var)));
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _put - prints the content of the variable passed to it
 * @var: string to print
 * Return: string
 */

int _puts(char **var)
{
	return (write(fd, *var, _strlen(*var)));
}

/**
 * _strcpy - copies the content of a string to another
 * @dest: where to copy string to
 * @src: origin of the string
 * Return: a pointer to the destination string(dest)
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return(dest);
}
		
