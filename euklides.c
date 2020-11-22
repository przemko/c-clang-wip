// euklide.c
//
// Obliczenie największego wspólnego dzielnika algorytmem 
// Euklidesa.

#include <stdio.h>
#include <assert.h>

int nwd(int a, int b)
{
  while(b > 0)
  {
    // niezmiennik: nwd(m, n) = nwd(a, b)
    int reszta = a % b;
    a = b;
    b = reszta;
  }
  return a;
}

int main(void)
{
  int m, n;
  printf("Podaj pierwszą dodatnią liczbę całkowitą: ");
  scanf("%d", &m);
  assert(m > 0);
  printf("   Podaj drugą dodatnią liczbę całkowitą: ");
  scanf("%d", &n);
  assert(n > 0);
  printf("nwd(%d, %d) = %d\n", m, n, nwd(m, n));
  return 0;
}

