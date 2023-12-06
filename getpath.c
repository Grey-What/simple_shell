#include "main.h"
/**
* getdires - gets the directories in PATH
* @name: name of command
* Return: return the list of directories
*/
char **getdires(char *name)
{
	int i =0, len = 0;
	char **env = environ, *path, **pathdires, **directories;
	
	len = _strlen(name);
	while (*env)
	{
		if (_strcmp(env[i], name , len) == 0 && env[i][len] == '=')
		{
			path = _strdup(env[i]);
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
	char **directories = NULL;

	directories = getdires(name);

}

