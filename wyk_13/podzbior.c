// podzbior.c

#include <stdio.h>

void podzbior(int n, int x[n], int i)
{
  if(i == n)
  {
    for(int j = 0; j < n; j++)
      printf("%d ", x[j]);
    printf("\n");
  }
  else
  {
    x[i] = 0;
    podzbior(n, x, i + 1);
    x[i] = 1;
    podzbior(n, x, i + 1);
  }
}

int main(void)
{
  int n;
  printf("rozmiar zbioru: ");
  scanf("%d", &n);
  int x[n];
  podzbior(n, x, 0);  
  return 0;
}

