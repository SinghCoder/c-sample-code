#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#define CHILD 0

int main(int argc, char *const argv[], char *const envp[]) {
    puts("Opening a pipe.");
    int pipe_fd[2];
    int pipe_res = pipe(pipe_fd);
    if (pipe_res < 0) {
        puts("Error in opening pipe.");
        exit(errno);
    }


    puts("About to split.");
    pid_t pid = fork();
    int status;
    char buf[1];
    ssize_t size;
    char *const _argv[] = {"/bin/ls", "-l", "./", NULL};
    switch (pid){
        case -1: // error
            puts("Failed to fork.");
            exit(errno);

        case CHILD: //child
            close(pipe_fd[0]);
            if (dup2(pipe_fd[1], STDOUT_FILENO) == -1) {
                puts("failed to replace stdout.");
                exit(errno);
            }
            write(STDOUT_FILENO, "Greetings from the child process!\n", 34);
            if (execve(_argv[0], &_argv[0], envp) == -1) {
                puts("Failed to execute ls.");
                exit(errno);
            }
            close(STDOUT_FILENO);
            return 0;

        default:  //parent
            close(pipe_fd[1]);
            if (dup2(pipe_fd[0], STDIN_FILENO) == -1) {
                puts("failed to replace stdin.");
                exit(errno);
            }
            write(STDOUT_FILENO, "\t", 1);
            while((size = read(STDIN_FILENO, buf, 1)) > 0) {
                if (buf[0] == '\n') {
                    write(STDOUT_FILENO, "\n\t", 2);
                } else {
                    write(STDOUT_FILENO, buf, size);
                }
            }
            waitpid(pid, &status, 0);
            close(STDIN_FILENO);
            puts("\nDone.");
            return WEXITSTATUS(status);
    }
}

// A disadvantage to using switch is that all of the variables need to be
// declared in advance before the switch statement - i.e. variable
// declerations can not be made inside the case statements.
