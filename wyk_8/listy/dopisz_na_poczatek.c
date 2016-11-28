// dopisz_na_poczatek.c

#include <stdlib.h>
#include "listy.h"

Lista dopisz_na_poczatek(Lista wsk, int i)
{
  Lista nowy;
  nowy = malloc(sizeof(struct Węzeł));
  nowy->wartość = i;
  nowy->następny = wsk;
  return nowy;
}
