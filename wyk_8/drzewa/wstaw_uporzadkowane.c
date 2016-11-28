// wstaw_uporzadkowane.c

#include <stdlib.h>
#include "drzewa.h"

void wstaw_uporzadkowane(Drzewo *wsk, int i)
{
	if(*wsk == NULL)
	{
		*wsk = malloc(sizeof(struct Węzeł));
		(*wsk)->wartość = i;
		(*wsk)->lewe = NULL;
		(*wsk)->prawe = NULL;
	}
	else 
		if(i < (*wsk)->wartość) 
			wstaw_uporzadkowane(&((*wsk)->lewe), i);
		else
			if(i > (*wsk)->wartość)
				wstaw_uporzadkowane(&((*wsk)->prawe), i);
}
