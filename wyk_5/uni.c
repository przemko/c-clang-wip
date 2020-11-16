// uni.c

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Mężczyzna
{
  char imię[20];
  char nazwisko[20];
};

struct Kobieta
{
  char imię[20];
  char nazwisko[20];
  char nazwisko_panieńskie[20];
};

union Wariant
{
  struct Mężczyzna m;
  struct Kobieta k;
};

struct Osoba
{
  bool jest_mężczyzną;
  union Wariant w;
};

void drukuj (struct Osoba o)
{
  if(o.jest_mężczyzną)
    printf("%s %s\n", o.w.m.imię, o.w.m.nazwisko);
  else
    printf("%s %s z domu %s\n", o.w.k.imię, o.w.k.nazwisko,
                                o.w.k.nazwisko_panieńskie);
}

int main(void)
{
  struct Osoba pracownik;
  pracownik.jest_mężczyzną = false;
  strcpy(pracownik.w.k.imię,                "Anna");
  strcpy(pracownik.w.k.nazwisko,            "Nowak");
  strcpy(pracownik.w.k.nazwisko_panieńskie, "Kowalska");
  drukuj(pracownik);
  return 0;
}

