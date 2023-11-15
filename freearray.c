#include "shell.h"
/**
 * free_array - Frees memory allocated for an array of strings.
 * @arr: A pointer to the dynamically allocated array of strings.
 *
 * This function frees the memory allocated for an array of strings.
 */
void free_array(char **arr)
{
	int i;

	if (!arr)
		return;
	for (i = 0; arr[i] != NULL; i++)
	{
		free(arr[i]);
	}
	free(arr);
}

