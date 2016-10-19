// ptr.c
//
// wynik analizy statycznej:
//
// $ clang --analyze ptr.c 
// ptr.c:23:18: warning: Use of memory after it is freed
//   printf("%d\n", *y); // ta instrukcja nie ma sensu
//                  ^~
// 1 warning generated.

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int* x;
  int* y;
  x = malloc(sizeof(int));
  *x = 13;
  y = x;
  printf("%d\n", *y);
  free(x);
  printf("%d\n", *y); // ta instrukcja nie ma sensu
  return 0;
}

