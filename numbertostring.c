#include "shell.h"

/**
 * strreverse - reverses a string.
 *
 * @str: pointer to string.
 * Return: void.
 */

void strreverse(char *str)
{

	int i = 0, length = _strlength(str) - 1;
	char hold;

	while (i < length)
	{
		hold = str[i];
		str[i++] = str[length];
		str[length--] = hold;
	}
}

/**
 * num_to_string - converts a number to a string.
 * @num: number to be converten in an string.
 * @str: the return string
 * Return: the number as string.
 */
void num_to_string(int num, char *str)
{
	int index = 0, inNegative = 0;
	long cociente = num;
	char letters[] = {"0123456789"};

	if (cociente == 0)
		str[index++] = '0';

	if (str[0] == '-')
		inNegative = 1;

	while (cociente)
	{
		if (cociente < 0)
			str[index++] = letters[-(cociente % 10)];
		else
			str[index++] = letters[cociente % 10];
		cociente /= 10;
	}
	if (inNegative)
		str[index++] = '-';

	str[index] = '\0';
	strreverse(str);
}

