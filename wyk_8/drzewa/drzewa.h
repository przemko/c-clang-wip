// drzewa.h

struct Węzeł {
	int wartość;
	struct Węzeł *lewe;
	struct Węzeł *prawe;
};

typedef struct Węzeł *Drzewo;

void drukuj_prefiksowo(Drzewo wsk);
void drukuj_infiksowo(Drzewo wsk);
void drukuj_postfiksowo(Drzewo wsk);
void wstaw_uporzadkowane(Drzewo *wsk, int i);
void usun(Drzewo *wsk);
