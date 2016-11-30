// maze.c
//
// Generowanie nieskończonego losowego "labiryntu".
//
// Na podstawie książki pt. "10 PRINT CHR$(205.5+RND(1)); : GOTO 10"
// http://10print.org

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  srand(time(NULL));
  while(1)
  {
    printf(rand()&1?"\u2571":"\u2572");
    fflush(stdin);
  }
}
