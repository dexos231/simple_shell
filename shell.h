#ifndef SHELL_H
#define SHELL_H

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<stddef.h>
#include<string.h>
#include<sys/wait.h>
#include <limits.h>

extern char **environ;

int _aoti(char *string);
int find_cmd_path(char *cmd, char **cmd_path);
void execute_sh_cmd(char **cmd_arguments, char **environ_vars
		, int *exit_status, char **argv, int ind);
void wait_ch_process(int *exit_stat);
char *get_env_var(const char *var);
void print_env_variables(void);
void handle_getline_error(char *input_line);
void handle_exit_status(int cstm_status, char **cmd_arguments, char **token,
		int *exit);
void handle_custom_exit(int cstm_status, char **cmd_arguments,
		char *input_ln, int *exit_stats);
void free_array(char **arr);
void non_interact_mode(char *tok, int *status, char **argv);
char **tokenize_str(char *string, char *delim);
void strreverse(char *str);
void num_to_string(int num, char *str);
void start_sh(char **argv);
ssize_t read_cmd(char **li, size_t *li_si);
void write_err(char *n, char *cmd, int ind);
void write_exit_err(char *num);
int _strcompare(char *string1, char *string2);
char *_strduplication(const char *string);
int _strlength(char *string);
int main(int ac, char **argv);


#endif
