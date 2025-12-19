/*
 * Catching signals with sigset
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

typedef void (*sighandler_t)(int);
sighandler_t sigset(int sig, sighandler_t disp);

int val = 0;

int main(void)
{
  int  i;
  void signal_catcher(int);

  i = 50;

  alarm(i);

  while ( ( i = alarm(i)) > 0) {
    printf("i = %d\n", i);
  }

  printf("i = %d\n", i);

  if ( sigset(SIGALRM, signal_catcher) == SIG_ERR ) {
    perror("Sigset can not set SIGALRM");
    exit(SIGINT);
  }

  while ( 1 ) {
    pause();
  }
}

void signal_catcher(int the_sig)
{
  val++;

  printf("val = %d\n", val);

  if (val < 10)
    alarm(1);
}

