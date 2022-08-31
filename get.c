#include "shell.h"

int hsh(void)
{
	ssize_t num;
	size_t len = 50;
	char *prompt = malloc(len * sizeof(char));

	putchar('$');
	fflush(stdout);
	putchar(' ');
	fflush(stdout);

	num = get_line(&prompt, &len, stdin);

	printf("%s", prompt);
	printf("%ld\n", len);

	free(prompt);
	return(num);
}
