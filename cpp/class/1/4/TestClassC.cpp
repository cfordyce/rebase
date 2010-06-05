/*------------------
  Test Class C
-------------------*/

#include "TestClassC.h"
#include "Fordyce04-1.h"


TestC::TestC()
{
  p = new Probe("TestC::TestC");
}

TestC::~TestC()
{
  p->deadObj("TestC::TestC");
  delete p;
}

void TestC::testCFuncA()
{
  p->addFuncCall("testCFuncA");
}

void TestC::testCFuncB()
{
  p->addFuncCall("testCFuncB");
}
