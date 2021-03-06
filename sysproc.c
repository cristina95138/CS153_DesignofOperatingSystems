#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_hello(void) {
    hello();
    return 0;
}

int
sys_exitSt(void) {
    int exitStatus;

    if (argint(0, &exitStatus) < 0)
        return -1;

    exitSt(exitStatus);

    return 0;
}

int
sys_waitSt(void) {
    int* exitStatus;

    if (argptr(0, (char**)&exitStatus, sizeof(int*) < 0))
        return -1;

    return waitSt(exitStatus);
}

int
sys_waitpid(void) {
    int pid;
    int* exitStatus;
    int options;

    if (argint(0, &pid) < 0)
        return -1;

    if (argptr(1, (char**)&exitStatus, sizeof(int*) < 0))
        return -1;

    if (argint(2, &options) < 0)
        return -1;

    return waitpid(pid, exitStatus, options);
}

int
sys_setPrior(void) {
    int prior;

    if((argint(0, &prior) < 0)) {
        return -1;
    }

    setPrior(prior);

    return 0;
}

int
sys_trackSched(void) {
    int sched;
    if ((argint(0, &sched) < 0)) {
        return -1;
    }

    trackSched();

    return 0;
}
