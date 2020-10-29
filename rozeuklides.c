// rozeuklides.c

// Program przedstawia wartość największego wspólego dzielnika
// dwóch liczb w postaci ich liniowej kombinacji. Wykorzystano
// rozszerzony algorytm Euklidesa.

#include <stdio.h>
#include <assert.h>

int main(void)
{
  int m, n;
  printf("Podaj pierwszą liczbę dodatnią: ");
  scanf("%d", &m);
  assert(m > 0);
  printf("   Podaj drugą liczbę dodatnią: ");
  scanf("%d", &n);
  assert(n > 0);

  int a = m;
  int b = n;
  int x = 1;
  int y = 0;
  int r = 0;
  int s = 1;
  while (b > 0)
  {
    // niezmiennik: NWD(m, n) = NWD(a, b)
    // niezmiennik: a = m * x + n * y
    // niezmiennik: b = m * r + n * s
    int reszta = a % b;
    int iloraz = a / b;
    a = b;
    b = reszta;
    int rr = r;
    int ss = s;
    r = x - iloraz * r;
    s = y - iloraz * s;
    x = rr;
    y = ss;
  }
  int z = a;
  
  printf("%d * %d + %d * %d = %d\n", m, x, n, y, z);
  return 0;
}
