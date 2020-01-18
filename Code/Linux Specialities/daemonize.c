/* Disclaimer: glibc provides the deamon(3) library function as a part of
Linux and should be prefered over writing ad-hoc boiler plate code like
this. Though this C example *does* provide a good demonstration of the steps
to be taken to daemonize a process via. system calls in Unix especially since
deamon(3) is not a POSIX.1. standard function. */

#include <errno.h>
#include <fcntl.h>
#include <getopt.h>
#include <signal.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#define SILENT_LOOP

void handle_sigalrm() {
    // Exit gracefully.
    puts("I rest my case.");
    exit(0);
} 

int main(int argc, char* argv[], char* envp[]) {

    // Fork and let the parent process exit succesfully.
    switch (fork()) {
        case 1:
            puts("Error in trying to fork.");
            exit(EXIT_FAILURE);
            break;
        case 0:
            break;
        default:
            printf("Parent with pid %d now exiting.\n", getpid());
            exit(EXIT_SUCCESS);
    }

    // Let's have the child process now leave the session of the terminal.
    // This action will set both the PRGP and the SID of this child process
    // to its PID. Only a non-group leader would have been able to do this.
    if (setsid() < 0) {
        puts("Error in trying to create new session.");
        exit(EXIT_FAILURE);
    }

    // Change directory back to the file system root. This is just a kind of
    // formality. Also remove any umask - it just gets in the way when setting
    // permission for files.
    chdir("/");
    umask(0000);

    // Now detach from the previous/default stdin, stdout and stderr.
    // Do this by redirecting to /dev/null instead.
    int fd = open("/dev/null", O_RDWR);
    // TODO: Add an extra check to see if the file already exists, if
    // it doesn't then we shouldn't be using the O_CREAT flag.
    int logfile = open("/home/driveknight/output", O_WRONLY | O_CREAT, 0664);
    if (dup2(fd, STDIN_FILENO) == -1) {
        perror(NULL);
        exit(errno);
    }
    // We're doing this for observability
    // otherwise use "fd" -> /dev/null.
    if (dup2(logfile, STDOUT_FILENO) == -1) {
        perror(NULL);
        exit(errno);
    }
    if (dup2(logfile, STDERR_FILENO) == -1) {
        perror(NULL);
        exit(errno);
    }

    // Now have the child process do something that prevents it from exiting.
    // This way we can monitor it from htop, top, or ps. Personally, I think
    // that htop is just brilliant and would recommend monitoring from it.
    int opt;
    bool silent_mode = false;
    while((opt = getopt(argc, argv, "s?")) != -1) {
        switch(opt) {
            case 's':
                silent_mode = true;
                break;
            case '?':
            default:
                break;
        }
    }

    signal(SIGALRM, handle_sigalrm);
    alarm(5);  // Stop the daemon after about 5 seconds though - auto cleanup.

    if (silent_mode) {
        while(true);
    }
    else {
        while(true) {
            puts("Poke.");
            sleep(1);  // For sanity.
        }
    }

    // Add a return statement for formality.
    return 0;
}
