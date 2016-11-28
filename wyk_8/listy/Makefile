CC=clang
CFLAGS=-Wall --pedantic -std=c11

all: main1 main2

main1: main1.o drukuj.o dopisz_na_poczatek.o usun.o
	clang -o main1 main1.o drukuj.o dopisz_na_poczatek.o usun.o

main2: main2.o drukuj.o dopisz_na_koniec.o usun.o
	clang -o main2 main2.o drukuj.o dopisz_na_koniec.o usun.o

clean:
	rm -f main1 main2 *.o *.plist *~
