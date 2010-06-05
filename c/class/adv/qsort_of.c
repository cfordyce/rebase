/******************************************************************************
 *
 * File: qsort_of.c
 *
 * System: C Programming Advanced, Exercise 7
 * 
 * Description: My version of qsort algorithm
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 20-Nov-2000  Charles Fordyce     1.0
 *****************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <qsort_of.h>

/*******************************************************************
 Function Prototypes
*******************************************************************/

static void RecQS(void * objects, int num, int objsize, int (*cmp)(const void *, const void *), int low, int high);

static int partition(void * objects, int objsize, int (*cmp)(const void *, const void *), int low, int high);
		     
static void swap(int objsize, void * low, void * high);


/******************************************************************
 The Functions
 ******************************************************************/

extern void qsort_of(void * objects, int num, int objsize, int (* cmp)(const void *, const void *))
{
  RecQS(objects, num, objsize, cmp, 0, num - 1);
}

 
static void RecQS(void * objects, int num, int objsize, int (*cmp)(const void *, const void *), int low, int high)
{
  int pos;

  if(low < high)
    {
      pos = partition(objects, objsize, cmp, low, high);
      
      RecQS(objects, num, objsize, cmp, low, pos - 1);
      
      RecQS(objects, num, objsize, cmp, pos + 1, high);
      
    }
}


static int partition(void * objects, int objsize, int (*cmp)(const void *, const void *), int low, int high)
{
  char * array = objects;
  int inx, pivot;
  static int pivotpos;
  
  pivot = low;
  pivotpos = low;
  
  swap(objsize, &array[low * objsize], &array[((low + high) / 2) * objsize]);
  
  for(inx = low + 1; inx <= high; inx++)
    if(cmp(&array[inx * objsize], &array[pivot * objsize]) == -1)
      swap(objsize, &array[++pivotpos * objsize], &array[inx * objsize]);
  
  swap(objsize, &array[low * objsize], &array[pivotpos * objsize]); 
  
  return pivotpos;
}


static void swap(int objsize, void * p_lo, void * p_hi)
{
  char * temp;
  char * low = p_lo;
  char * high = p_hi;
  
  temp = (char *) malloc(objsize*sizeof(char));
  
  memcpy(temp, high, objsize * sizeof(char));
  
  memcpy(high, low, objsize * sizeof(char)); 
  
  memcpy(low, temp, objsize * sizeof(char)); 
  
  free(temp); 
  
}
