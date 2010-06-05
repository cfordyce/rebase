/*------------------
  Test Class A
-------------------*/

#include "TestClassA.h"
#include "Fordyce04-1.h"


TestA::TestA()
{
  p = new Probe("TestA::TestA");
}

TestA::~TestA()
{
  p->deadObj("TestA::TestA");
  delete p;
}

void TestA::testAFuncA()
{
  p->addFuncCall("testAFuncA");
}

void TestA::testAFuncB()
{
  p->addFuncCall("testAFuncB");
}
