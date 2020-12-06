// listy.h

struct Węzeł
{
  int wartość;
  struct Węzeł* następny;
};

typedef struct Węzeł* Lista;

void drukuj(Lista wsk);
Lista dopisz_na_poczatek(Lista wsk, int i);
void dopisz_na_koniec(Lista* wsk, int i);
void usun(Lista* wsk);
