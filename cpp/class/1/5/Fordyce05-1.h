/*----------------------------------------
  Charles Fordyce
  
  Assingment 5-1 Header File
  ----------------------------------------*/

#ifndef FORDYCE_05_1_h
#define FORDYCE_05_1_h

#include <iostream>

template<class T> class ElasticArray {
  
 public:
  
  // Constructor takes a pointer to a T array (arg 1) and a T specifying the length of the array (arg 2).
  ElasticArray( T* arr, int num )
    : arx( num )
    {
      parr = new T [arx];
      
      for ( int i=0; i < arx; i++ )
	parr[i] = arr[i];
    }

  // Destructor.  deletes the array of T being pointed to by parr.
  ~ElasticArray() { delete [] parr; }

  
  // Add a T to the end of the array
  void Append( T num )
    {
      int i, *tptr, * tmp = new int[++arx];
      
      for ( i=0; i < arx-1; i++ )
	tmp[i] = parr[i];
      
      tmp[i] = num;
      
      tptr = parr;
      delete [] tptr;
      parr = tmp;
    }
  
  // Insert a T at a specific position in the array.
  void Insert( T num, int ind )
    {
      if ( ind > arx )
	return;
      
      T i, * tptr, * tmp = new T[++arx];
      
      for ( i=0; i < ind; i++ )
	tmp[i] = parr[i];
      
      tmp[i] = num;
      
      for ( ; i < arx; i++ )
	tmp[i+1] = parr[i];
      
      tptr = parr;
      delete [] tptr;
      parr = tmp;
    }
  
  
  // Remove an element at the specicified array position.
  void Remove( int pos )
    {
      if ( pos > arx )
	return;
      
      int i, * tptr, * tmp = new T[arx];
      
      for ( i=0; i < pos; i++ )
	tmp[i] = parr[i];
      
      for (; i < arx; i++ )
	tmp[i] = parr[i+1];
      
      --arx;
      
      tptr = parr;
      delete [] tptr;
      parr = tmp;
    }
  
  // Returns the value stored in the array at the position specified.
  int Value( int pos )
    {
      if ( pos > arx )
	return 0;
      
      cout << parr[pos] << endl;
      
      return parr[pos];
    }
  
  //Prints the elements of the array to stdout.
  void Print()
    {
      for ( int i=0; i < arx; i++ )
	cout << parr[i] << " ";
      
      cout << endl;
    }
  
 private:
  T* parr;
  int arx;
  
};

#endif
