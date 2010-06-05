/******************************************************************************
 *
 * File: qsort_of.c
 *
 * System: C Programming Advanced, Exercise 7
 * 
 * Description:This program tests the PERIODIC_read_recs_from_bin function
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 11-Nov-2000  Charles Fordyce     1.0
 *****************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/*#include <periodic.h> */
#include <assert.h>
/*#include <qsort_of.h> */

/***************************************************************************
 * constants
 ***************************************************************************/
#ifndef TRUE
#define TRUE  (1)
#endif
#ifndef FALSE
#define FALSE (0)
#endif

/***************************************************************************
 * Function Prototypes
 ***************************************************************************/						

static void qsort_of( void *objects, int num, int size, int (*cmp)(const void *, const void *));

static int q_comp(const void *ptr1, const void *ptr2);

static void RecQS(void * objects, int num, int objsize, int (*cmp)(const void *, const void *), int low, int high);

/*static int partition(void * array, int num, int objsize, int (*cmp)(const void *, const void *)); */

static int partition(void * objects, int objsize, int (*cmp)(const void *, const void *), int low, int high);
		     
static void swap(int objsize, void * low, void * high);

/***************************************************************************
 * main function
 ***************************************************************************/
int main( void )
{
  char * binfile = "periodic.bin";
  int inx = 0;
  int num = 8;
  int keys[] = {25,20,10,5,15,30,40,35};

  
  for(inx = 0; inx < num; inx++)
    printf("keys[%d] = %d \n", inx, keys[inx]);
  
  qsort_of(keys, num, sizeof(int), q_comp);
  
  printf("\n\n");
  
  for(inx = 0; inx < num; inx++)
    printf("keys[%d] = %d \n", inx, keys[inx]);
   
}  
  
static void qsort_of(void * objects, int num, int objsize, int (* cmp)(const void *, const void *))
{
  RecQS(objects, num, objsize, cmp, 0, num - 1);
}

 
static void RecQS(void * objects, int num, int objsize, int (*cmp)(const void *, const void *), int low, int high)
{
  int pos;

  if(low < high)
    {

      printf("low = %d   high = %d\n", low, high);
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
  
  printf("\n**************\n1 Swap: Low: %d  pivotpos: %d \n", low, pivotpos);
  swap(objsize, &array[low * objsize], &array[((low + high) / 2) * objsize]);
  
  for(inx = low + 1; inx <= high; inx++)
    if(cmp(&array[inx * objsize], &array[pivot * objsize]) == -1)
      {
	printf("-1 Swap\n");
	swap(objsize, &array[++pivotpos * objsize], &array[inx * objsize]);
      }
  
  printf("2 Swap: Low: %d  pivotpos: %d \n", low, pivotpos);
  swap(objsize, &array[low * objsize], &array[pivotpos * objsize]); 
  
  return pivotpos;
}















static void swap(int objsize, void * plo, void * phi)
{
  char * temp;
  char * low = plo;
  char * high = phi;
  
  temp = (char *) malloc(objsize*sizeof(char));
  
  memcpy(temp, high, objsize * sizeof(char));
  
  memcpy(high, low, objsize * sizeof(char)); 
  
  memcpy(low, temp, objsize * sizeof(char)); 
  
  free(temp); 
  
}


 
static int q_comp(const void * p1, const void * p2)
{
  const int * a = p1;
  const int * b = p2;
  
  if(*a < *b)
    {
      printf("a:%d  LT  b:%d\n", *a, *b);
      return -1;
    }

  if(*a > *b)
    {
      printf("a:%d  GT  b:%d\n", *a, *b);
      return 1;
    }
  
  else 
    {
      printf("a:%d  == b:%d\n",*a, *b);
      return 0;
    }
}


/*
static int q_comp(const void * p1, const void * p2)
{
  const PERIODIC_data_t * pps1 = p1;
  const PERIODIC_data_t * pps2 = p2;
  
  if((pps1->atomic_number) < (pps2->atomic_number))
    return -1;
  
  else if((pps1->atomic_number) > (pps2->atomic_number))
    return 1;
  
  else 
    return 0; 

}
*/
