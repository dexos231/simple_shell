#include "shell.h"

/**
 * _strduplication - returns a pointer to a newly allocated space in memory,
 * @string: the source string
 * Return: returns a pointer to the copy string.
 */
char *_strduplication(const char *string)
{
	char *duplic;
	int i, length;

	if (string == NULL)
		return (NULL);

	for (length = 0; string[length] != '\0'; length++)
	{
	}

	duplic = (char *)malloc((sizeof(char) * length) + 1);
	if (duplic == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
		duplic[i] = string[i];
	duplic[length] = '\0';

	return (duplic);
}


