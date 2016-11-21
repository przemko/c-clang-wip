// parametry.c
//
// Program drukuje parametry uruchomienia programu.

#include <stdio.h>

int main(int argc, char **argv)
{
	printf("Liczba parametrów (argc) = %d\n", argc);
	printf("Kolejne parametry o indeksach od 0 do %d:\n", argc - 1);
	for(int i = 0; i < argc; i++)
		printf("\targv[%d] = \"%s\"\n", i, argv[i]);
	return 0;
}