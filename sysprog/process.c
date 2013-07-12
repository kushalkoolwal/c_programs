#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void main (void) {

	pid_t getpid (void);

	printf("My pid=%d\n", getpid());
	printf("Parent pid=%d\n", getppid());

}
