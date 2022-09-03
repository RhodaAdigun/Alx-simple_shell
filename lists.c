#include "shell.h"
/**
 * add_node - Adds a new node at the beginning
 *            of a list_t list.
 * @head: A pointer to the head of the list_t list.
 * @str: The string to be added to the list_t list.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - the address of the new element.
 */

line_t *add_line_node(line_t **head, const char *str)
{
	line_t *new;
	char *dup_str;
	int len;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	dup_str = _strdup(str);
	if (dup_str == NULL)
	{
		free(new);
		return (NULL);
	}

	new->line = dup_str;
	new->next = *head;

	*head = new;

	return (new);
}

/**
 * add_node_end - Adds a new node at the end
 *                of a sep_t list.
 * @head: A pointer the head of the list_t list.
 * @str: The string to be added to the list_t list.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - the address of the new element.
 */

sep_t *add_sep_node(sep_t **head, const char *str, int index)
{
	char *dup;
	int len;
	list_t *new, *last;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	dup = _strdup(str);
	if (str == NULL)
	{
		free(new);
		return (NULL);
	}

	new->separator = dup;
	new->index = index
	new->next = NULL;

	if (*head == NULL)
		*head = new;

	else
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}

	return (*head);
}


/**
 * free_list - Frees a line_t list.
 * @head: A pointer to the line_t list.
 */

void free_line_list(line_t *head)
{
	line_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head->str);
		free(head);
		head = tmp;
	}
}
