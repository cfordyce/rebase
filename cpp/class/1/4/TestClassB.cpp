/*------------------
  Test Class B
-------------------*/

#include "TestClassB.h"
#include "Fordyce04-1.h"


TestB::TestB()
{
  p = new Probe("TestB::TestB");
}

TestB::~TestB()
{
  p->deadObj("TestB::TestB");
  delete p;
}

void TestB::testBFuncA()
{
  p->addFuncCall("testBFuncA");
}

void TestB::testBFuncB()
{
  p->addFuncCall("testBFuncB");
}
