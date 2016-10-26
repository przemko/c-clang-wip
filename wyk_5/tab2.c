// tab2.c

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int n;
  scanf("%d", &n);
  int* tab = malloc(n * sizeof(int));
  if(tab == NULL)
  {
    printf("zabrakło pamięci!\n");
    return 1;
  }
  for(int i = 0; i < n; i++)
    tab[i] = 13;
  return 0;
}


