#include "types.h"
#include "stat.h"
#include "user.h"
#include <stddef.h>

int waitStatus = 1;
int exitStatus;
int waitPidStatus = 1;

int main(int argc, char *argv[]) {

    printf(1, "lab1\n");

    int i = 0;

    for (i = 0; i < 2; ++i) {
        int pid = fork();
        int parent_status;
        int waitPID;

        if (pid == 0) {
            if (i == 0) {
                printf(1, "This is a child process, PID: %d and Exit Status: %d\n", getpid(), 0);
                exitSt(0);
            } else {
                printf(1, "This is a child process, PID: %d and Exit Status: %d\n", getpid(), -1);
                exitSt(-1);
            }
        } else if (pid > 0) {
            waitPID = waitSt(&parent_status);
            printf(1, "This is a parent process. PID: %d and Exit Status: %d\n", waitPID, parent_status);
        } else {
            printf(1, "Error\n");
            exitSt(-1);
        }
    }

    exitSt(0);

    //int pid = fork();

//    if (pid > 0) {
//        waitpid(pid, NULL, 0);
//        printf(1, "This is a parent process. PID: %d\n", pid);
//        exitSt(0);
//    }
//
//    pid = fork();
//
//    if (pid == 0) {
//        printf(1, "This is a child process, PID: %d\n", pid);
//    } else if (pid > 0) {
//        printf(1, "This is a parent process. PID: %d\n", pid);
//        waitpid(pid, NULL, 0);
//    } else {
//        printf(1, "Error\n");
//    }
}


