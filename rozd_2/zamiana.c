// zamiana.c

#include <stdio.h>

int main(void)
{
  int x = 13;
  int y = 7;

  printf("x=%d, y=%d\n", x, y);
  x = x ^ y;
  y = x ^ y;
  x = x ^ y;
  printf("x=%d, y=%d\n", x, y);

  return 0;
}

