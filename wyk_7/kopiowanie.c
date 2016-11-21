// kopiowanie.c
//
// Program kopiuje standardowe wejście na standardowe wyjście.

#include <stdio.h>

int main(void)
{
  char ch;
  while((ch = getchar()) != EOF) putchar(ch);
  return 0;
}
