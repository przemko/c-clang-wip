// znajdz2.c
//
// Wyznaczanie najmniejszej liczby naturalnej, która nie występuje
// w danej tablicy (zastosowano połowienie).

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int podziel(int dl, unsigned int tab[dl], int początek, int koniec, 
            unsigned int próg)
{
  int i = początek;
  int j = koniec;
  while(i <= j)
  {
    if(tab[i] < próg)
      i++;
    else if(tab[j] >= próg)
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

unsigned int znajdz_min_spoza(int dl, unsigned int tab[dl])
{
  int początek = 0;
  int koniec = dl - 1;
  unsigned int akumulator = 0;
  int n = dl;
  unsigned int pomoc[dl];
  for(int i = 0; i < dl; i++)
    pomoc[i] = tab[i];
  while(n > 0)
  {
    unsigned int próg = akumulator + 1 + n / 2;
    int granica = podziel(dl, pomoc, początek, koniec, próg);
    int m = granica - początek;
    if(m == próg - akumulator)
    {
      akumulator = próg;
      n -= m;
      początek = granica;
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
  unsigned int t[n];
  srand(time(NULL));
  for(int i = 0; i < n; i++)
  {
    bool następny;
    do
    {
      t[i] = rand() % (3 * n / 2);
      następny = true;
      for(int j = 0; j < i; j++)
        if(t[i] == t[j])
        {
          następny = false;
          break;
        }
    } while(! następny);
  }
  printf("          Tablica:");
  for(int i = 0; i < n; i++)
    printf(" %d", t[i]);
  printf("\n");
  printf("Najmniejszy spoza: %u\n", znajdz_min_spoza(n, t));
  return 0;
}

