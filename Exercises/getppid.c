#include <unistd.h>
#include <stdio.h>

int main()
{
	pid_t parent_id;
	pid_t current_id;

	parent_id = getppid();
	current_id = getpid();

	printf("parent id: %d\n", parent_id);
	printf("current id: %d\n", current_id);

	return (0);
}
