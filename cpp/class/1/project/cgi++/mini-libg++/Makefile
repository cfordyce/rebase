# This wants GNU Make
#
OBJECTS=	String.o Regex.o builtin.o error.o hash.o rx.o

CC=	cc -c
CFLAGS=	-I. -Wall -O2 #-posix -ansi -pedantic

rx.o:	rx.c
	$(CC) $(CFLAGS) rx.c

%.o: %.cc
	$(CC) $(CFLAGS) $<

../libmini-g++.a:	$(OBJECTS)
		ar rv ../libmini-g++.a $(OBJECTS)
		ranlib $@

clean:
	rm *o

distclean:
	rm *o
	rm ../libmini-g++.a
