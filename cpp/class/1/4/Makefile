#  Charles Fordyce
#  July 25, 2001
#  C++ Intro Assignment 4

#----- Variables -----#

CXX = g++
CXXOBJ = -c -g -ansi -pedantic -Wall
CXXEXE = -g -ansi -pedantic -Wall



objects = Fordyce04-1.o TestClassA.o TestClassB.o TestClassC.o Fordyce04-1-main.o		



#----- Targets -----#

all : 4-1

4-1 : $(objects)
	$(CXX) $(CXXEXE) $(objects) -o Fordyce04-1.x 


Fordyce04-1.o : Fordyce04-1.h Fordyce04-1.cpp
	$(CXX) $(CXXOBJ) Fordyce04-1.cpp


Fordyce04-1-main.o : Fordyce04-1-main.cpp Fordyce04-1.o
	$(CXX) $(CXXOBJ) Fordyce04-1-main.cpp


TestClassA.o : Fordyce04-1.o TestClassA.h TestClassA.cpp
	$(CXX) $(CXXOBJ) TestClassA.cpp	

	
TestClassB.o : Fordyce04-1.o TestClassB.h TestClassB.cpp
	$(CXX) $(CXXOBJ) TestClassB.cpp


TestClassC.o : Fordyce04-1.o TestClassC.h TestClassC.cpp
	$(CXX) $(CXXOBJ) TestClassC.cpp



.PHONY : clean

clean : 
	rm Fordyce04-1.x
	rm *.o

realclean :
	rm Fordyce*~
	rm *.o