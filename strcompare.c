#include "shell.h"

/**
 * _strcompare - Compare strings
 * @string1: First string
 * @string2: Second string
 *
 * Return: The difference between the first non-matching character.
 */
int _strcompare(char *string1, char *string2)
{
	int j, k, i = 0;

	while (string1[i] != '\0' && string2[i] != '\0')
	{
		if (string1[i] != string2[i])
		{
			k = string1[i];
			j = string2[i];
			return (k - j);
		}
		i++;
	}
	if (string1[i] != '\0')
	{
		k = string1[i];
		return (k);
	}
	else
	{
		j = string2[i];
		return (-j);
	}
}

