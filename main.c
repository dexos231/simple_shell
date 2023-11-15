#include "shell.h"

/**
 * main - Entry point for the shell program
 * @ac: argument count
 * @argv: argument param
 * Return: Returns 0 on success, or status of the non_interactive_mode
 */

int main(int ac, char **argv)
{
	size_t size_li = 0;
	char *line = NULL;
	int stat = 0;
	(void) ac;

	if (!isatty(0))
	{
		while (getline(&line, &size_li, stdin) != -1)
		{
			non_interact_mode(line, &stat, argv);
		}
		if (line)
		{
			free(line);
			line = NULL;
		}
		return (stat);
	}
	start_sh(argv);
	return (0);
}

/**
 * non_interact_mode - Executes shell commands in non_interactive_mode
 * @tok: The string containing commands separated by newline characters
 * @status: Pointer to an integer to store the exit status
 * @argv: argument param
 * Return: Returns exit status.
 */

void non_interact_mode(char *tok, int *status, char **argv)
{
	char **single_command;
	char *envp[] = {NULL};

	tok[strlen(tok) - 1] = '\0';
	single_command = tokenize_str(tok, " \t");
	if (single_command[0])
	{
		if (!_strcompare(single_command[0], "exit"))
		{
			if (single_command[1])
			{
				int custom_status = _aoti(single_command[1]);

				handle_exit_status(custom_status, single_command, &tok, status);
			}
			else
			{
				free(tok);
				free_array(single_command);
				exit(*status);
			}
		}
		else if (!_strcompare(single_command[0], "env"))
		{
			print_env_variables();
			*status = 0;
		}
		else
			execute_sh_cmd(single_command, envp, status, argv, 0);
	}
	free_array(single_command);
}

/**
 * tokenize_str - Splits a string into tokens
 * @string: The string to tokenize
 * @delim: The delimiters to use for tokenization
 *
 * Return: Returns result.
 */

char **tokenize_str(char *string, char *delim)
{
	int count = 0;
	char *token;
	char **result = malloc(20 * sizeof(char *));

	if (result == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	token = strtok(string, delim);
	while (token != NULL)
	{
		result[count] = _strduplication(token);
		count++;
		token = strtok(NULL, delim);
	}
	while (count < 20)
	{
		result[count] = NULL;
		count++;
	}

	return (result);
}

