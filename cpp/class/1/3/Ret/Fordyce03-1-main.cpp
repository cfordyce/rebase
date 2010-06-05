/*----------------------------------------
  Charles Fordyce
  
  Assingment 3-1 Test Driver
  ----------------------------------------*/
#include "Fordyce03-1.h"
#include <iostream>

int
main()
{
  int num[] = {10,20,30,40,50};

/////////////////////////////////////////////////////////////////////////////
// bmr
// In a situation where the object will be created at the beginning of 
// scope, and destroyed at the end of a scope, it is probably preferable
// to simply allow the variable to be local, and let the compiler
// handle its destruction at the end of scope: "Histogram h;".
  ElasticIntArray* e = new ElasticIntArray( num, 5 ); 

  e->Print();

  e->Append(60);

  e->Print();

  e->Remove(3);

  e->Print();

  e->Insert(70,1);
  
  e->Print();

  e->Value(0);


  delete e;
 
  return 0;

}
