// wyszukbinarne.c
//
// Wyszukiwanie zadanej wartości w tablicy uporządkowanej.

#include <stdio.h>
#include <stdbool.h>

bool szukaj(int n, int tablica[n], int wart, int *indeks)
{
  // zakładamy, że elementy tablicy są posortowane niemalejąco
  int lewy = 0;
  int prawy = n - 1;
  while(lewy <= prawy)
  {
    int środek = lewy + (prawy - lewy) / 2;
    if(wart == tablica[środek])
    {
      *indeks = środek;
      return true;
    }
    else
      if(wart < tablica[środek])
        prawy = środek - 1;
      else
        lewy = środek + 1;
  }
  return false;
}

int main(void)
{
  int i;
  int t[8] = {1, 3, 5, 6, 6, 8, 8, 9};
  if(szukaj(8, t, 3, &i))
    printf("Liczba 3 występuje w tablicy na pozycji %d.\n", i);
  else
    printf("Liczby 3 nie ma w tablicy.\n");
  if(szukaj(8, t, 7, &i))
    printf("Liczba 7 występuje w tablicy na pozycji %d.\n", i);
  else
    printf("Liczby 7 nie ma w tablicy.\n");
  return 0;
}

