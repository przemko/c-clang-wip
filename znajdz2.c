// znajdz2.c
//
// Wyznaczanie najmniejszej liczby naturalnej, która nie 
// występuje w danej tablicy (zastosowano połowienie).

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int podziel(int dl, int tab[dl], int poczatek, 
            int koniec, int prog)
{
  int i = poczatek;
  int j = koniec;
  while(i <= j)
  {
    if(tab[i] < prog)
      i++;
    else if(tab[j] >= prog)
      j--;
    else
    {
      int tmp = tab[i];
      tab[i] = tab[j];
      tab[j] = tmp;
      i++;
      j--;
    }
  }
  return i;
}

int znajdz_min_spoza(int dl, int tab[dl])
{
  int poczatek = 0;
  int koniec = dl - 1;
  int akumulator = 0;
  int n = dl;
  int pomoc[dl];
  for(int i = 0; i < dl; i++)
    pomoc[i] = tab[i];
  while(n > 0)
  {
    int prog = akumulator + 1 + n / 2;
    int granica = podziel(dl, pomoc, poczatek, koniec, prog);
    int m = granica - poczatek;
    if(m == prog - akumulator)
    {
      akumulator = prog;
      n -= m;
      poczatek = granica;
    }
    else
    {
      n = m;
      koniec = granica - 1;
    }
  }  
  return akumulator;
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

