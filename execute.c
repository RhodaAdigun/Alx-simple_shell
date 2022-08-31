#include "shell.h"

int hsh(char *buffer,ssize_t line)
{
	int tok;

	readline(buffer,line);
	tok = tokenize(buffer);
	return(tok);
}
