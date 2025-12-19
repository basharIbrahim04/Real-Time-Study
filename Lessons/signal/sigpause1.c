/*
 * Pausing with sigpause
 */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

typedef void (*sighandler_t)(int);
sighandler_t sigset(int sig, sighandler_t disp);

int sighold(int sig);
int sigrelse(int sig);

void main(void)
{
  void   sigset_catcher(int);
  void   sigset_catcher2(int);
  void   sigset_catcherq(int n);
  void   sigset_catcherInt(int n);
    
  sigset(SIGUSR2, sigset_catcher);
  sigset(SIGUSR1, sigset_catcher2);
  sigset(SIGQUIT, sigset_catcherq);
  sigset(SIGINT,  sigset_catcherInt);

  while ( 1 ) {
    printf("Waiting for signal %d\n", SIGUSR2);
    //sigpause(SIGUSR2);		/* Wait for USR1 signal */

    pause();
  }
}

void sigset_catcher(int n)
{
  sighold(SIGINT);		/* Hold interrupt */
  sighold(SIGTERM);		/* Hold terminate */
  sighold(SIGQUIT);		/* Hold Quit */
  sighold(SIGUSR1);		/* Hold USR1 */
  printf("Beginning important stuff\n");
  sleep(25);
  printf("Ending important stuff\n");
  sigrelse(SIGINT);		/* Release interrupt */
  sigrelse(SIGTERM);		/* Release terminate */
  sigrelse(SIGQUIT);		/* Release quit */
  sigrelse(SIGUSR1);		/* Release quit */
}

void sigset_catcher2(int n)
{
  printf("Received signal USR1\n");
}

void sigset_catcherq(int n)
{
  printf("Received signal quit\n");
}

void sigset_catcherInt(int n)
{
  printf("Received signal INT\n");
}
