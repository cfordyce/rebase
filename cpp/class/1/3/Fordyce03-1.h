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
  void Append( int );
  
  // Insert an integer (arg 1) at a specific position (arg 2) in the array.
  void Insert( int, int );

  // Remove an element at the specicified array position (arg 1).
  void Remove( int );

  // Returns the value stored in the array at the position specified (arg 1).
  int  Value( int );
  
  //Prints the elements of the array to stdout.
  void Print();
  
 private:
  int* curr;
  int idx;
  
};

#endif

