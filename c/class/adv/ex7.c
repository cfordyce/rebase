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
 * 20-Nov-2000  Charles Fordyce     1.0
 *****************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <periodic.h>
#include <assert.h>
#include <qsort_of.h>

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
 * Comaparison Function Prototypes
 ***************************************************************************/						
static int int_comp(const void *ptr1, const void *ptr2);
static int double_comp(const void * p1, const void * p2);
static int struct_comp(const void * p1, const void * p2);
static int atomic_num_comp(const void * p1, const void * p2);

/***************************************************************************
 * main test function
 ***************************************************************************/

/* Choose the type of sort.  Release the #define you want

#define SORT_INTS
#define SORT_DOUBLES
#define SORT_STRUCTS
#define SORT_ARRAY_OF_POINTERS_TO_STRUCTS

*/

#define SORT_ARRAY_OF_POINTERS_TO_STRUCTS

int main( void )
{
  int inx = 0;

/******************************************************
 Test sorting ints
******************************************************/
#ifdef SORT_INTS
  int num_recs = 17;
  int array_of_ints[] = {25,20,10,5,15,30,40,35,50,80,65,85,55,60,75,70,45};
  
  for(inx = 0; inx < num_recs; inx++)
    printf("array_of_ints[%d] = %d \n", inx, array_of_ints[inx]);
  
  qsort_of(array_of_ints, num_recs, sizeof(int), int_comp);
  
  printf("\n** Sorted Array **\n");
  
  for(inx = 0; inx < num_recs; inx++)
    printf("array_of_ints[%d] = %d \n", inx, array_of_ints[inx]);
   
#endif  /* SORT_INTS */

/******************************************************
 Test sorting doubles
******************************************************/
#ifdef SORT_DOUBLES
  int num_recs = 17;
  double array_of_doubles[] = {25.1,20.2,10.3,5.4,15.5,30.6,40.7,35.8,50.9,80.11,65.12,85.13,55.14,60.15,75.16,70.17,45.18};
  
  for(inx = 0; inx < num_recs; inx++)
    printf("array_of_doubles[%d] = %f \n", inx, array_of_doubles[inx]);
  
  qsort_of(array_of_doubles, num_recs, sizeof(double), double_comp);
  
  printf("\n** Sorted Array **\n");
  
  for(inx = 0; inx < num_recs; inx++)
    printf("array_of_doubles[%d] = %f \n", inx, array_of_doubles[inx]);
   
#endif  /* SORT_DOUBLES */

/******************************************************
 Test sorting structures
******************************************************/
#ifdef SORT_STRUCTS
  
  char * binfile = "periodic.bin";
  PERIODIC_data_p_t periodic_ptr = NULL;
  int num_recs = 0;

  PERIODIC_read_recs_from_bin(binfile, &periodic_ptr, &num_recs);
  
  PERIODIC_print_recs(periodic_ptr, num_recs); 
  
  qsort_of(periodic_ptr, num_recs, sizeof(PERIODIC_data_t), struct_comp);
  
  PERIODIC_print_recs(periodic_ptr, num_recs);

#endif /* SORT_STRUCTS */


/******************************************************
 Test sorting array of structures
******************************************************/
#ifdef SORT_ARRAY_OF_POINTERS_TO_STRUCTS
  char * binfile = "periodic.bin";
  PERIODIC_data_p_t periodic_ptr = NULL;
  PERIODIC_data_p_t * periodic_ptr_arr = NULL;
  int num_recs = 0;
    
  PERIODIC_read_recs_from_bin(binfile, &periodic_ptr, &num_recs);
  
  periodic_ptr_arr = malloc(num_recs*sizeof(PERIODIC_data_p_t));

  for(inx=0; inx < num_recs; inx++)
    periodic_ptr_arr[inx] = &periodic_ptr[inx];
  
  PERIODIC_print_recs(*periodic_ptr_arr, num_recs);
  
  qsort(periodic_ptr_arr, num_recs, sizeof(PERIODIC_data_p_t), atomic_num_comp);
  
  PERIODIC_print_recs(*periodic_ptr_arr, num_recs);
  
  free(periodic_ptr_arr);

  free(periodic_ptr);
  
#endif  /* SORT_ARRAY_OF_POINTERS_TO_STRUCTS */

}  
  

 
static int int_comp(const void * p1, const void * p2)
{
  const int * a = p1;
  const int * b = p2;
  
  if(*a < *b)
      return -1;

  if(*a > *b)
      return 1;
  
  else 
      return 0;
}

static int double_comp(const void * p1, const void * p2)
{
  const double * a = p1;
  const double * b = p2;
  
  if(*a < *b)
      return -1;

  if(*a > *b)
      return 1;
  
  else 
      return 0;
}

static int struct_comp(const void * p1, const void * p2)
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


static int atomic_num_comp(const void * p1, const void * p2)
{
  return (*(PERIODIC_data_p_t *)p1)->atomic_number - (*(PERIODIC_data_p_t *)p2)->atomic_number;
}
