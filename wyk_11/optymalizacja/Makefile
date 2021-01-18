all: f1.s f2.s f3.s f4.s

f1.s: f1.c
	clang -O3 -S f1.c

f2.s: f2.c
	clang -O3 -S f2.c

f3.s: f3.c
	clang -O3 -S f3.c

f4.s: f4.c
	clang -O3 -S f4.c

clean:
	rm -f *.s *~
