#ifndef TESTCLASS_C_H
#define TESTCLASS_C_H

#include "Fordyce04-1.h"


class TestC
{
 public:

  TestC();
  ~TestC();
  
  void testCFuncA();
  void testCFuncB();
  
 private:
  
  Probe *p;
};

#endif
