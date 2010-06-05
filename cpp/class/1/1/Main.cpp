//----------------------------------------------------------- 
// Module name: 
//     Main.cpp 
// 
// Description: 
//    Class implementation for Homework #1. Counts the number 
// 
// Author: 
//    Bruce M. Reynolds 
//----------------------------------------------------------- 
#include "Homework1.h"
#include "CountLines.h"

//----------------------------------------------------------- 
// main( int argc, char **argv ) 
// 
// Purpose: 
//    Execute all of the functions for the homework assigment.
// 
// Parameters: 
//    int argc      the number of arguments passed in
//    char **argv   array of arguments; first argument is a
//                  filename
// 
// Returns:
//    int 0
//    
// 
// Method: 
//    Execute each function. Pass the filename to the functions
//    that need it.
//    
//----------------------------------------------------------- 
int main( int argc, char **argv )
{
	goto test;

	Func1_1();
	Func1_2();
	Func1_3();
	Func1_4();
	Func1_5();

test:
	CountLines( argc, argv );
	return 0;
}
