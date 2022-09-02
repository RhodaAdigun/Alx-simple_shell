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
#define SEP_DELIM "&|;"

extern char **environ;


/**
 * struct sep_list_s - single linked list for command lines
 * @separator: ; | &
 * @index: the index of where the separator was found
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct sep_s
{
	char separator;
        int index;
	struct sep_s *next;
} sep_t;


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
char **tokenize(char *buffer);

/* string.c*/
int _print(char *var, int fd);
int _puts(char **var);
int _strlen(char *str);
int _putchar(char c);
char *_strcpy(char *dest, char *src);

/* read.c*/
int readline(char *buffer, ssize_t line);
void remove_comment(char *buf);

/* execute.c*/
int hsh(char *buffer,ssize_t line);

#endif

