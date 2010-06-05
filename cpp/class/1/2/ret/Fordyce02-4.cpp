/*----------------------------------------
  Charles Fordyce
  
  Assingment 2-4  Source File
  ----------------------------------------*/

#include <iostream>
#include <vector>
#include "Fordyce02-4.h"


/////////////////////////////////////////////////////////////////////////////
// bmr
// This is a boring solution which probably didn't teach you very much.
// One of the most important things to learn with C++ is management of
// remotely-owned resources (memory, file handles, window handles, thread
// ids, etc.). By using a data structure which manages the memory for you,
// you lose the practice with new, delete, a dtor, etc.


////////////////////////////////////////////////////////////////
// bmr
// Perhaps the arguments should be const.
ElasticString::ElasticString( char* str )
{
  while (*str)
    s.push_back(*str++);
}

void ElasticString::Concat( char* catstr )
{
  while ( *catstr )
    s.push_back(*catstr++);
}

void ElasticString::Append( char c )
{
  s.push_back( c );
}

void ElasticString::Trunc( int t )
{
/////////////////////////////////////////////////////////////////////////////
// bmr
// Perhaps std::remove...
  for ( int i = 0; i < t; ++i )
    s.pop_back();
}


void ElasticString::Print()
{
/////////////////////////////////////////////////////////////////////////////
// bmr
// Definitely std::copy...
  for ( int i = 0; i < s.size(); i++  )
    cout << s[i];

  cout << endl;
}
