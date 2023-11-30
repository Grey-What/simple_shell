#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
int main()
{
	char *buffer = NULL;
	size_t n = 0;
	int i = 0;
	int check = 0, status;
	pid_t my_pid;

	while (1)
	{
		printf("#cisfun$ ");
		check = getline(&buffer, &n, stdin);
		if (check <= 0)
		{
			free(buffer);
			perror("Error");
			exit(errno);
		}
		while(buffer[i])
		{
			if (buffer[i] == '\n')
				buffer[i] = '\0';
			i++;
		}
		i = 0;
		my_pid = fork();
		if (my_pid == -1)
		{
			free(buffer);
			perror("Error");
			exit(errno);
		}
		if (my_pid == 0)
		{
			char *argv[] = {buffer, NULL};
			char *envp[] = {NULL};

			execve(argv[0], argv, envp);
			free(buffer);
			perror("Error");
			exit(errno);
		}
		else
		{
			if (wait(&status) == -1)
				perror("Error");
			free(buffer);
			buffer = NULL;
			n = 0;
		}
	}
	return (0);
}
