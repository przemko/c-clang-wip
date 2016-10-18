// switch.c
//
// kompilacja: clang switch2.c
// kompilacja konczy sie bledem kompilatora!

#include <stdio.h>

int main(void)
{
  switch(1)
  {
    case 1: printf("ok\n");
    for(int i = 0; i < 10; i++)
      default: printf("i=%d\n", i);
  }
  return 0;
}
