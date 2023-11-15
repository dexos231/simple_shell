#include "shell.h"

/**
 * handle_getline_error - Handles getline() error.
 * @input_line: A pointer to the input line.
 *
 * Return: void.
 */
void handle_getline_error(char *input_line)
{
	perror("getline");
	free(input_line);
	input_line = NULL;
	exit(EXIT_FAILURE);
}

