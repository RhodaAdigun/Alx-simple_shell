#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>

#define READ_BUFSIZE 1024

/* memory.c*/
void *_realloc(void *ptr, size_t oldsize, size_t newsize);
void _memcpy(void *new_ptr, void *ptr, size_t size);

/* _getline.c*/
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

#endif
