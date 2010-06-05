/*----------------------------------------
  Charles Fordyce
  
  Assingment 5-1 Test Driver
  ----------------------------------------*/
#include "Fordyce05-1.h"
#include <iostream>

int
main()
{
  int num[] = {10,20,30,40,50};

  ElasticArray<int> e( num, 5 ); 

  e.Print();

  e.Append(60);

  e.Print();

  e.Remove(3);

  e.Print();

  e.Insert(70,1);
  
  e.Print();

  e.Value(0);

  return 0;

}
