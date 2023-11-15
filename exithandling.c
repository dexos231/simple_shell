#include "shell.h"

/**
 * handle_exit_status - Handles the exit status for a command.
 * @cstm_status: The status to check.
 * @cmd_arguments: The command arguments.
 * @token: A pointer to dynamically allocated memory.
 * @exit_status: A pointer to an int to hold the exit status value.
 *
 * Return: void.
 */

void handle_exit_status(int cstm_status, char **cmd_arguments, char **token,
		int *exit_status)
{
	if (cstm_status == -1 ||
		(cstm_status == 0 && cmd_arguments[1][0] != '0') ||
		cstm_status < 0)
	{
		write_exit_err(cmd_arguments[1]);
		*exit_status = 2;
	}
	else
	{
		free(*token);
		free_array(cmd_arguments);
		exit(cstm_status);
	}
}

/**
 * handle_custom_exit - Handles custom exit statuses for a command.
 * @cstm_status: The exit status to check.
 * @cmd_arguments: The array containing the command and its arguments.
 * @input_ln: A pointer to the input line.
 * @exit_stats: A pointer to an int to hold the return exit status value.
 *
 * Return: void.
 */

void handle_custom_exit(int cstm_status, char **cmd_arguments,
		char *input_ln, int *exit_stats)
{
	if (cstm_status == -1 ||
		(cstm_status == 0 && cmd_arguments[1][0] != '0') ||
		cstm_status < 0)
	{
		write_exit_err(cmd_arguments[1]);
		*exit_stats = 2;
	}
	else
	{
		free(input_ln);
		free_array(cmd_arguments);
		exit(cstm_status);
	}
}

