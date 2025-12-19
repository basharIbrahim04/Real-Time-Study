// example.c
#include <stdio.h>

#ifndef MY_NUMBER
#define MY_NUMBER 5
#endif

int main() {
  printf("The value of MY_NUMBER is: %d\n", MY_NUMBER);
  return 0;
}
