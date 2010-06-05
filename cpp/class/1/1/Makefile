#  Charles Fordyce
#  July 1, 2001
#  C++ Intro Assignment 1

CXX = g++
CXXFLAGS = -g -ansi -pedantic -Wall

#----- Targets -----#

all : 1-1 1-2 1-3 1-4 1-5 1-6

1-1 : Fordyce01-1.cc 
	$(CXX) $(CXXFLAGS) Fordyce01-1.cc -o Fordyce01-1.x

1-2 : Fordyce01-2.cc
	$(CXX) $(CXXFLAGS) Fordyce01-2.cc -o Fordyce01-2.x

1-3 : Fordyce01-3.cc
	$(CXX) $(CXXFLAGS) Fordyce01-3.cc -o Fordyce01-3.x

1-4 : Fordyce01-4.cc
	$(CXX) $(CXXFLAGS) Fordyce01-4.cc -o Fordyce01-4.x

1-5 : Fordyce01-5.cc
	$(CXX) $(CXXFLAGS) Fordyce01-5.cc -o Fordyce01-5.x

1-6 : Fordyce01-6.cc
	$(CXX) $(CXXFLAGS) Fordyce01-6.cc -o Fordyce01-6.x

.PHONY : clean

clean : 
	rm Fordyce01-*.x

realclean :
	rm Fordyce*~
