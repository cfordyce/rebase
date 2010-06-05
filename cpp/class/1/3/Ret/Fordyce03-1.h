/*----------------------------------------
  Charles Fordyce
  
  Assingment 3-4 Header File
  ----------------------------------------*/

#ifndef FORDYCE_03_1_h
#define FORDYCE_03_1_h

class ElasticIntArray {
  
 public:
  
  // Constructor takes a pointer to an Integer array (arg 1) and an integer specifying the length of the array (arg 2).
  ElasticIntArray( int* , int );

  ~ElasticIntArray();
  
  // Add an integer (arg 1) to the end of the array
////////////////////////////////////////////////////////////////
// bmr
// Common practice in C++ is to lower-case method names, but use
// whatever style you are comfortable with.
  void Append( int );
  
  // Insert an integer (arg 1) at a specific position (arg 2) in the array.
  void Insert( int, int );

  // Remove an element at the specicified array position (arg 1).
  void Remove( int );

  // Returns the value stored in the array at the position specified (arg 1).
  int  Value( int );
  
  //Prints the elements of the array to stdout.
////////////////////////////////////////////////////////////////
// bmr
// Think about using ostream &operator<<() for this.
  void Print();
  
 private:
////////////////////////////////////////////////////////////////
// bmr
// I don't like either of these names. "idx" is usually "index",
// and in this case it is not an index, it is a length, size, or
// total number of elements. "curr" i assume stands for "current",
// which again sounds like a position in a list (current, previous,
// next).
  int* curr;
  int idx;
  
};

#endif

