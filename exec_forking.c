#include "shell.h"
/* BY CHARIFA MASBAHI & NORA JEOUT*/
/* BY CHARIFA MASBAHI & NORA JEOUT*/
/**
 * comment - executes a command using the fork-exec
 * @s: ------------------
 * Return: err code
 */
char **comment(char **s)
{
	int i = 0;

	while (s[i] != NULL)
	{
		if (s[i][0] == '#')
		{
			free(s[i]);
			s[i] = NULL;
			return (s);
		}
		i++;
	}
	return (s);
}
/**
 * exec_forking - executes a command using the fork-exec
 * @arr_words: arr containing commands
 * @prompt: user prompt
 * @name: program name
 * @cnt: cmonad count
 * @n: ------------------
 * Return: err code
 */
int exec_forking(char **arr_words, char *prompt, char *name, int cnt, int n)
{
	char *cmd = NULL, *cmd_to_exec = NULL, *curr_cnt = NULL;
	pid_t pid;
	int curr_status, ex_code = 0;

	if (arr_words)
	{
		arr_words = comment(arr_words);
		if (arr_words == NULL || arr_words[0] == NULL)
			return (0);
		cmd = arr_words[0];
		if (_strcmp(cmd, "/bin/ls") == 0)
		{
			exec_binLs(arr_words);
			return (0);
		}
		if (handle_multi_cmds(arr_words, prompt, name, cnt, n) == 1)
			return (0);
		cmd_to_exec = get_path(cmd);
		if (!cmd_to_exec)
		{
			curr_cnt = intToString(cnt);
			if (!is_valid(cmd))
				p_the_err(curr_cnt, name, NULL, "not found\n");
			else
				p_the_err(curr_cnt, name, cmd, "not found\n");
			free(curr_cnt);
			return (127);
		}
		pid = fork();
		if (pid == 0)
			cmd_execve(cmd_to_exec, arr_words);
		else if (pid < 0)
			return (errno);
		wait_kid_process(pid, &curr_status);
		if (WIFEXITED(curr_status))
			ex_code = (WEXITSTATUS(curr_status));
	}
	if (arr_words && (cmd_to_exec != arr_words[0]))
		free(cmd_to_exec);
	return (ex_code);
}
