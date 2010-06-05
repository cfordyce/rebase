GNU=		String.Bag.cc String.Bag.h \
		String.FEP.VHMap.cc String.FEP.VHMap.h \
		String.FEP.Map.cc String.FEP.Map.h \
		String.SLBag.cc String.SLBag.h \
		String.SLList.cc String.SLList.h \
		String.String.AVLMap.cc String.String.AVLMap.h \
		String.String.Map.cc String.String.Map.h \
		String.defs.h

LIBOBJ=		static.o CGI.o FORM.o FEP.o String.Bag.o String.SLBag.o \
		String.FEP.Map.o String.FEP.VHMap.o \
		String.String.Map.o String.String.AVLMap.o \
		String.SLList.o FileStream.o Escape.o Text.o

LIBSRC=		CGI.cc FORM.cc FEP.cc FileStream.cc Escape.cc \
		CGI.h FORM.h FEP.h FileStream.h Escape.h \
		Text.h Text.cc Timebuf.h	\
		demo.cc filedemo.cc static.cc

MINIGPP=	mini-libg++/Regex.h mini-libg++/String.h \
		mini-libg++/builtin.h mini-libg++/std.h \
		mini-libg++/Pix.h mini-libg++/hash.cc \
		mini-libg++/Regex.cc mini-libg++/String.cc \
		mini-libg++/builtin.cc mini-libg++/error.cc \
		mini-libg++/rx.c mini-libg++/rx.h \
		mini-libg++/Makefile

DOC=		README COPYING

CC=	cc -c
CFLAGS=	-Wall -Imini-libg++ -O2 #-posix -ansi -pedantic

all:	libcgi++.a libmini-g++.a filedemo.cgi demo.cgi

rcs:	$(LIBSRC) Makefile
	ci -l -t- $(LIBSRC) Makefile
	touch rcs

clean:
	rm -f $(LIBOBJ)
	(cd mini-libg++ ; make clean)

distclean:
	rm -f $(LIBOBJ) *cgi libcgi++.a
	(cd mini-libg++ ; make distclean)

install:
	cp libcgi++.a /usr/lib
	cp libmini-g++.a /usr/lib
	(mkdir /usr/include/CGI++ >/dev/null 2>&1 || echo "/usr/include/CGI++ already exists")
	cp *.h /usr/include/CGI++
	chmod 444 /usr/include/CGI++/*
	(mkdir /usr/include/mini-libg++ >/dev/null 2>&1 || echo "/usr/include/mini-libg++ already exists")
	cp mini-libg++/*.h /usr/include/mini-libg++
	chmod 444 /usr/include/mini-libg++/*

#see above: if this doesn't work, download "gnu.tar.gz" and skip this step!
#Note: you can change the Map and Bag implementations.   I've used simple
#link-list bags, plain hash table for forms, and AVL Trees for form
#elements (to keep your Popup menus and Radio groups ordered!).
#To get your form elements ordered, you could use AVL Trees for them too.
#To reduce the size of executables, you could use Chained Hash Tables
# etc etc - see the GNU info files on genclass

gnu:	
	genclass String ref defs
	genclass String ref Bag
	genclass String ref SLBag
	genclass String ref SLList
	genclass -2 String ref String ref Map
	genclass -2 String ref String ref AVLMap
	genclass -2 String ref FEP val Map
	genclass -2 String ref FEP val VHMap
	echo "#include <String.h>" > tmp
	echo "#include <builtin.h>" >> tmp
	echo "#define StringHASH(x) hashpjw((const char*)x)" >> tmp
	cat String.defs.h >> tmp
	mv tmp String.defs.h
	echo "#include \"FEP.h\"" | cat - String.FEP.Map.h > tmp
	mv tmp String.FEP.Map.h
	touch gnu

libcgi++.a:	libcgi++.a($(LIBOBJ))
		ar rv libcgi++.a $(LIBOBJ)
		ranlib $@

libmini-g++.a:
		(cd mini-libg++ ; make)

demo.cgi:	demo.cc libcgi++.a($(LIBOBJ))
		cc $(CFLAGS) -o demo.cgi demo.cc -L. -lcgi++ -lmini-g++ -lstdc++
		strip demo.cgi

filedemo.cgi:	filedemo.cc libcgi++.a($(LIBOBJ))
		cc $(CFLAGS) -o filedemo.cgi filedemo.cc -L. -lcgi++ -lmini-g++ -lstdc++
		strip filedemo.cgi

cgi.tar.gz:	libcgi++.a
		tar czf cgi.tar.gz $(LIBSRC) Makefile $(DOC) $(GNU) $(MINIGPP)

################MakeMake auto#############################
CGI.o:	CGI.cc
	$(CC) $(CFLAGS) CGI.cc
CGI.cc:	CGI.h FileStream.h Escape.h
	touch CGI.cc

CGI.h:	FORM.h
	touch CGI.h

Escape.o:	Escape.cc
	$(CC) $(CFLAGS) Escape.cc
Escape.cc:	Escape.h
	touch Escape.cc

FEP.o:	FEP.cc
	$(CC) $(CFLAGS) FEP.cc
FEP.cc:	Escape.h FEP.h FORM.h
	touch FEP.cc

FEP.h:	String.String.AVLMap.h String.SLBag.h
	touch FEP.h

FORM.o:	FORM.cc
	$(CC) $(CFLAGS) FORM.cc
FORM.cc:	FORM.h FileStream.h
	touch FORM.cc

FORM.h:	String.FEP.VHMap.h FEP.h
	touch FORM.h

FileStream.o:	FileStream.cc
	$(CC) $(CFLAGS) FileStream.cc
FileStream.cc:	FileStream.h
	touch FileStream.cc

String.Bag.o:	String.Bag.cc
	$(CC) $(CFLAGS) String.Bag.cc
String.Bag.cc:	String.Bag.h
	touch String.Bag.cc

String.Bag.h:	String.defs.h
	touch String.Bag.h

String.FEP.Map.o:	String.FEP.Map.cc
	$(CC) $(CFLAGS) String.FEP.Map.cc
String.FEP.Map.cc:	String.FEP.Map.h
	touch String.FEP.Map.cc

String.FEP.Map.h:	FEP.h String.defs.h
	touch String.FEP.Map.h

String.FEP.VHMap.o:	String.FEP.VHMap.cc
	$(CC) $(CFLAGS) String.FEP.VHMap.cc
String.FEP.VHMap.cc:	String.FEP.VHMap.h
	touch String.FEP.VHMap.cc

String.FEP.VHMap.h:	String.FEP.Map.h
	touch String.FEP.VHMap.h

String.SLBag.o:	String.SLBag.cc
	$(CC) $(CFLAGS) String.SLBag.cc
String.SLBag.cc:	String.SLBag.h
	touch String.SLBag.cc

String.SLBag.h:	String.Bag.h String.SLList.h
	touch String.SLBag.h

String.SLList.o:	String.SLList.cc
	$(CC) $(CFLAGS) String.SLList.cc
String.SLList.cc:	String.SLList.h
	touch String.SLList.cc

String.SLList.h:	String.defs.h
	touch String.SLList.h

String.String.AVLMap.o:	String.String.AVLMap.cc
	$(CC) $(CFLAGS) String.String.AVLMap.cc
String.String.AVLMap.cc:	String.String.AVLMap.h
	touch String.String.AVLMap.cc

String.String.AVLMap.h:	String.String.Map.h
	touch String.String.AVLMap.h

String.String.Map.o:	String.String.Map.cc
	$(CC) $(CFLAGS) String.String.Map.cc
String.String.Map.cc:	String.String.Map.h
	touch String.String.Map.cc

String.String.Map.h:	String.defs.h
	touch String.String.Map.h

bind.o:	bind.cc
	$(CC) $(CFLAGS) bind.cc
bind.cc:	bind.h
	touch bind.cc

bind.h:	String.SLBag.h
	touch bind.h

demo.o:	demo.cc
	$(CC) $(CFLAGS) demo.cc
demo.cc:	CGI.h
	touch demo.cc

file2.o:	file2.cc
	$(CC) $(CFLAGS) file2.cc
file2.cc:	CGI.h
	touch file2.cc

filedemo.o:	filedemo.cc
	$(CC) $(CFLAGS) filedemo.cc
filedemo.cc:	CGI.h
	touch filedemo.cc

static.o:	static.cc
	$(CC) $(CFLAGS) static.cc
static.cc:	CGI.h
	touch static.cc

test.o:	test.cc
	$(CC) $(CFLAGS) test.cc
test.cc:	Escape.h
	touch test.cc

testform.o:	testform.cc
	$(CC) $(CFLAGS) testform.cc
testform.cc:	CGI.h
	touch testform.cc

zz.o:	zz.cc
	$(CC) $(CFLAGS) zz.cc

Text.o:		Text.cc Text.h
	$(CC) $(CFLAGS) Text.cc
