#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define READ_BUFSIZE 1024
#define DELIM " \t\r\n\v"


/* memory.c*/
void *_realloc(void *ptr, size_t oldsize, size_t newsize);
void _memcpy(void *new_ptr, void *ptr, size_t size);

/* _getline.c*/
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

/* parsing.c*/

char **tokenize(char *str, const char *delim);
int is_delimeter(const char *delimeters, char c);

#endif
