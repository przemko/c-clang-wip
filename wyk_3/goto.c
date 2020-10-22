// goto.c

#include<stdio.h>

int main(void)
{
  int n;
  printf("Podaj ile liczb wydrukować: ");
  scanf("%d", &n);
  printf("\n");
  int i = 1;

Początek:

  if(i > n)
    goto Koniec;
  printf("%d\n", i);
  i = i + 1;
  goto Początek;

Koniec:

  return 0;
}

