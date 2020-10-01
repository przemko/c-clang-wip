#include <stdio.h>
#include <math.h>
#include <assert.h>

int power(int x, unsigned int n)
{
  int y = 1;
  int p = x;
  unsigned int i = n;
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
  return y;
}

int main(void)
{
  printf("%d\n", power(2, 16));
  return 0;
}
