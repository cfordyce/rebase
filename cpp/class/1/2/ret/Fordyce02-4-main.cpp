/*----------------------------------------
  Charles Fordyce
  
  Assingment 2-4 Test Driver
  ----------------------------------------*/
#include "Fordyce02-4.h"


int
main()
{
  char * name = "Charles Fordyce";
  
  ElasticString* e = new ElasticString( name );

  e->Print();
  
  e->Concat(" and Rain ");

  e->Print();

  e->Append('H');

  e->Print();

  e->Trunc(11);

  e->Print();

  delete e;
 
  return 0;

}
