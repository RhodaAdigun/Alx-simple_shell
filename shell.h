#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define READ_BUFSIZE 1024
#define DELIM " \t\r\n\v"


/* memory.c*/
void *_realloc(void *ptr, size_t oldsize, size_t newsize);
void _memcpy(void *new_ptr, void *ptr, size_t size);

/* _getline.c*/
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
int non_interactive(char **argv);
void sig_handler(int signum);

/* parsing.c*/
char **_strtok(char *str, const char *delim);
int is_delimeter(const char *delimeters, char c);
int tokenize(char *buffer);

/* string.c*/
int _print(char *var, int fd);
int _strlen(char *str);
int _putchar(char c);
char *_strcpy(char *dest, char *src);
int buf_len(char *buffer);

#endif

