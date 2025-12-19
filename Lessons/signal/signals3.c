/*
 * Catching signals with sigset
 * Remember that sighold and sigrelse are obsolete.
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

typedef void (*sighandler_t)(int);
sighandler_t sigset(int sig, sighandler_t disp);

void sigset_catcher(int);
void sigset_catcher2(int);

int main(void)
{
  sigset(SIGUSR1, sigset_catcher2);
  
  signal(SIGUSR1,SIG_IGN);
    
  sigset(SIGUSR2, sigset_catcher);
  printf("Waiting for signal\n");
  pause();
  printf("Done\n");

  while(1) {
    pause();
  }
  
  exit(0);
}

void sigset_catcher(int n)
{
  printf("\nReceived signal %d will release SIGUSR1\n", n);
    
  printf("SIGUSR1 released!\n");
  
  signal(SIGUSR1,sigset_catcher2);
}

void sigset_catcher2(int n)
{
  printf("/Received SIGUSR1\n");
}
