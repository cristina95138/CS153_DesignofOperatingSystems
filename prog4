#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
        set_prior(7);
        int i, k;


        for(i = 0; i < 10000; i++) {
                asm("nop");
                for(k=0; k < 10000; k++) {
                        asm("nop");
                }
        }
  
        track_scheduler();
}
