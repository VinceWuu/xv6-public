//test for mprotect and munprotect
#include "types.h"
#include "stat.h"
#include "user.h"
#include "mmu.h"

int
main(int argc, char *argv[])
{
  char *x = sbrk(0);//initialize
  sbrk(PGSIZE);
  *x = 100;
  mprotect(x, 1);//to read-only
  if(fork() == 0){
    printf(1, "Protecting... %d \n", *x);
    munprotect(x, 1);// to read-write
    *x = 10;
    printf(1, "Unprotecting.... %d \n", *x);
    exit();
  }
  else if(fork() > 0){
    wait();//until all the child process finished
    printf(1, "Error.... \n");
    *x = 10;
    exit();
  }
 exit();
}