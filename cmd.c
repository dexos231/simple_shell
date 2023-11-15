#include "shell.h"

/**
 * find_cmd_path - Searches for the full path of a command
 * in the PATH environment variable
 * @cmd: The command to search for
 * @cmd_path: Pointer to store the full path of the command
 *
 * Return: 1 if found, 0 if not found
 */
int find_cmd_path(char *cmd, char **cmd_path)
{
	char *token, *path_env;
	int found = 0;

	path_env = get_env_var("PATH");

	if (path_env != NULL)
	{
		char *path_env_copy = strdup(path_env);

		token = strtok(path_env_copy, ":");

		while (token != NULL && !found)
		{
			*cmd_path = malloc(strlen(token) + strlen(cmd) + 2);
			if (*cmd_path != NULL)
			{
				strcpy(*cmd_path, token);
				strcat(*cmd_path, "/");
				strcat(*cmd_path, cmd);

				if (access(*cmd_path, X_OK) == 0)
				{
					found = 1;
				}

				if (!found)
				{
					free(*cmd_path);
				}
			}

			token = strtok(NULL, ":");
		}

		free(path_env_copy);
	}

	return (found);
}


/**
 * exec_sh_cmd - Execute a shell command
 * and its arguments by searching in PATH
 * @cmd_arguments: The command and its arguments as an array of strings
 * @environ_vars: The environment variables
 * @exit_status: The pointer to an int where the exit status will be stored
 * @argv: program argument
 * @ind: execution count
 */

void execute_sh_cmd(char **cmd_arguments, char **environ_vars
		, int *exit_status, char **argv, int ind)
{
	char *cmd_path = NULL;
	int child_pid;

	if (access(cmd_arguments[0], X_OK) == 0)
	{
		child_pid = fork();

		if (child_pid == 0)
		{
			execve(cmd_arguments[0], cmd_arguments, environ_vars);
		}
		else
		{
			wait_ch_process(exit_status);
		}
	}
	else if (find_cmd_path(cmd_arguments[0], &cmd_path))
	{
		child_pid = fork();

		if (child_pid == 0)
		{
			execve(cmd_path, cmd_arguments, environ_vars);
		}
		else
		{
			wait_ch_process(exit_status);
		}

		free(cmd_path);
	}
	else
	{
		*exit_status = 127;
		write_err(argv[0], cmd_arguments[0], ind);
	}
}

/**
 * wait_ch_process - Waits for a child process to end
 * and gets its exit status
 * @exit_stat: Pointer to the exit status variable to store the exit status
 *
 * Return: void
 */

void wait_ch_process(int *exit_stat)
{
	int child_status;

	if (wait(&child_status) == -1)
	{
		perror("wait");
		exit(EXIT_FAILURE);
	}

	if (WIFEXITED(child_status))
	{
		*exit_stat = WEXITSTATUS(child_status);
	}
}

/**
 * get_env_var - Searches for an environment
 * variable and returns its value
 * @var: The name of the environment variable to search for
 *
 * Return: Pointer to the value of the environment variable,
 * or NULL if not found
 */

char *get_env_var(const char *var)
{
	int i;
	int name_length = _strlength((char *)var);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (!strncmp(var, environ[i], name_length))
		{
			if (environ[i][name_length] == '=')
			{
				return (environ[i] + name_length + 1);
			}
		}
	}

	return (NULL);
}



/**
 * print_env_variables - Prints the environment variables to stdout
 *
 * Return: void
 */
void print_env_variables(void)
{
	char **envir = environ;

	while (*envir != NULL)
	{
		write(STDOUT_FILENO, *envir, _strlength(*envir));
		write(STDOUT_FILENO, "\n", 1);
		envir++;
	}
}


