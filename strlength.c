#include "shell.h"

/**
 * _strlength - returns the length of a string
 * @string: the string
 *
 * Return: length of the string.
 */
int _strlength(char *string)
{
	int length = 0;

	while (*string)
	{
		length++;
		string++;
	}

	return (length);
}


