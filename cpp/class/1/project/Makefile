#  Charles Fordyce
#  Aug 24, 2001
#  C++ Intro Project

#----- Variables -----#

CXX = g++
CXXOBJ = -c -g -ansi -pedantic -Wall
CXXEXE = -g -ansi -pedantic -Wall



objects = Html.o Cgi.o UserData.o Main.o


#----- Targets -----#

all : $(objects)
	$(CXX) $(CXXEXE) $(objects) -o Project.cgi 

Html.o : Html.h Html.cpp
	$(CXX) $(CXXOBJ) Html.cpp

Cgi.o : Cgi.h Cgi.cpp
	$(CXX) $(CXXOBJ) Cgi.cpp

UserData.o : UserData.h UserData.cpp
	$(CXX) $(CXXOBJ) UserData.cpp

Main.o : Main.cpp
	$(CXX) $(CXXOBJ) Main.cpp


.PHONY : clean

clean : 
	rm user.cgi
	rm *.o

realclean :
	rm *~
	rm *.o
	rm *.cgi
