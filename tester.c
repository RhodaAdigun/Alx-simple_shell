#include "shell.h"

/*
 * print_list - prints all the elements of a sep_t list
 * @h: points to the first node of the linked list
 * Return: the number of items in the list
 */

size_t print_list(const sep_t *head)
{
	size_t count;
	const sep_t *ptr;

	ptr = head;
	for (count = 0; ptr != NULL; count++)
	{
		if (ptr->str != NULL)
			printf("[%d] %s\n", ptr->len, ptr->str);
		else
			printf("[0] (nil)\n");
		ptr = ptr->next;
	}
	return (count);
}
