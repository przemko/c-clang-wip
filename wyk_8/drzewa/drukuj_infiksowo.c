// drukuj_infiksowo.h

#include <stdio.h>
#include "drzewa.h"

void drukuj_infiksowo(Drzewo wsk)
{
	if(wsk != NULL)
	{
		drukuj_infiksowo(wsk->lewe);
		printf("%d ", wsk->wartość);
		drukuj_infiksowo(wsk->prawe);
	}
}
