CC=clang
CFLAGS=-Wall --pedantic -std=c11

all: main

main: main.o drukuj_prefiksowo.o drukuj_infiksowo.o drukuj_postfiksowo.o \
      wstaw_uporzadkowane.o usun.o
	clang -o main main.o drukuj_prefiksowo.o drukuj_infiksowo.o \
		drukuj_postfiksowo.o wstaw_uporzadkowane.o usun.o

clean:
	rm -f main *.o *.plist *~
