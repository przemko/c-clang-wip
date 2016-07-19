// euklide.c
//
// Obliczenie największego wspólnego dzielnika algorytmem 
// Euklidesa.

#include <stdio.h>
#include <assert.h>

int main(void)
{
  int m, n;
  printf("Podaj pierwszą dodatnią liczbę całkowitą: ");
  scanf("%d", &m);
  assert(m > 0);
  printf("   Podaj drugą dodatnią liczbę całkowitą: ");
  scanf("%d", &n);
  assert(n > 0);
  int a = m;
  int b = n;
  while(b > 0)
  {
    // niezmiennik: nwd(m, n) = nwd(a, b)
    int reszta = a % b;
    a = b;
    b = reszta;
  }
  printf("nwd(%d, %d) = %d\n", m, n, a);
  return 0;
}

