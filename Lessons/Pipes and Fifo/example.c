/*
 * The server process
 */
#ifdef LINUX
#include "locallinux.h"
#endif

#ifdef WINDOWS
#include "localwin.h"
#endif

#ifdef MACOS
#include "localmacos.h"
#endif

#include "local.h"
#include "local.h"
#include "local.h"

//#include "local1.h"
//#include "local1.h"

int debug = 0;

void main(void)
{
  int            n, done, dummyfifo, publicfifo, privatefifo;
  struct message msg;
  FILE          *fin;
  static char    buffer[PIPE_BUF];

  int debug = 1;
  
#ifdef __ALG1__
  shsjh
    sdsdfs
    fsf
    sfsf
    sfsf
    sfsf
    sfs
    f
#endif

#ifdef __ALG2__
dfd\fdf\
    dfd
    fd
    fd
    fdf
    df
    
#endif

    if ( debug == 1 ) 
      printf("Hi 3\n");

#ifdef __DEBUG3__
    printf("Hi 4\n");
#endif

    return;
}

