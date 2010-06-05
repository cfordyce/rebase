/*----------------------------------------
  Charles Fordyce
  
  Assingment 3-1 Source File
  ----------------------------------------*/

#include <iostream>
#include "Fordyce03-1.h"

ElasticIntArray::ElasticIntArray( int* arr, int num )
{
  idx = num;
  
  curr = new int [num];
  
  for ( int i=0; i < idx; i++ )
    curr[i] = arr[i];
}

ElasticIntArray::~ElasticIntArray()
{
  delete [] curr;
}


void ElasticIntArray::Append( int num )
{
  int i, *tptr, * tmp = new int[++idx];
  
  for ( i=0; i < idx-1; i++ )
    tmp[i] = curr[i];
  
  tmp[i] = num;
  
  tptr = curr;
  delete [] tptr;
  curr = tmp;
}

void ElasticIntArray::Insert( int num, int ind )
{
  if ( ind > idx )
    return;
  
  int i, * tptr, * tmp = new int[++idx];
  
  for ( i=0; i < ind; i++ )
    tmp[i] = curr[i];
  
  tmp[i] = num;

  for ( ; i < idx; i++ )
    tmp[i+1] = curr[i];
  
  tptr = curr;
  delete [] tptr;
  curr = tmp;
}

void ElasticIntArray::Remove( int pos )
{
  if ( pos > idx )
    return;
  
  int i, * tptr, * tmp = new int[idx];
  
  for ( i=0; i < pos; i++ )
    tmp[i] = curr[i];
      
  for (; i < idx; i++ )
    tmp[i] = curr[i+1];
  
  --idx;

  tptr = curr;
  delete [] tptr;
  curr = tmp;
}


int ElasticIntArray::Value( int pos )
{
  if ( pos > idx )
    return 0;
  
  cout << curr[pos] << endl;
  
  return curr[pos];
}


void ElasticIntArray::Print()
{

  for ( int i=0; i < idx; i++ )
    cout << curr[i] << " ";
  
  cout << endl;
}
