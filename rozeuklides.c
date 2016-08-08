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
    // niezmiennik: nwd(m, n) = nwd (a, b)
    // niezmiennik: a = m * x + n * y
    // niezmiennik: b = m * r + n * s
    int reszta = a % b;
    int iloraz = a / b;
    assert(reszta == a - iloraz * b);
    a = b;
    b = reszta;
    int zapamiętaj_r = r;
    int zapamiętaj_s = s;
    r = x - iloraz * r;
    s = y - iloraz * s;
    assert (m * r + n * s == m * x + n * y - iloraz * (m * zapamiętaj_r + n * zapamiętaj_s));
    x = zapamiętaj_r;
    y = zapamiętaj_s;
  }
  printf("nwd(%d, %d) = %d * %d + %d * %d = %d\n", 
         m, n, x, m, y, n, a);
  return 0;
}
