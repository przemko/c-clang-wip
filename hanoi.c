// hanoi.c
//
// Program rozwiązuje łamigłówkę wieży z Hanoi.

#include <stdio.h>
#include <assert.h>

void hanoi(int ile, int skąd, int dokąd, int *licznik)
{
  if(ile  > 0)
  {
    int pomoc = 6 - (skąd+dokąd);
    hanoi(ile-1, skąd, pomoc, licznik);
    (*licznik)++;
    printf("%d: %d ==> %d\n", *licznik, skąd, dokąd);
    hanoi(ile-1, pomoc, dokąd, licznik);
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

