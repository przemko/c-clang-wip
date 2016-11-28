// main.c

#include <stdio.h>
#include "drzewa.h"

int main(void)
{
	Drzewo wsk = NULL;
	wstaw_uporzadkowane(&wsk, 4);
	wstaw_uporzadkowane(&wsk, 2);
	wstaw_uporzadkowane(&wsk, 3);
	wstaw_uporzadkowane(&wsk, 6);
	wstaw_uporzadkowane(&wsk, 1);
	wstaw_uporzadkowane(&wsk, 7);
	wstaw_uporzadkowane(&wsk, 5);
	printf(" pre = ");
	drukuj_prefiksowo(wsk);
	printf("\n  in = ");
	drukuj_infiksowo(wsk);
	printf("\npost = ");
	drukuj_postfiksowo(wsk);
	printf("\n");
	return 0;
}
