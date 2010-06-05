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
