// dopisz_na_koniec.c

#include <stdlib.h>
#include "listy.h"

void dopisz_na_koniec(Lista *wsk, int i)
{
  Lista nowy, pomoc;
  nowy = malloc(sizeof(struct Węzeł));
  nowy->wartość = i;
  nowy->następny = NULL;
  if(*wsk == NULL)
    *wsk = nowy;
  else
  {
    pomoc = *wsk;
    while(pomoc->następny != NULL)
      pomoc = pomoc->następny;
    pomoc->następny = nowy;
  }
}
