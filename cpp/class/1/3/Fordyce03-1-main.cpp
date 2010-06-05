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
