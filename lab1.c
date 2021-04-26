#include "types.h"
#include "stat.h"
#include "user.h"

int waitStatus = 1;
int exitStatus;
int waitPidStatus = 1;

int main(int argc, char *argv[]) {	
    int pid = fork();
    pid = waitSt(&waitStatus);
    printf(1, "pid: %d\n", pid);
    pid = hello();
    if(waitpid(pid, &waitPidStatus, 0) != -1) {
        printf(1, "waitPidStatus status: %d\n", waitPidStatus);
    }
    printf(1, "waitpid complete.\nwaitSt status: %d\n", waitStatus);

    //exit();
    printf(1, "\n");
    exitSt(getpid());
    printf(1, "exitSt status: %d\n", exitStatus);
}


