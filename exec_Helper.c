#include "shell.h"
/**
 * cmd_execve - the name explains it
 * @cmd: the command to execute
 * @arr_words: arr of commands
 * Return: void
 */
/* BY CHARIFA MASBAHI & NORA JEOUT*/
void cmd_execve(char *cmd, char **arr_words)
{
	if (execvp(cmd, arr_words) == -1)
	{
		perror("Error executing command");
		exit(100);
	}
}

/**
 * wait_kid_process - wait child process to end
 * @pid: process id
 * @status: status of process
 * Return: void
 */
/* BY CHARIFA MASBAHI & NORA JEOUT*/
void wait_kid_process(pid_t pid, int *status)
{
	if (waitpid(pid, status, 0) == -1)
	{
		perror("Error while waiting for child process");
		return;
	}
}
