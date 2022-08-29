#include "shell.h"

int main(void)
{
	/*char *prompt = NULL;*/
	size_t len = 50;
	char *prompt = malloc(len * sizeof(char));

	putchar('$');
	fflush(stdout);
	putchar(' ');
	fflush(stdout);

	ssize_t num = get_line(&prompt, &len, stdin);

	printf("%s", prompt);
	printf("%ld\n", len);

	free(prompt);
	return(num);
}
