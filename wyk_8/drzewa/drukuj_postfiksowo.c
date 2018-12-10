// drukuj_postiksowo.c

#include <stdio.h>
#include "drzewa.h"

void drukuj_postfiksowo(Drzewo wsk)
{
  if(wsk != NULL)
    {
      drukuj_postfiksowo(wsk->lewe);
      drukuj_postfiksowo(wsk->prawe);
      printf("%d ", wsk->wartość);
    }
}
