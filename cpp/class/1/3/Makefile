#  Charles Fordyce
#  July 11, 2001
#  C++ Intro Assignment 3


CXX = g++
CXXOBJ = -c -g -ansi -pedantic -Wall
CXXEXE = -g -ansi -pedantic -Wall
#----- Targets -----#

all : 3-1 3-2 3-3 3-4

3-1 : Fordyce03-1.cpp 
	$(CXX) $(CXXEXE) Fordyce03-1.cpp Fordyce03-1-main.cpp -o Fordyce03-1.x

3-2 : Fordyce03-2.cpp
	$(CXX) $(CXXEXE) Fordyce03-2.cpp Fordyce03-3-main.cpp -o Fordyce03-2.x

3-3 : Fordyce03-3.cpp
	$(CXX) $(CXXEXE) Fordyce03-3.cpp Fordyce03-3-main.cpp -o Fordyce03-3.x

3-4 : Fordyce03-4.cpp
	$(CXX) $(CXXEXE) Fordyce03-4.cpp Fordyce03-4-main.cpp -o Fordyce03-4.x

3-1o: Fordyce03-1.cpp
	$(CXX) $(CXXOBJ) Fordyce03-1.cpp



.PHONY : clean

clean : 
	rm Fordyce03-*.x

realclean :
	rm Fordyce*~
