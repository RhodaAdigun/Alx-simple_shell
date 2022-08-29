#include "shell.h"

/**
 * _realloc - reallocates a new memory space
 * @ptr: the ptr to the previous memory block
 * @oldsize: the old size of memory
 * @newsize: the new size to be allocated
 * Return: a pointer to the newly allocated memory if successful
 * returns NULL if new_size = 0
 *
 */

void *_realloc(void *ptr, size_t oldsize, size_t newsize)
{
	void *new_ptr;

	if (!ptr)
		return (malloc(newsize));
	if (!newsize)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(newsize);

	if (newsize == oldsize)
		return (ptr);
	else if (newsize > oldsize)
		_memcpy(new_ptr, ptr, newsize);
	else
		_memcpy(new_ptr, ptr, oldsize);

	free(ptr);
	return (new_ptr);
}

/**
 * _memcpy - copies the content of a pointer to another
 * @ptr: the pointer to copy from
 * @new_ptr: the pointer to copy to
 * @size: the size of the pointer to copy to
 *
 */

void _memcpy(void *new_ptr, void *ptr, size_t size)
{
	unsigned int i;

	for (i = 0; i < size; i++)
		((char *)new_ptr)[i] = ((char *)ptr)[i];
}

