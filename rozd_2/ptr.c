// ptr.c

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int* x;
  int* y;
  x = malloc(sizeof(int));
  *x = 13;
  y = x;
  printf("%d\n", *y);
  return 0;
}

