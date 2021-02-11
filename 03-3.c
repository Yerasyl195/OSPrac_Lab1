#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
	printf("arguments:\n");

	for (int i = 0; i < argc; i++) {
		
		printf("%s", argv[i]);
		printf("\n");
	}
	
	printf("\nparametrs:\n");
	int i = 0;
	while(envp[i] != NULL){
		printf("%s", envp[i]);
		printf("\n");
		i++;	
	}
	return 0;
}
