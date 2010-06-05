/*----------------------------------------
  Charles Fordyce
  
  Assingment 2-1
  ----------------------------------------*/

#include <string>

////////////////////////////////////////////////////////////////
// bmr
// No tests for this class?? It's not that you forgot to include
// a file, I can see from your makefile.
class Add {
  
public:
  
  Add();
  ~Add();
  
  // Adds 2 ints and returns the value.
  int    add( int =0, int =0 );
  
  // Adds 2 floats and returns the value
  float  add( float =0, float =0 );
  
  // Adds the integer values of 2 chars and returns the value
  int    add( char =0, char =0 );
  
  // Compares 2 bools; returns true if they're the same, false otherwise
  bool   add( bool =0, bool =0 );
  
  // Concatenates 2 strings into a new string and returns the new string 
  string add( string a, string b );
  
};

Add::Add(){}


Add::~Add(){}


int Add::add( int a, int b )
{
  return a + b;
}

float Add::add( float a, float b )
{
  return a + b;
}

int Add::add( char a, char b )
{
  return a + b;
}

bool Add::add( bool a, bool b )
{
  return a == b;
}

string Add::add( string a, string b )
{
  string v = a + b;
  return v;
}
