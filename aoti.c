#include "shell.h"

/**
 * _aoti - Converts a string to an integer
 * @string:string
 * Return: 0 if no number or the number if exist
 */

int _aoti(char *string)
{
	int i = 0, neg = 0, exist = 0;
	unsigned int num = 0;

	for (i = 0; string[i] != '\0';)
	{
		if (string[i] == '-')
			neg++;
		while (string[i] >= 48 && string[i] <= 57)
		{
			exist = 1;
			num = (num * 10) + (string[i] - '0');
			i++;
		}
		if (exist)
			break;
		i++;
	}
	if (neg % 2 != 0)
		return (-num);
	return (num);
}

