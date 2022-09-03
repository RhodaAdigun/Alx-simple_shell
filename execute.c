#include "shell.h"

int hsh(char *buffer,ssize_t line, int argc)
{

	readline(buffer,line);
	return(0);
}
