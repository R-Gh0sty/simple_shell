#include "shell.h"

/**
 * _myenv_shell - prints the current environment
 * @info: structure that contains some arguments of programs in the shell
 *
 * Return: Always 0
 */
int _myenv_shell(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv_shell - gets the value of an environ variable
 * @info: structure that contains some arguments of the program
 * @name: name of env
 *
 * Return: the value
 */
char *_getenv_shell(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv_shell - Initialize a new environment variable,
 * @info: structure that contains arguments of the program
 *
 *  Return: Always 0 or 1
 */
int _mysetenv_shell(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv_shell - Remove an environment variable
 * @info: structure that contains arguemnts of the program
 *
 *  Return: Always 0
 */
int _myunsetenv_shell(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list_shell - populates env linked list
 * @info: structure that contains arguments of the program
 *
 * Return: Always 0
 */
int populate_env_list_shell(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
