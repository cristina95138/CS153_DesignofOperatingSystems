#include "types.h"
#include "stat.h"
#include "user.h"

int waitStatus = 1;
int exitStatus;
int waitPidStatus = 1;

int main(int argc, char *argv[]) {	
    int pid = fork();

    if (pid > 0) {
        waitpid(pid, status, 0);
        printf(1, "This is a parent process. PID: ", pid);
        exitSt(0);
    } else if (pid < 0) {
        printf(1, "Error! No processes");
    }

    pid = fork();

   if (pid == 0) {
       printf(1, "This is a child process, PID: ", pid);
   } else if (pid > 0) {
       printf(1, "This is a parent process. PID: ", pid);
       waitpid(pid, status, 0);
   } else if (pid < 0) {
       printf(1, "Error! No processes");
   }


    exitSt(0);
}


