// hetmany.c
//
// Dla danego n, będącego rozmiarem szachownicy, program
// znajduje takie rozmieszczenie n hetmanów, w którym żadne
// dwa się nie biją.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int const max_rozmiar = 20;

bool hetmany(int rozmiar, int permutacja[rozmiar], int kolumna)
{
  if(kolumna == rozmiar)
    return true;
  for(int wiersz = 0; wiersz < rozmiar; wiersz++)
  {
    int i = 0;
    while(i < kolumna)
    {
      if(wiersz == permutacja[i] ||
          abs(permutacja[i] - wiersz) == kolumna - i)
        break;
      i++;
    }
    if(i == kolumna)
    {
      permutacja[kolumna] = wiersz;
      if(hetmany(rozmiar, permutacja, kolumna + 1))
        return true;
    } 
  } 
  return false;
}


int main(void)
{
  int n;
  for(;;)
  {
    printf("Rozmiar nie większy niż %d (zero aby zakończyć): ",
           max_rozmiar);
    scanf("%d", &n);
    if(n == 0)
      break;
    if(n < 0)
    {
      printf("Rozmiar powinien być dodatni.\n");
      continue;
    }
    if(n > max_rozmiar)
    {
      printf("Za duży rozmiar planszy (przekracza %d).\n",
             max_rozmiar);
      continue;
    }
    int permutacja[n];
    if(hetmany(n, permutacja, 0))
    {
      for(int i = 0; i < n; i++)
        printf("%4d", permutacja[i]);
      printf("\n");
    }
    else
      printf("Brak rozwiązania!\n");
  }
  return 0;
}

