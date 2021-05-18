#include "types.h"
#include "stat.h"
#include "user.h"
#include <stddef.h>

int main(int argc, char *argv[]) {

    printf(1, "lab2,3\n");

    int pid;
    pid = fork();

    setPrior(7);
    int i, k;

    if (pid == 0) {
        for(i = 0; i < 43000; i++) {
            asm("nop");
            for(k=0; k < 43000; k++) {
                asm("nop");
            }
        }
        printf(1, "Child %d that has a priority of %d has finished.\n", getpid(), 7);
        trackSched();
        exit();
    } else {
        printf(1, "Error\n");
    }

    if (pid > 0) {
        wait();
    }

    exit();

    return 0;
}
