/*---------------------------------
  Charles Fordyce

  Assignment 4-1  Header File
  --------------------------------*/
  

#ifndef FORDYCE_04_1_H
#define FORDYCE_04_1_H

#include <map>
#include <string>

class Probe 
{
public:
  
  // Construct a Probe for a specific class
  Probe(const string);
  
  // Destructor
  ~Probe() {};
  
  
  // Call this method when you want to add new objects to an existing probe. The new 
  // class name is the argument
  // Example:  probe->addObj("MyClass");

  void addObj(const string);

  // Call this method when deleteing the class, class name is the argument
  // Example:  probe->DeadObj("MyClass");
  
  void deadObj(const string);
  

  // Call this method when you call the method you're tracking.
  // Supply the fully qualified name:  probe->AddFuncCall("MyClass::MyCoolFunction");
  
  void addFuncCall(const string);
  

  // Prints tracking information for all data recieved.
  // First, the history of all classes ever created is printed.
  // Second, the history of all existing objects is printed.
  // Third, the history of all probed functions is called.

  void print();
  
 private:
  
  static map<string, int> history;
  static map<string, int> current;
  static map<string, int> function;

};

#endif
