// goto.c

#include<stdio.h>

int main(void)
{
  int n;
  printf("Podaj ile liczb wydrukować: ");
  scanf("%d", &n);
  printf("\n");
  int i = 1;

Pętla:

  if(i > n)
    goto Koniec;
  printf("%d\n", i);
  i = i + 1;
  goto Pętla;

Koniec:

  return 0;
}

