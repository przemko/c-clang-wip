// usun.c

#include <stdlib.h>
#include "drzewa.h"

void usun(Drzewo *wsk)
{
	if(*wsk != NULL)
	{
		usun(&((*wsk)->lewe));
		usun(&((*wsk)->prawe));
		free(*wsk);
		*wsk = NULL;
	}
}
