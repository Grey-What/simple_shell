#include "main.h"
/**
* getdires - gets the directories in PATH
* @name: name of command
* Return: return the list of directories
*/
char **getdires(char *name)
{
	int i = 0, len = 0;
	char **env = environ, *path, **pathdires, **directories;

	len = _strlen(name);
	while (*env)
	{
		if (_strncmp(env[i], name , len) == 0 && env[i][len] == '=')
		{
			path = _strdup(env[i]);
			if (!path)
			{
				perror("path");
				return (NULL);
			}
		}
		i++;
	}
	pathdires = construct_list(path, "=");
	if (pathdires == NULL)
	{
		/* error check */
	}
	directories = construct_list(pathdires[1], ":");
	if (directories == NULL)
	{
		/* error check */
	}
	return (directories);
}

/**
* getpath - gets an environment variable
* @name: name of the environmental variable
* Return: full environment varaible definition
*/
char *getpath(char *name)
{
	int i = 0;
	char **directories = NULL, *pathname = NULL;

	struct stat *temp = malloc(sizeof(struct stat));
	if (!temp)
	{
		perror("temp");
		return (NULL);
	}

	directories = getdires(name);
	while (directories[i] != NULL)
	{
		pathname = malloc(sizeof(char) * (_strlen(directories[i]) + _strlen(name) + 2));
		if (pathname == NULL)
			return (NULL);

		_strcpy(pathname, directories[i]);
		_strcat(pathname, "/");
		_strcat(pathname, name);
		if (stat(pathname, temp) == 0)
		{
			free_list(directories);
			free(temp);
			return (pathname);
		}
		free(pathname);
		pathname = NULL;
		i++;
	}
	free_list(directories);
	free(temp);
	return (NULL);
}
