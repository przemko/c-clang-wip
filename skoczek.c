// skoczek.c
//
// Program znajduje rozwiązanie problemu skoczka szachowego
// (jeśli ono istnieje). Dla danego rozmiaru planszy
// rozwiązaniem jest droga ruchami skoczka szachowego przez
// wszystkie pola planszy, przy czym każde pole planszy jest
// odwiedzane dokładnie raz.

#include <stdio.h>
#include <stdbool.h>

int const max_rozmiar = 8;
int dx[8] = {+1, +2, +2, +1, -1, -2, -2, -1};
int dy[8] = {-2, -1, +1, +2, +2, +1, -1, -2};

bool skoczek(int rozmiar, int plansza[rozmiar][rozmiar], 
              int wiersz, int kolumna, int krok)
{
  if(plansza [wiersz][kolumna] != 0)
    return false;
  plansza[wiersz][kolumna] = krok;
  if(krok == rozmiar * rozmiar)
    return true;
  for(int i = 0; i < 8; i++)
  {
    int wiersz2 = wiersz + dy[i];
    int kolumna2 = kolumna + dx[i];
    if(wiersz2 >= 0 && wiersz2 < rozmiar &&
       kolumna2 >= 0 && kolumna2 < rozmiar)
      if(skoczek(rozmiar, plansza, wiersz2, kolumna2, krok + 1))
        return true;
  }
  plansza[wiersz][kolumna] = 0;
  return false;
}

int main(void)
{
  int n;
  for(;;)
  {
    printf("Rozmiar nie większy niż %d (zero aby zakończyć): ",
           max_rozmiar);
    scanf("%d", &n);
    if(n == 0)
      break;
    if(n < 0)
    {
      printf("Rozmiar powinien być dodatni.\n");
      continue;
    }
    if(n > max_rozmiar)
    {
      printf("Za duży rozmiar planszy (przekracza %d).\n",
             max_rozmiar);
      continue;
    }
    int plansza[n][n];
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        plansza[i][j] = 0;
    if(skoczek(n, plansza, 0, 0, 1))
    {
      for(int i = 0; i < n; i++)
      {
        for(int j = 0; j < n; j++)
          printf("%3d", plansza[i][j]);
        printf("\n");
      }
    }
    else
      printf("Brak rozwiązania!\n");
  }
  return 0;
}

