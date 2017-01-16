// kombinacje.c

#include <stdio.h>

void kombinacje(int n, int k, int x[n], int i)
{
  if(i == n)
  {
    for(int j = 0; j < n; j++)
      printf("%d ", x[j]);
    printf("\n");
  }
  else
  {
    int start = 1 + (i == 0 ? 0 : x[i - 1]);
    for(x[i] = start; x[i] <= k; x[i]++)
      kombinacje(n, k, x, i + 1);
  }
}

int main(void)
{
  int n;
  printf("   rozmiar zbioru: ");
  scanf("%d", &n);
  int k;
  printf("rozmiar dziedziny: ");
  scanf("%d", &k);
  int x[n];
  kombinacje(n, k, x, 0);  
  return 0;
}

