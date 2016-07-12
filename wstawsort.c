// wstawsort.c 
//
// Algorytm sortowania przez wstawianie.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int dl, int tab[dl])
{
  for(int i = 1; i < dl; i++)
  {
    // wstawienie tab[i] do ciągu tab[0], ..., tab[i-1]
    int j = 0;
    while(j < i && tab[i] > tab[j])
      j++;
    if(j < i)
    {
      int tmp = tab[i];
      for(int k = i - 1; k >= j; k--)
        tab[k+1] = tab[k];
      tab[j] = tmp;
    }
  }
}

int main(void)
{
  int n = 20;
  int t[n];
  srand(time(NULL));
  for(int i = 0; i < n; i++)
    t[i] = rand() % 100;
  printf("przed sortowaniem: ");
  for(int i = 0; i < n; i++)
    printf("%2d ", t[i]);
  printf("\n");
  sort(n, t);
  printf("    po sortowaniu: ");
  for(int i = 0; i < n; i++)
    printf("%2d ", t[i]);
  printf("\n");
  return 0;
}
