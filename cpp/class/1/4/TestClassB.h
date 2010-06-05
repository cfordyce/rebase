#ifndef TESTCLASS_B_H
#define TESTCLASS_B_H

#include "Fordyce04-1.h"


class TestB
{
 public:

  TestB();
  ~TestB();
  
  void testBFuncA();
  void testBFuncB();
  
 private:
  
  Probe *p;
};

#endif
