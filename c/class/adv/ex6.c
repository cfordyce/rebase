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
  PERIODIC_data_p_t periodic_rec_arr = NULL;
  PERIODIC_data_p_t search_res = NULL;
  PERIODIC_data_p_t * periodic_ptr_arr = NULL;
  int num_recs, inx;
  int keys[] = {19,30,32,39,45,47,55,65,77,87,88,94,97};
  num_recs = inx = 0;
  
  
  PERIODIC_read_recs_from_bin(binfile, &periodic_ptr, &num_recs);

  periodic_ptr_arr = (PERIODIC_data_p_t *) malloc(num_recs*sizeof(PERIODIC_data_p_t));

  periodic_rec_arr = (PERIODIC_data_p_t) malloc(num_recs*sizeof(PERIODIC_data_t));
      
  for(inx=0; inx < num_recs; inx++)
    {
      *periodic_ptr_arr = &periodic_ptr;
      
      memcpy(periodic_rec_arr+inx, &periodic_ptr[inx], sizeof(PERIODIC_data_t));
      
      periodic_ptr_arr++;
    }
  
  *periodic_ptr_arr = &periodic_ptr;
  
  PERIODIC_print_recs(periodic_ptr, num_recs); 
  
  qsort(periodic_ptr_arr, num_recs, sizeof(PERIODIC_data_p_t), q_comp);
  
  PERIODIC_print_recs(periodic_rec_arr, num_recs);
  
  
  for(inx = 0; inx < 13; inx++)
    {
      search_res = bsearch(&keys[inx], *periodic_ptr_arr, num_recs, sizeof(PERIODIC_data_t), (void *)b_comp);
      
      if(search_res)
      printf("\n\nFound Periodic Record:
               Symbol:    %s
               Name:      %s
               Number:    %d
               Weight:    %f", 
	     search_res->symbol,
	     search_res->name,
	     search_res->atomic_number,
	     search_res->atomic_weight);        
    }


  free(periodic_rec_arr);

  free(periodic_ptr);

  return 0;
  
}

static int b_comp(const void * p1, const void * p2)
{
  const int * key = p1;
  const PERIODIC_data_t * pps1 = p2;

  if(((*key) < (pps1->atomic_number)) || (pps1->atomic_number == 101))
    return -1;
  
  else if((*key) > (pps1->atomic_number)|| (pps1->atomic_number == (-73) || (0)))
    return 1;
  
  else 
    return 0; 
}



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
