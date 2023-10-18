#include "shell.h"

/**
 * bfree - pointer get free and NULLs the adress
 * @ptr: adress of the pointer to free
 *
 * Return: if freed 1, 0 otherwise.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

