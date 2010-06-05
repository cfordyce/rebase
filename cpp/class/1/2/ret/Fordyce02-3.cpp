/*----------------------------------------
  Charles Fordyce
  
  Assingment 2-3 Source File
  ----------------------------------------*/

#include <fstream>
#include <string>
#include "Fordyce02-3.h"


Histogram::Histogram()
{
  a = d = p = w = 0;
}

void Histogram::readData( ifstream& in )
{
  char c;

  while ( in.get( c ))
    {
      if ( isalpha( c ))
	a++;
      else if ( isdigit( c ))
	d++;
      else if ( ispunct( c ))
	p++;
      else if ( isspace( c ))
	w++;
    }
}

void Histogram::printAll()
{
  printAlpha();
  printDigits();
  printPunct();
  printWhite();
}

void Histogram::printAlpha()
{
  cout << "Alpha Chars [" << a << "]:" ;
/////////////////////////////////////////////////////////////////////////////
// bmr
// Indices rarely start at 1 and end at "val" in C++. Almost 
// always start at 0 and end at "val-1". Just style, but it
// gives away that you might not be a "native" C++er.
/////////////////////////////////////////////////////////////////////////////
// bmr
// Scaling would have been nice here. I think that if I send it a large file
// (200K) I get an output problem?
  for(int i = 1; i <= a; ++i)
    cout << "*";
  cout << "\n" << endl;
}

void Histogram::printDigits()
{
  cout << "Digits [" << d << "]:" ;
  for(int i = 1; i <= d; ++i)
    cout << "*";
  cout << "\n" << endl;
}

void Histogram::printPunct()
{
  cout << "Punct Chars [" << p << "]:" ;
/////////////////////////////////////////////////////////////////////////////
// bmr
// Style: I would recommend follow the style that every statement 
// (even single lines) must be a compound statement (with braces). 
  for(int i = 1; i <= p; ++i)
    cout << "*";
  cout << "\n" << endl;
}

void Histogram::printWhite()
{
  cout << "Whitespace Chars [" << w << "]:" ;
  for(int i = 1; i <= w; ++i)
    cout << "*";
  cout << "\n" << endl;
}
