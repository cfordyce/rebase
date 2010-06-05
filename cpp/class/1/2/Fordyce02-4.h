/*----------------------------------------
  Charles Fordyce
  
  Assingment 2-4 Header File
  ----------------------------------------*/

#ifndef FORDYCE_02_4_h
#define FORDYCE_02_4_h

#include <vector>
#include "Fordyce02-4.h"

class ElasticString {
  
 public:
  
  ElasticString( char* );
  ~ElasticString() {};
  
  void Concat( char* );
  void Append( char );
  void Trunc( int );
  void Print();
  
 private:
  vector<char> s;
  
};

#endif
