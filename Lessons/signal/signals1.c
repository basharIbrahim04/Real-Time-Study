/*
 * Catching signals with sigset
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

typedef void (*sighandler_t)(int);
sighandler_t sigset(int sig, sighandler_t disp);

int main(void)
{
  int  i;
  void signal_catcher(int);
  void signal_catcher1(int);
  void signal_catcher10(int);

  if ( sigset(SIGINT, signal_catcher) == SIG_ERR ) {
    perror("Sigset can not set SIGINT");
    exit(SIGINT);
  }
  if ( sigset(SIGQUIT, signal_catcher) == SIG_ERR ) {
    perror("Sigset can not set SIGQUIT");
    exit(SIGQUIT);
  }
  if ( sigset(SIGBUS, signal_catcher1) == SIG_ERR ) {
    perror("Sigset can not set SIGBUS");
    exit(SIGBUS);
  }

  if ( sigset(SIGUSR1, signal_catcher10) == SIG_ERR ) {
    perror("Sigset can not set SIGUSR1");
    exit(SIGQUIT);
  }

  //if ( sigset(SIGKILL, signal_catcher10) == SIG_ERR ) {
  //perror("Sigset can not set SIGKILL");
  //exit(SIGKILL);
  //}

  for ( i = 0; ; ++i ) {
    printf("%i\n", i);

    //sleep(10);
    pause();
  }

  
}

void signal_catcher(int the_sig)
{
  printf("\nSignal %d received.\n", the_sig);
  
  if ( the_sig == SIGQUIT )
    exit(1);
}

void signal_catcher1(int the_sig)
{
}

void signal_catcher10(int the_sig)
{
  printf("Youpiiiiiiiii!\n");
  return;
}

