# Wymaga zainstalowania pakietu libx11-dev.

CC=clang
CFLAGS=-Wextra -pedantic -std=c11 -I/usr/include/X11
LDFLAGS=-I/usr/lib/X11 -lX11 -lm

PROGS=sierpinski triangles julia

all: $(PROGS)

clean:
	rm -f $(PROGS) *.o *~

