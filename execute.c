#include "shell.h"

int hsh(char *buffer,ssize_t line)
{

	readline(buffer,line);
	return(0);
}
