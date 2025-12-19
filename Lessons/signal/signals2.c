/*
 * Catching signals with sigset
 * Check file signals3.c for a clean version of it.
 * Remember that sighold and sigrelse are obsolete.
 */
#define _XOPEN_SOURCE 500

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int i;

void sigset_catcher(int);
void sigset_catcher2(int);

int main(void)
{
  sigset(SIGINT, sigset_catcher2);
  //sigset(SIGINT, sigset_catcher2);
  //i = sighold(SIGUSR1);

  signal(SIGINT,SIG_IGN);
  // signal(SIGINT,SIG_IGN);

  printf("i = %d\n", i);
  
  sigset(SIGUSR2, sigset_catcher);
  printf("Waiting for signal\n");

  while ( 1 )
    pause();

  
  printf("Done\n");
  //while(1);
  exit(0);
}

void sigset_catcher(int n)
{
  printf("\nReceived signal %d will release SIGUSR2\n", n);
  //i = sigrelse(SIGUSR1);

  //printf("i = %d\n", i);
  
  printf("SIGINT released!\n");
  // sigset(SIGUSR1, sigset_catcher2);
  signal(SIGINT,sigset_catcher2);

  //signal(SIGINT, SIG_DFL);
  
  //signal(SIGINT,sigset_catcher2);
  //sleep(1);
  //pause();
  //while(1);
}

void sigset_catcher2(int n)
{
  printf("/Received SIGINT\n");
  //pause();
}
