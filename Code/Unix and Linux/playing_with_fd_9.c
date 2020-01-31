#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int main() {
    int status;
    FILE* oob = fopen("./test_res", "w+");

    // Close all standard file streams.
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);

    // Now try to print something to stdout.
    // Then record the status in a separate
    // file since we just closed stdout (an
    // out of band observation in a way but
    // not exactly).
    status = printf("du wat?\n");
    fprintf(oob, "%d %d\n", status, errno);
    // errno 9 - EBADF 9 Bad file descriptor

    // Wrap things up.
    fclose(oob);
    return 0;
}
