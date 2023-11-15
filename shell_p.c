#include "shell.h"

/**
 * start_sh - Starts the shell's main loop
 * @argv: program argument
 * Description: Initializes the shell, handles user input,
 * tokenizes commands, and executes them.
 */

void start_sh(char **argv)
{
	char *line = NULL, **commands, *envp[] = {NULL};
	size_t line_size = 0;
	ssize_t nread;
	int status = 0, count = 0;

	while (++count)
	{
		nread = read_cmd(&line, &line_size);
		if (nread == -1)
			handle_getline_error(line);
		commands = tokenize_str(line, " \n\t");
		if (commands[0])
		{
			if (!_strcompare(commands[0], "exit"))
			{
				if (commands[1])
				{
					int custom_status = _aoti(commands[1]);

					handle_custom_exit(custom_status, commands, line, &status);
				}
				else
				{
					free(line);
					free_array(commands);
					exit(status);
				}
			}
			else if (!_strcompare(commands[0], "env"))
			{
				print_env_variables();
				status = 0;
			}
			else
				execute_sh_cmd(commands, envp, &status, argv, count);
		}
		free_array(commands);
		free(line);
		line = NULL;
	}
}

/**
 * read_cmd - Reads a line of command from the user
 * @li: The line buffer to store the command
 * @li_si: The size of the line buffer
 *
 * Return: Returns the number of characters read.
 */
ssize_t read_cmd(char **li, size_t *li_si)
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);
	return (getline(li, li_si, stdin));
}


/**
 * write_err - Writes an error message to STDERR
 * @ind: execution count
 * @n: error name
 * @cmd: command
 * Description: Writes an error message
 */

void write_err(char *n, char *cmd, int ind)
{
	char i[10] = {'\0'};

	if (ind == 0)
		ind = 1;
	num_to_string(ind, i);

	write(STDERR_FILENO, n, _strlength(n));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, i, _strlength(i));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlength(cmd));
	write(STDERR_FILENO, ": not found\n", 12);
}

/**
 * write_exit_err - Writes an error message to STDERR
 *
 * @num: number
 * Description: Writes an error message
 */
void write_exit_err(char *num)
{
	write(STDERR_FILENO, "./hsh: 1: exit: Illegal number: ", 32);
	write(STDERR_FILENO, num, _strlength(num));
	write(STDERR_FILENO, "\n", 1);
}

