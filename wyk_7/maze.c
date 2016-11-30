// maze.c
//
// Generowanie nieskończonego losowego "labiryntu".
//
// Na podstawie książki pt. "10 PRINT CHR$(205.5+RND(1)); : GOTO 10"
// http://www.mos6502.com/friday-commodore/a-world-in-a-single-line-of-code/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  srand(time(NULL));
  while(1)
  {
    printf(rand()%2?"\u2571":"\u2572");
    fflush(stdin);
  }
}
