CC=clang
CFLAGS=-Wall --pedantic -std=c11
LDFLAGS=

PROGS=doublemacheps euklides floatmacheps hanoi hetmany \
pierwsza plecak rozeuklides sito skoczek scalsort wstawsort \
sumy wyszukliniowe wyszukbinarne znajdz1 znajdz2

all: $(PROGS)

analiza:
	clang --analyze *.c

clean:
	rm -f $(PROGS) *.o *.plist *~

