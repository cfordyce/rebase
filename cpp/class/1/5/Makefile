#  Charles Fordyce
#  July 11, 2001
#  C++ Intro Assignment 3


CXX = g++
CXXOBJ = -c -g -ansi -pedantic -Wall
CXXEXE = -g -ansi -pedantic -Wall
#----- Targets -----#

all : 5-1

5-1 : Fordyce05-1.h 
	$(CXX) $(CXXEXE) Fordyce05-1-main.cpp -o Fordyce05-1.x


.PHONY : clean

clean : 
	rm Fordyce05-*.x

realclean :
	rm Fordyce*~
