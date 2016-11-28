// main1.c

#include <stdio.h>
#include "listy.h"

int main(void)
{
	Lista wsk = NULL;
	wsk = dopisz_na_poczatek(wsk, 8);
	wsk = dopisz_na_poczatek(wsk, 2);
	wsk = dopisz_na_poczatek(wsk, 7);
	printf("zawartość listy = ");
	drukuj(wsk);
	usun(&wsk);
	return 0;
}
