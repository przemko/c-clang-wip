// if.c

#include <stdio.h>

int main(void)
{
  int rok;
  printf("Podaj rok: ");
  scanf("%d", &rok);
  if((rok % 4 == 0 && rok % 100 != 0) || rok % 400 == 0)
    printf("%d jest rokiem przestępnym i ma 366 dni\n", rok);
  else
    printf("%d jest rokiem zwykłym i ma 365 dni\n", rok);
  return 0;
}

