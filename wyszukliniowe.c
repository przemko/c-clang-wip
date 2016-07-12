// wyszukiniowe.c
//
// Wyszukiwanie zadanej wartości w nieuporządkowanej tablicy.

#include <stdio.h>
#include <stdbool.h>

bool szukaj(int n, int tablica[n], int wart, int *indeks)
{
  *indeks = 0;
  while(*indeks < n && tablica[*indeks] != wart)
    (*indeks)++;
  return *indeks < n;
}

int main(void)
{
  int i;
  int t[8] = {6, 1, 3, 8, 4, 1, 9, 3};
  if(szukaj(8, t, 9, &i))
    printf("Liczba 9 występuje w tablicy na pozycji %d.\n", i);
  else
    printf("Liczby 9 nie ma w tablicy.\n");
  if(szukaj(8, t, 2, &i))
    printf("Liczba 2 występuje w tablicy na pozycji %d.\n", i);
  else
    printf("Liczby 2 nie ma w tablicy.\n");
  return 0;
}

