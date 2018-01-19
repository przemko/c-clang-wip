// scalsort.c 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void scal(int dl, int tab[dl], int robocza[dl],
          int pierwszy, int srodek, int ostatni)
{
  int i = pierwszy, j = srodek + 1, k = pierwszy;
  while(k <= ostatni)
  {
    if(i <= srodek && j <= ostatni)
      if(tab[i] <= tab[j])
        robocza[k++] = tab[i++];
      else
        robocza[k++] = tab[j++];
    else
      if(i <= srodek)
        robocza[k++] = tab[i++];
      else
        robocza[k++] = tab[j++];
  }
  for(int i = pierwszy; i <= ostatni; i++)
    tab[i] = robocza[i];
}

void reksort(int dl, int tab[dl], int robocza[dl],
             int pierwszy, int ostatni)
{
  if(pierwszy < ostatni)
  {
    int srodek = pierwszy + (ostatni - pierwszy) / 2;
    reksort(dl, tab, robocza, pierwszy, srodek);
    reksort(dl, tab, robocza, srodek + 1, ostatni);
    scal(dl, tab, robocza, pierwszy, srodek, ostatni);
  }
}

void sort(int dl, int tab[dl])
{
  int robocza[dl];
  reksort(dl, tab, robocza, 0, dl - 1);
}

int main(void)
{
  int n = 20;
  int t[n];
  srand(time(NULL));
  for(int i = 0; i < n; i++)
    t[i] = rand() % 100;
  printf("przed sortowaniem: ");
  for(int i = 0; i < n; i++)
    printf("%2d ", t[i]);
  printf("\n");
  sort(n, t);
  printf("    po sortowaniu: ");
  for(int i = 0; i < n; i++)
    printf("%2d ", t[i]);
  printf("\n");
  return 0;
}


