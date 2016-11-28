#include <stdio.h>
#include <stdlib.h>
#include "listy.h"

void drukuj(Lista wsk)
{
  while(wsk != NULL)
  {
    printf("%d ", wsk->wartość);
    wsk = wsk->następny;
  }
  printf("\n");
}
