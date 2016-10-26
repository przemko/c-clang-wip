// niezmiennik.c

#include <stdio.h>
#include <assert.h>

int main(void)
{
  int x;
  printf("         Podaj liczbę naturalną: ");
  scanf("%d", &x);
  int y;
  printf("Podaj liczbę całkowitą dodatnią: ");
  scanf("%d", &y);  
  assert(x >= 0 && y > 0);
  int q = 0;
  int r = x;
  assert(x == q * y + r && 0 <= r);
  while(r >= y)
  {
    assert(x == q * y + r && 0 < y && y <= r);
    r = r - y;
    q = q + 1;
  }
  assert(x == q * y + r && 0 <= r && r < y);
  printf("%d div %d = %d\n", x, y, q);
  printf("%d mod %d = %d\n", x, y, r);
  printf("test: %d * %d + %d = %d\n", q, y, r, q * y + r);
  return 0;
}

