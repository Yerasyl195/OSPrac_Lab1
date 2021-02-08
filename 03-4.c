#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
	pid_t pid = fork();

	if (pid == -1) {
		printf("Error");
		exit(-1);
	}
	else if (pid == 0) {
	/* ребенок */
		printf("This one is a kid\n");
		printf("The start of another programm\n");
		execl("program.out", "program.out", "12345", NULL);
	}
	else {
		/* родитель */
		printf("This one is a parent\n");
	}
}
