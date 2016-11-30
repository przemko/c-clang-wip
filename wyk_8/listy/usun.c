// usun.c

#include <stdlib.h>
#include "listy.h"

void usun(Lista *wsk)
{
  Lista pomoc;
  while(*wsk != NULL)
    {
      pomoc = (*wsk)->następny;
      free(*wsk);
      *wsk = pomoc;
    }
}
