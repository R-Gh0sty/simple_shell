#include "shell.h"

/**
 * bfree - Frees a pointer and NULLs the address
 * @ptr: Address of the pointer to free
 *
 * This function frees the memory pointed to by the given pointer and then
 * sets the pointer itself to NULL. It's a safe way to free dynamically
 * allocated memory and avoid using a dangling pointer.
 *
 * Return: 1 if the memory was freed, otherwise 0.
 */
int bfree(void **ptr)
{
    if (ptr && *ptr)
    {
        free(*ptr);  // Free the memory
        *ptr = NULL; // Set the pointer to NULL
        return 1;    // Return 1 to indicate success
    }
    return 0; // Return 0 if the pointer was already NULL or invalid
}

