// pierwsza.c
//
// Program sprawdza czy dana liczba jest pierwsza. Jeśli nie,
// to podaje jeden z jej właściwych dzielników.

#include <stdio.h>
#include <math.h>
#include <assert.h>

int main(void)
{
  int n;
  printf("Podaj liczbę do zbadania (większą od 1): ");
  scanf("%u", &n);
  assert(n > 1);
  int limit = sqrt(n);
  int i = 2;
  while(i <= limit)
  {
    if(n % i == 0)
      break;
    i++; 
  }
  if(i > limit)
    printf("%u jest liczbą pierwszą.\n", n);
  else
    printf("%u nie jest liczbą pierwszą (np. %u|%u).\n",
           n, i, n);
  return 0;
}

