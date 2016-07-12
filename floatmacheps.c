// floatmacheps.c
//
// Obliczenie epsilon maszynowego dla typu float.

#include <stdio.h>

int main(void)
{
  float delta = 1.0F;
  float macheps = 0.0F;
  while(1.0F + delta > 1.0F)
  {
    macheps = delta;
    delta *= 0.5F;
  }
  printf("Macheps dla typu float wynosi: %e\n", macheps);
  return 0;
}

