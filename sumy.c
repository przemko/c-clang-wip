// sumy.c
// 
// Program czyta liczby całkowite i liczy sumę liczb dodatnich
// oraz sumę liczb ujemnych. Aby zakończyć wpisywanie liczb
// należy wpisać liczbę zero.

#include <stdio.h>

int main(void)
{
  int suma_dodatnich = 0;
  int suma_ujemnych = 0;
  int n;
  printf("Wpisuj liczby całkowite.\n");
  printf("Aby zakończyć wpisz liczbę zero.\n");
  scanf("%d", &n);
  while(n != 0)
  {
    if(n > 0)
      suma_dodatnich = suma_dodatnich + n;
    else
      suma_ujemnych = suma_ujemnych + n;
    scanf("%d", &n);
  }
  printf("Suma dodatnich wynosi: %d\n", suma_dodatnich);  
  printf(" Suma ujemnych wynosi: %d\n", suma_ujemnych);
  return 0;
}

