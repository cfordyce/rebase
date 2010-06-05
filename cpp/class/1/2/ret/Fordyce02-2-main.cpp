/*----------------------------------------
  Charles Fordyce
  
  Assingment 2-2 Test Driver
  ----------------------------------------*/

#include <iostream>
#include "Fordyce02-2.h"

int f1();
int f2();

int
main()
{
  cout << "Entry: main" << endl;
  Add a;

////////////////////////////////////////////////////////////////
// bmr
// ... Instantiate your class on the stack in main and function f1. 
// Instantiate your class on the heap (using new and delete) in function f2.

  Add *aObj = new Add;
  f1();
  delete aObj;
  cout << "Exit: main" << endl;
  return 0;
}


int f1()
{
  cout << "Entry: f1" << endl;
  Add a;
  f2();
  cout << "Exit: f1" << endl;
  return 0;
}  

int f2()
{
  cout << "Entry: f2" << endl;
  Add a;
  cout << "Exit: f2" << endl;
  return 0;
}
