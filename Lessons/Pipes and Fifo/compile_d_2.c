#include <stdio.h>
#include <math.h>

#ifndef MY_NUMBER
#define MY_NUMBER 5
#endif

int main() {
  double value;
  int valueInt;
      
#ifdef _ALG_1_
  value = 2.0;
  printf("The cosine value of %f is %f\n", value, cos(value));
#else
  value = 2.0;
  valueInt = 2;
  
  printf("The sine value of %f is %f\n", value, sin(value));
#endif
  
  printf("The value of MY_NUMBER is: %d\n", MY_NUMBER);
  return 0;
}
