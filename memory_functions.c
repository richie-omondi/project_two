#include "shell.h"
/**
 * _calloc - Allocates memory for an array of a certain number
 * of elements each of an inputed byte size.
 * @nmem: The number of elements.
 * @size: The byte size of each array element.
 *
 * Return: If nmemb = 0, size = 0, or the function fails - NULL.
 * Otherwise - a pointer to the allocated memory.
 */
void *_calloc(unsigned int nmem, unsigned int size)
{
	void *mem;
	char *filler;
	unsigned int i;

	if (nmem == 0 || size == 0)
		return (NULL);

	mem = malloc(size * nmem);

	if (mem == NULL)
		return (NULL);

	filler = mem;

	for (i = 0; i < (size * nmem); i++)
		filler[i] = '\0';

	return (mem);
}
