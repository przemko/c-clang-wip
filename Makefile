CC=clang
CFLAGS=-Wall --pedantic -std=c11
LDFLAGS=-lm

PROGS=doublemacheps euklides floatmacheps hanoi hetmany \
pierwsza plecak rozeuklides sito skoczek scalsort wstawsort \
sumy wyszukliniowe wyszukbinarne znajdz1 znajdz2

all: $(PROGS)

analiza:
	clang --analyze *.c

check:
	cppcheck --std=c11 *.c

clean:
	rm -f $(PROGS) *.o *.plist *~

