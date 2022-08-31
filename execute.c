#include "shell.h"

int hsh(char *buffer,ssize_t line)
{
	char **tok;
	int i;

	readline(buffer,line);
	tok = _strtok(buffer, DELIM);
	for(i = 0; tok[i]; i++)
		puts(tok[i]);
	return(0);
}
