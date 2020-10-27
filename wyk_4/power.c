#include <stdio.h>
#include <math.h>
#include <assert.h>

int main(void)
{
  int x;
  printf(" podaj dodatnie x: ");
  scanf("%d", &x);
  assert(x > 0);
  int n;
  printf("podaj nieujemne n: ");
  scanf("%d", &n);
  assert(n >= 0);

  int y = 1;
  int p = x;
  int i = n;
  while(i > 0)
  {
    assert (y * pow(p, i) == pow(x, n));
    if(i % 2 == 0)
    {
      p = p * p;
      i = i / 2;
    }
    else
    {
      y = y * p;
      i = i - 1;
    }
  }

  printf("%d ** %d = %d\n", x, n, y);
  return 0;
}

