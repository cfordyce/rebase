/*----------------------------------------
  Charles Fordyce
  
  Assingment 2-4  Source File
  ----------------------------------------*/

#include <iostream>
#include <vector>
#include "Fordyce02-4.h"


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
  for ( int i = 0; i < t; ++i )
    s.pop_back();
}


void ElasticString::Print()
{
  for ( int i = 0; i < s.size(); i++  )
    cout << s[i];

  cout << endl;
}
