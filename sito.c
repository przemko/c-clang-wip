// sito.c
//
// Program zlicza liczby pierwsze z przedziału [0 .. n]. Do
// szybkiego wyznaczania liczb pierwszych wykorzystano sito
// Eratostenesa.

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

int const max_n = 1000000;

int main(void)
{
  int n;
  printf("Podaj zakres (max %d): ", max_n);
  scanf("%d", &n);
  assert(n <= max_n);
  bool sito[n+1];
  for(int i = 0; i <= n; i++)
    sito[i] = true;
  sito[0] = false;
  sito[1] = false;
  int limit = sqrt (n);
  assert(limit <= n); // na potrzeby analizy statycznej

  for(int liczba = 0; liczba <= limit; liczba++)
  {
    if(sito[liczba])
    {
      for(int i = liczba*liczba; i <= n; i += liczba)
        sito[i] = false;
    }
  }

  int licznik = 0;
  for(int liczba = 0 ; liczba <= n; liczba++)
    if(sito[liczba])
      licznik++;

  printf("Znaleziono %d liczb pierwszych w [0 .. %d].\n",
         licznik, n);
  return 0;
}
