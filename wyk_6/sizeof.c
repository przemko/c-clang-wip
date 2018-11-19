#include <stdio.h>

void f(int n, int *tab) {
  printf("   f: %u\n", sizeof(tab));
}

void g(int n, int tab[]) {
  printf("   g: %u\n", sizeof(tab));
}

void h(int n, int tab[n]) {
  printf("   h: %u\n", sizeof(tab));
}

int main(void) {
  int n = 10;
  int tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  printf("main: %u\n", sizeof(tab));
  f(n, tab);
  g(n, tab);
  h(n, tab);
  return 0;
}
