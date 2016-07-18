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
    int reszta = a % b;
    int iloraz = a / b;
    a = b;
    b = reszta;
    int zapamiętaj_r = r;
    int zapamiętaj_s = s;
    r = x - iloraz * r;
    s = y - iloraz * s;
    x = zapamiętaj_r;
    y = zapamiętaj_s;
  }
  printf("nwd(%d, %d) = %d * %d + %d * %d = %d\n", 
         m, n, x, m, y, n, a);
  return 0;
}
