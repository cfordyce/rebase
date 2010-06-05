/******************************************************************************
 *
 * File: ex6.c
 *
 * System: C Programming Advanced, Exercise 6
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
#include <periodic.h>
#include <assert.h>
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
static int q_comp(const void *ptr1, const void *ptr2);
static int b_comp(const void *ptr1, const void *ptr2);

/***************************************************************************
 * main function
 ***************************************************************************/
int main( void )
{
  char * binfile = "periodic.bin";
  PERIODIC_data_p_t periodic_ptr = NULL;
  PERIODIC_data_p_t * periodic_ptr_arr = NULL;
  int num_recs, inx;
  int keys[] = {19,30,32,39,45,47,55,65,77,87,88,94,97};
  num_recs = inx = 0;
  
  
  PERIODIC_read_recs_from_bin(binfile, &periodic_ptr, &num_recs);

  periodic_ptr_arr = malloc(num_recs*sizeof(PERIODIC_data_p_t));

  for(inx=0; inx < num_recs; inx++)
    periodic_ptr_arr[inx] = &periodic_ptr[inx];
  
  PERIODIC_print_recs(*periodic_ptr_arr, num_recs);
  
  qsort(periodic_ptr_arr, num_recs, sizeof(PERIODIC_data_p_t), q_comp);
  
  PERIODIC_print_recs(*periodic_ptr_arr, num_recs);
  
  free(periodic_ptr_arr);

  free(periodic_ptr);

  return 0;
  
}

static int q_comp(const void * p1, const void * p2)
{
  return (*(PERIODIC_data_p_t *)p1)->atomic_number - (*(PERIODIC_data_p_t *)p2)->atomic_number;


/*  const PERIODIC_data_p_t * pps1 = p1;
  const PERIODIC_data_p_t * pps2 = p2;
  */ 
/* printf("\natomic_number %d  -or-  %d\n", (*pps1)->atomic_number, (*pps2)->atomic_number); */

 /*
  if(((*pps1)->atomic_number) < ((*pps2)->atomic_number))
  return -1;
    
    else if(((*pps1)->atomic_number) > ((*pps2)->atomic_number))
    return 1;
  
  else 
 
 return -1; 
 */

}
