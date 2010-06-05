/*----------------------------------------
  Charles Fordyce

  Assingment 4-1 Test Driver
  ----------------------------------------*/

#include "Fordyce04-1.h"

#include "TestClassA.h"
#include "TestClassB.h"
#include "TestClassC.h"

int main()
{
  Probe p("Test Driver");
  TestA a;
  TestB b;
  TestC c;


  a.testAFuncA();
  a.testAFuncB();
    
  b.testBFuncA();
  b.testBFuncB();
  
  c.testCFuncA();
  c.testCFuncB();
  
  // Should all be 1's
  p.print();
  
  /////////////////////////////
  // Round 2

  TestA *pca = new TestA();
  TestB *pcb = new TestB();
  TestC *pcc = new TestC();
  
  pca->testAFuncA();
  pca->testAFuncB();
    
  pcb->testBFuncA();
  pcb->testBFuncB();
  
  pcc->testCFuncA();
  pcc->testCFuncB();

  // Should all be 2's
  p.print();
  

  ////////////////////////
  // It's all over
  
  delete pca;
  delete pcb;
  delete pcc;

  // History should be 2's, function should be 2's and current will be 1's
  p.print();

  return 0;
}
