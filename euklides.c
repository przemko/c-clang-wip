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
  int x = m < n ? m : n;
  int y = m > n ? m : n;
  while(x > 0)
  {
    // niezmiennik: nwd(m, n) = nwd(x, y)
    int tmp = x;
    x = y % x;
    y = tmp;
  }
  printf("nwd(%d, %d) = %d\n", m, n, y);
  return 0;
}

