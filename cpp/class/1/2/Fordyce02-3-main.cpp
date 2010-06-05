/*----------------------------------------
  Charles Fordyce
  
  Assingment 2-3 Test Driver
  ----------------------------------------*/


#include <fstream>
#include "Fordyce02-3.h"


int
main()
{
  ifstream inFile( "/home/chas/class/cpp1/2/test02-3.txt", ios::in );
  
  Histogram* h = new Histogram;

  h->readData(inFile);

  h->printAll();

  delete h;
 
  return 0;

}
