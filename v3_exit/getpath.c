#include "main.h"
/**
* getdires - gets the directories in PATH
* @name: name of command
* Return: return the list of directories
*/
char **getdires(char *name)
{
	int len = 0;
	char **env = environ, *path, **pathdires, **directories;

	len = _strlen(name);
	while (*env)
	{
		if (_strncmp(name, *env, len) == 0 && (*env)[len] == '=')
		{
			path = _strdup(*env);
			if (!path)
			{
				perror("path");
				return (NULL);
			}
		}
		env++;
	}
	pathdires = construct_list(path, "=");
	if (pathdires == NULL)
	{
		/* error check */
		printf("no pathdires");
		free(path);
		exit(EXIT_FAILURE);
	}
	free(path);

	directories = construct_list(pathdires[1], ":");
	if (directories == NULL)
	{
		/* error check */
		printf("no directories");
		exit(EXIT_FAILURE);
	}
	free_list(pathdires);
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

	struct stat temp;

	directories = getdires("PATH");
	if (directories == NULL)
	{
		return (NULL);
	}
	while (directories[i] != NULL)
	{
		pathname = malloc(sizeof(char) * (_strlen(directories[i]) + _strlen(name) + 2));
		if (pathname == NULL)
			return (NULL);

		_strcpy(pathname, directories[i]);
		_strcat(pathname, "/");
		_strcat(pathname, name);
		if (stat(pathname, &temp) == 0)
		{
			free_list(directories);
			return (pathname);
		}
		free(pathname);
		pathname = NULL;
		i++;
	}
	free_list(directories);
	return (NULL);
}
