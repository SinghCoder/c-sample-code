#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void immortality(int signo) {
    printf("I cannot be terminated. (kill <pid>)\n");
    return;
}

void respectfully_die(int signo) {
    printf("\nSo be it.\n");
    exit(signo);
}

int main() {
    // This will have no effect since The signals SIGKILL and SIGSTOP cannot
    // be caught, blocked, or ignored.
    signal(SIGKILL, immortality); // kill -9 <pid>

    // These signals, however, can be intercepted.
    signal(SIGTERM, immortality);
    signal(SIGINT, respectfully_die);

    while (1) {};

    return 0;
}
