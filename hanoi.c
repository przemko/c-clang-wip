// hanoi.c
//
// Program rozwiązuje łamigłówkę wieży z Hanoi.

#include <stdio.h>
#include <assert.h>

void hanoi(int ile, int skad, int dokad, int *licznik)
{
  if(ile  > 0)
  {
    int pomoc = 6 - (skad+dokad);
    hanoi(ile-1, skad, pomoc, licznik);
    (*licznik)++;
    printf("%d: %d ==> %d\n", *licznik, skad, dokad);
    hanoi(ile-1, pomoc, dokad, licznik);
  }
}

int main(void)
{
  int n, licznik = 0;
  printf("Podaj liczbę krążków do przeniesienia: ");
  scanf("%d", &n);
  assert (n >= 0);
  hanoi(n, 1, 3, &licznik);
  printf("Rozwiązano łamigłówkę wykonując %d ruchów.\n", licznik);
  return 0;
}

