/*----------------------------------------
  Charles Fordyce
  
  Assingment 2-3 Header File
  ----------------------------------------*/

#ifndef FORDYCE_02_3_H
#define FORDYCE_02_3_H

#include <fstream>


class Histogram {

public:
  
  Histogram();
  
  ~Histogram(){};
  
  void readData( ifstream& );

  // Prints histogram for all: Alpha,Digits,Punctuation,Whitespace
  void printAll();

  // Print histogram for Alpha
  void printAlpha();

  // Print histogram for Digits
  void printDigits();

  // Print histogram for Punctuation
  void printPunct();

  // Print histogram for Whitespace
  void printWhite();
  
  
private:
  
/////////////////////////////////////////////////////////////////////////////
// bmr
// -- No one-letter variable names! They hamper reading and understanding code.
// Use meaningful variable names.
  int a,d,p,w;
};

#endif
