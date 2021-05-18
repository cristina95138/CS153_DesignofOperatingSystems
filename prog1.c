#include "types.h"
#include "stat.h"
#include "user.h"
#include <stddef.h>

int main(int argc, char *argv[]) {

    printf(1, "lab2,1\n");

    int pid;
    pid = fork();

    //setPrior(1);
    //int i, k;

    if (!pid) {
	printf(1, "Error, parent process\n");
     //   exit();
     }  else {
        /*for(i = 0; i < 43000; i++) {
            asm("nop");
            for(k=0; k < 43000; k++) {
                asm("nop");
            }
        }*/
	//printf(1, "a");
        printf(1, "Child %d that has a priority of %d has finished.\n", getpid(), 1);
	trackSched();
	//printf(1, "b");
    }

    return 0;
}
