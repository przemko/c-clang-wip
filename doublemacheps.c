// doublemacheps.c
//
// Obliczenie epsilon maszynowego dla typu double.

#include <stdio.h>

int main(void)
{
  double delta = 1.0;
  double macheps = 0.0;
  while(1.0 + delta > 1.0)
  {
    macheps = delta;
    delta *= 0.5;
  }
  printf("Macheps dla typu double wynosi: %E\n", macheps);
  return 0;
}

