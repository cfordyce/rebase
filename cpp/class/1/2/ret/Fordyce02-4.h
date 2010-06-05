/*----------------------------------------
  Charles Fordyce
  
  Assingment 2-4 Header File
  ----------------------------------------*/

#ifndef FORDYCE_02_4_h
#define FORDYCE_02_4_h

#include <vector>
#include "Fordyce02-4.h"

////////////////////////////////////////////////////////////////
// bmr
// This code, in general, is woefully underdocumented. There is 
// no excuse to omit function and file headers. See the class 
// website for minimum expectations. If you produce under-
// documented code, you will
// -- not be able to understand your own code months later 
//    (or even weeks or days)
// -- be disliked and reviled by your teammates
// -- doom your code to being deleted, replaced and rewritten
//    by other programmers
// -- never get the chance to see your code reused outside of
//    its original application
// Consider this: I am the only instructor in the C++ certificate
// program who will give you a passing grade for an undocumented
// solution (and I am not signed up to teach Intermediate or 
// Advanced anytime soon).

class ElasticString {
  
 public:
  
  ElasticString( char* );
  ~ElasticString() {};
  
/////////////////////////////////////////////////////////////////////////////
// bmr
// -- By convention, many C++ programmers lower
// case method names. Firstly, follow
// the convention of the group with which you work. Otherwise, if you have
// no preference, I would recommend following the C++ conventions: 
//   -- lower case for variables, members and methods (eg. <printInfo()> method
//      or <isPrintable> member of <ExampleClass>)
/////////////////////////////////////////////////////////////////////////////
// bmr
// I notice that you used lowercase method names in Histogram...
  void Concat( char* );
  void Append( char );
  void Trunc( int );
  void Print();
  
 private:
  vector<char> s;
  
};

#endif
