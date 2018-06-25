/* given the file name, typing this name out in the terminal namemight seem like a pain, but that's what <tab> is for. Alternatively, make a copy and change the name of it. */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	printf("The process id of this process is: %d\n", getpid());
	printf("Now forking into child and parent processes.\n");
	int pid = fork();
	int child_status;
	if(pid == 0){
	/* 	When fork() is called, it will split this process into a parent process and a child process.	
		Then eventually it will return a value. But since there are two copies of the program, it 
		will return to both the parent process and child process. To the parent process, it returns
		the child process pid and to the child process it returns 0, making it easier for use to 
		split the code for each one. NOTE: the code is not actually getting copied over but is instead
		intelligently shared. */
		printf("From the child process:\n");
		printf("  Child pid: %d\n", getpid());
		printf("  Parent pid: %d\n", getppid());
		return 0;
	}
	else{
		waitpid(pid, &child_status, 0 /* 0 for no special behavior */ );
		/* 	waitpid will wait for the child process to finish executing and then saves the exit code
			of the child process in the second argument and in doing so, will remove the child process
			preventing it from turning into a zombie or an orphan process. */
		/*	Zombie process: a process which has finished executing but since it's exit code was not
			queried, it still has an entry logged in the process table. 
			Orphan process: once the parent process finishes executing (as a child of the shell 
			process) the shell process will query it and thus will effectively eliminate it from the
			process table) leaving the child process in the process table still as an orphan process
			either in a zombie or non-zombie state. The Init process (father of all processes) will then 
			adopt and query the child process to remove it from the process table. */
		if(WIFEXITED(child_status)){
		/* 	will check if the child process exited normally (exit code 0) or not. If the child process 
			exited normally, it will return a non-zero value, else 0; */
		printf("From the parent process:\n");
		printf("  Parent pid: %d\n", getpid());
		printf("  Child pid: %d\n", pid);
		printf("  Child process exited normally with exit code: %d\n", child_status);
		}
		else{
			printf("An error occured in the child process!\n");
		}
	}
	return 0;
}
