// plecak.c
//

#include <stdio.h>
#include <assert.h>

static const int max_n = 100;
static const int max_pojemność = 1000000;

int plecak(int n, int rozmiar[n], int wartość[n],
           int pojemność)
{
  int max_wartość[pojemność + 1];
  max_wartość[0] = 0;
  for(int i = 1; i <= pojemność; i++)
  {
    int max = 0;
    for(int t = 0; t < n; t++)
      if(rozmiar[t] <= i)
      {
        int łącznie = max_wartość[i - rozmiar[t]] + wartość[t];
        if(łącznie > max)
          max = łącznie;
      }
    max_wartość[i] = max;
  }
  return max_wartość[pojemność];
}

int main(void)
{
  int n;
  printf("  Ile przedmiotów (max = %d): ", max_n);
  scanf("%d", &n);
  assert(n > 0);
  assert(n <= max_n);
  int pojemność;
  printf("Pojemność plecaka (max = %d): ", max_pojemność);
  scanf("%d", &pojemność);
  assert(pojemność > 0);
  assert(pojemność <= max_pojemność);
  int rozmiar[n];
  int wartość[n];
  for(int i = 0; i < n; i++)
  {
    printf("  rozmiar przedmiotu [%d]: ", i);
    scanf("%d", &rozmiar[i]);
    printf("  wartość przedmiotu [%d]: ", i);
    scanf("%d", &wartość[i]);
  } 
  printf("Maksymalna wartość zabranych przedmiotów = %d\n", 
         plecak(n, rozmiar, wartość, pojemność)); 
  return 0;
}

