// znajdz1.c
//
// Wyznaczanie najmniejszej liczby naturalnej, która nie 
// występuje w danej tablicy.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int znajdz_min_spoza(int n, int tab[n])
{
  int min = 0;
  bool zrobione = false;  
  while(!zrobione)
  {
    int i = 0;
    while(i < n && min != tab[i])
      i++;
    if(i == n)
      zrobione = true;
    else
      min++;
  }
  return min;
}

int main(void)
{
  int n = 20;
  int t[n];
  srand(time(NULL));
  for(int i = 0; i < n; i++)
  {
    bool nastepny;
    do
    {
      t[i] = rand() % (3 * n / 2);
      nastepny = true;
      for(int j = 0; j < i; j++)
        if(t[i] == t[j])
        {
          nastepny = false;
          break;
        }
    } while(! nastepny);
  }
  printf("          Tablica:");
  for(int i = 0; i < n; i++)
    printf(" %u", t[i]);
  printf("\n");
  printf("Najmniejszy spoza: %u\n", znajdz_min_spoza(n, t));
  return 0;
}

