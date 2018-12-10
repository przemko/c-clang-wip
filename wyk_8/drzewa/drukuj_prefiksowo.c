// drukuj_prefiksowo.c

#include <stdio.h>
#include "drzewa.h"

void drukuj_prefiksowo(Drzewo wsk)
{
  if(wsk != NULL)
    {
      printf("%d ", wsk->wartość);
      drukuj_prefiksowo(wsk->lewe);
      drukuj_prefiksowo(wsk->prawe);
    }
}
