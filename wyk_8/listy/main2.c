// main2.c

#include <stdio.h>
#include "listy.h"

int main(void)
{
	Lista wsk = NULL;
	dopisz_na_koniec(&wsk, 8);
	dopisz_na_koniec(&wsk, 2);
	dopisz_na_koniec(&wsk, 7);
	printf("zawartość listy = ");
	drukuj(wsk);
	usun(&wsk);
	return 0;
}
