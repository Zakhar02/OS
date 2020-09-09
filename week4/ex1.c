#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	int n =10;
	pid_t pid = fork();
	if(pid==0) //if child
		printf("Hello from child[%d - %d]\n", pid, n);
	else if(pid>0) // if parent
		printf("Hello from parent[%d - %d]\n", pid, n);
	else return 1;
// in total 20 lined in output because each process runs child process
	return 0;
}
