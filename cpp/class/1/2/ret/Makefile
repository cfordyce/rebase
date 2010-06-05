#  Charles Fordyce
#  July 11, 2001
#  C++ Intro Assignment 2


CXX = g++
CXXOBJ = -c -g -ansi -pedantic -Wall
CXXEXE = -g -ansi -pedantic -Wall
#----- Targets -----#

all : 2-1 2-2 2-3 2-4

2-1 : Fordyce02-1.cpp 
	$(CXX) $(CXXEXE) Fordyce02-1.cpp -o Fordyce02-1.x

2-2 : Fordyce02-2.cpp
	$(CXX) $(CXXEXE) Fordyce02-2.cpp Fordyce02-2-main.cpp -o Fordyce02-2.x

2-3 : Fordyce02-3.cpp
	$(CXX) $(CXXEXE) Fordyce02-3.cpp Fordyce02-3-main.cpp -o Fordyce02-3.x

2-4 : Fordyce02-4.cpp
	$(CXX) $(CXXEXE) Fordyce02-4.cpp Fordyce02-4-main.cpp -o Fordyce02-4.x




.PHONY : clean

clean : 
	rm Fordyce02-*.x

realclean :
	rm Fordyce*~
