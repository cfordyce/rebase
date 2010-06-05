//----------------------------------------------------------- 
// Module name: 
//     CountLines.cpp 
// 
// Description: 
//    Write a program that counts the lines of code in a source 
//    code file. Do not count blank lines and C++-style comment 
//    lines (where the first non-blank characters are "//"). 
//    Read the file from the standard input stream using the cin 
//    object (or use fstream). Report the number of lines to the 
//    standard output stream using the cout object.
// 
// Author: 
//    Bruce M. Reynolds 
//----------------------------------------------------------- 
#include <iostream>
#include <fstream>
#include <assert.h>
using namespace std;

#include "CountLines.h"

//----------------------------------------------------------- 
// CountLines( int argc, char **argv ) 
// 
// Purpose: 
//    Write a program that counts the lines of code in a source 
//    code file. 
// 
// Parameters: 
//    int argc      the number of arguments passed in
//    char **argv   array of arguments; first argument is a
//                  filename
// 
// Returns: 
//    None
// 
// Method:
//    open the file for reading
//    while ( there are lines in the file )
//    {
//        read a line from the file
//        if ( the line is countable )
//        {
//            count the line
//        }
//    }
//    report the number of lines
//     
//----------------------------------------------------------- 
void CountLines( int argc, char **argv )
{
	assert( argc == 2 );
	const char *filename = argv[1]; 	// filename: the name of the file to open
	ifstream is( filename );			// is: input file stream

	if ( is )
	{
		int count = 0;					// count: running total of countable lines
		
		while ( !is.eof() )
		{
			// assumes lines are 256 chars or less
			const int BUFSIZE = 257;	// BUFSIZE: size of buffer to hold the input line 
			char buf[ BUFSIZE ];		// buf: 	holds the line input

			// get a line of input, and count it if it is countable
			is.getline( buf, BUFSIZE );
			if ( !IsBlank( buf ) && !IsComment( buf ) )
			{
				++count;
			}

			// for debugging, see each line with the count
			cout << count << ":  " << buf << endl;
		}
		cout << "Number of lines is " << count << endl;
	}
	else
	{
		cout << "Unable to open file " << filename << endl;
	}
	cout << endl;
}

//----------------------------------------------------------- 
// IsCountable( const char* const buf )
// 
// Purpose: 
//    returns true if the line of code is countable (a blank
//    line or a C++-style comment line
// 
// Parameters: 
//    char *        the line to be examined
// 
// Returns: 
//    bool          true if the line is blank or a comment
// 
// Method: 
//    Combines the algorithms to search for a blank or comment
//    line. This is the preferred method; it is more efficient,
//    and shares the code that each method has in common.
//
//    Skip whitespace. If there are characters left on the 
//    line, and they are not "//", then the line is countable.
//    
//----------------------------------------------------------- 
bool IsCountable( const char* const buf )
{
	bool bCountable = false;			// bCountable: turns true if the line is countable
	int charDx = 0; 					// charDx: index into the line as each char is scanned
	
	// skip over white space at the beginning of the line
	while ( isspace( buf[ charDx ] ) ) 
	{
		++charDx;
	}
	
	// if there are characters left on the line
	if ( buf[ charDx ] != '\0' )
	{
		// if the characters are not "//", count the line 
		if ( buf[ charDx ] != '/' || buf[ charDx+1 ] != '/' )
		{
			bCountable = true;
		}
	}
	return bCountable;
}

//----------------------------------------------------------- 
// IsBlank( const char* const buf )
// 
// Purpose: 
//    return true if the line of code is blank 
// 
// Parameters: 
//    char *        the line to be examined
// 
// Returns: 
//    bool          true if the line is blank
// 
// Method: 
//    Skip whitespace. If there are no other characters
//    on the line, then it is blank.
//    
//----------------------------------------------------------- 
bool IsBlank( const char* const buf )
{
	bool bBlank = true;					// bBlank: turns false if the line is not blank
	const int nLength = strlen( buf );	// nLength: the length of the line

	if ( nLength != 0 )
	{
		int charDx = 0;					// charDx: index into the line as each char is scanned

		// skip over white space at the beginning of the line
		while ( isspace( buf[ charDx ] ) )
		{
			++charDx;
		}

		// if there are no characters remaining, the line is blank
		bBlank = nLength == charDx;
	}	
	return bBlank;	
}

//----------------------------------------------------------- 
// IsComment( const char* const buf )
// 
// Purpose: 
//    return true if the line of code is a C++-style comment
// 
// Parameters: 
//    char *        the line to be examined
// 
// Returns: 
//    bool          true if the line is a comment
// 
// Method: 
//    Skip whitespace. If there are at least two characters
//    on remaining on the line, and they are "//", then the
//    line is a comment.
//    
//----------------------------------------------------------- 
bool IsComment( const char* const buf )
{
	bool bComment = false;				// bComment: turns true if the line is a comment
	const int nLength = strlen( buf );	// nLength: the length of the line

	if ( nLength != 0 )
	{
		int charDx = 0;					// charDx: index into the line as each char is scanned

		// skip over white space at the beginning of the line
		while ( isspace( buf[ charDx ] ) )
		{
			++charDx;
		}

		// if the remaining characters are "//", the line is a comment
		if ( nLength >= charDx + 2 )
		{
			bComment = buf[ charDx ] == '/' && buf[ charDx+1 ] == '/';
		}
	}	
	return bComment;
}

