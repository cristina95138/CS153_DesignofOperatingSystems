#include "types.h"
#include "stat.h"
#include "user.h"
#include <stddef.h>

int main(int argc, char *argv[]) {

    printf(1, "lab2\n");

    int pid;
    int i, j, k;

    for (k = 0; k < 3; k++) {
        pid = fork();
        setPrior(30-10*k);

        if (pid > 0) {
            continue;
        } else if (pid == 0) {
            for (i = 0; i < 43000; i++) {
                asm("nop");
                for (j = 0; j < 43000; j++) {
                    asm("nop");
                }
            }
            printf(1, "Child %d that has a priority of %d has finished.\n", getpid(), 30-10*k, trackSched());
            exit();
        } else {
            printf(1, "Error\n");
        }
    }

    if (pid > 0) {
        for (k = 0; k < 3; k++) {
            wait();
        }
    }

    exit();

    return 0;
}
