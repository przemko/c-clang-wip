// sumator.c
//
// Program czyta liczby rzeczywiste i oblicza ich sumę.
// Jeśli nie podano parametru wywołania, to czyta ze standardowego wyjścia.
// W przeciwnym przypadku czyta z pliku, którego nazwę podano.
// Program kończy czytanie gdy skończy się strumień znaków lub nie może 
// zinterpretować wejścia jako liczba rzeczywista.

#include <stdio.h>
#include <stdbool.h>

int main(int argc, char **argv)
{
  FILE *fp;
  if(argc < 2)
    fp = stdin;
  else
    fp = fopen(argv[1], "r");
  
  double suma = 0.0;
  
  while(true)
    {
      double wartość;
      int wynik = fscanf(fp, "%lf", &wartość);
      if(wynik < 1)
	break;
      suma = suma + wartość;
    }
  fclose(fp);
  printf("suma = %f\n", suma);
  return 0;
}

