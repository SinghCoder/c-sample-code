#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	printf("About to fork.\n");
	int pid = fork();
	int status;
	printf("This was probably printed twice because it is common to the parent and the child processes.\n");
	if(pid == 0){
		// child process
		printf("Once the execl function gets called, that process overwrites this one.\n");
		execlp("python", "python", "prgm.py", NULL);
		// or other exec varients
		printf("Which is why this line won't get printed.\n"); // this line won't run
		return 0; // this line also won't run
	}
	else{
		waitpid(pid, &status, 0);
		printf("Child process %d exited with exit code %d.\n", pid, status);
	}
	return 0;
}
