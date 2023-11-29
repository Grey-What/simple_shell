#include "main.h"
/**
 * _getenv - gets an enviroment variable
 *
 *@name: name of the enviromental variable
 *
 * Return: full enviroment variable definition
 */
char *_getenv(const char *name)
{
	int i = 0, len = 0;
	char **env = environ;

	len = _strlen(name);
	while (*env)
	{
		if (_strncmp(env[i], name, len) == 0 && env[i][len] == '=')
		{
			return (env[i]);
		}
		i++;
	}
	return (NULL);
}
/**
 * getenv_var - get the enviromental variable value
 *
 * Return: NULL on fail, else value of env variable
 */
char *getenv_var()
{
	char *full_var = NULL, **tokens = NULL, *path_val = NULL;

	full_var = _strdup(_getenv("PATH"));
	if (full_var == NULL)
	{
		free(full_var);
		return (NULL);
	}
	tokens = parse_buff(full_var, "=");
	if (!tokens || !*tokens)
	{
		free(full_var);
		return (NULL);
	}
	free(full_var);

	path_val = _strdup(tokens[1]);
	if (path_val == NULL)
	{
		free_com(tokens);
		free(path_val);
		return (NULL);
	}
	return (path_val);
}
/**
 * get_path - will search each directory in path for command
 *
 * @com: command to search for in directories
 *
 * Return: full path name of command executable
 */
char *get_path(char *com)
{
	char *path_val = NULL, *path_name = NULL, **dires = NULL;
	struct stat *temp = malloc(sizeof(struct stat));
	int i = 0, check_stat;

	path_val = getenv_var();
	if (!path_val)
		return (NULL);
	dires = parse_buff(path_val, ":");
	if (!dires || !*dires)
	{
		free(path_val);
		return (NULL);
	}
	free(path_val);
	while (dires[i])
	{
		path_name = malloc(sizeof(char) * (_strlen(dires[i]) + _strlen(com) + 2));
		if (path_name == NULL)
		{
			free_com(dires);
			return (NULL);
		}
		_strcpy(path_name, dires[i]);
		_strcat(path_name, "/");
		_strcat(path_name, com);

		check_stat = stat(path_name, temp);
		if (check_stat == 0)
		{
			free_com(dires);
			free(temp);
			return (path_name);
		}
		free(path_name);
		path_name = NULL;
		i++;
	}
	free_com(dires);
	free(temp);
	return (NULL);
}
