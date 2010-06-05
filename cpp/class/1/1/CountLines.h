//----------------------------------------------------------- 
// Module name: 
//     CountLines.h 
// 
// Description: 
//    Function declarations for Homework #1-6: to counts the 
//    lines of code in a source code file. 
// 
// Author: 
//    Bruce M. Reynolds 
//----------------------------------------------------------- 

void CountLines( int argc, char **argv );
bool IsCountable( const char* const buf );
bool IsBlank( const char* const buf );
bool IsComment( const char* const buf );

