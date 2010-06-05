/*---------------------------------
  Charles Fordyce

  Assignment 4-1  Source File
  --------------------------------*/

#include <map>
#include <string>
#include <iostream>

#include "Fordyce04-1.h"


// Define Static Members
// I chose string over char* because it has a default compare function

map<string, int> Probe::history;
map<string, int> Probe::current;
map<string, int> Probe::function;



// Construct a Probe for a specific class

Probe::Probe(const string name)
{
  ++current[name];
  ++history[name];
}


// Call this method when you want to add new objects to an existing probe. The new 
// class name is the argument
// Example:  probe->addObj("MyClass");

void Probe::addObj(const string name)
{
  ++current[name];
  ++history[name];
}


// Call this method when deleteing the class, class name is the argument
// Example:  probe->deadObj("MyClass");

void Probe::deadObj(const string name)
{
  long int x = current[name];
  
  if ( x > 0 )
    --current[name];
}


// Call this method when you call the method you're tracking.
// Supply the fully qualified name:  probe->addFuncCall("MyClass::MyCoolFunction");

void Probe::addFuncCall(const string func)
{
  ++function[func];
}


// Prints tracking information for all data recieved.
// First, the history of all classes ever created is printed.
// Second, the history of all existing objects is printed.
// Third, the history of all probed functions is called.

void Probe::print()
{
  typedef map<const string, int>::const_iterator CI;
  
  cout << "Here's the history of all class instantiations:" << endl;
  for ( CI p = history.begin(); p != history.end(); ++p )
    cout << p->first << " = " << p->second << endl;
  
  cout << endl << "Here's the history of existing (live) class instantiations:" << endl;
  for ( CI p = current.begin(); p != current.end(); ++p )
    cout << p->first << " = " << p->second << endl;
  
  cout << endl << "Here's the history of all function calls:" << endl;
  for ( CI p = function.begin(); p != function.end(); ++p )
    cout << p->first << " = " << p->second << endl;

  cout << endl;
}
