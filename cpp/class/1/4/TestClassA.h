#ifndef TESTCLASS_A_H
#define TESTCLASS_A_H

#include "Fordyce04-1.h"


class TestA
{
 public:

  TestA();
  ~TestA();
  
  void testAFuncA();
  void testAFuncB();
  
 private:
  
  Probe *p;
};

#endif
