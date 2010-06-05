/******************************************************************************
 *
 * File: ex8.c
 *
 * System: C Programming Advanced, Exercise 8
 * 
 * Description: This program tests list.h API using Periodic Records
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 29-Nov-2000  Charles Fordyce     1.0
 *****************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <periodic.h>
#include <assert.h>
#include <list.h>
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
 * Function Protos
 ***************************************************************************/
void print_periodic_list(void *);
extern int id_periodic_rec(void *, void *);

/***************************************************************************
 * main function
 ***************************************************************************/

int main( void )
{
  char * binfile = "periodic.bin";
  const char * list_name = "fordyce_list";
  PERIODIC_data_p_t periodic_ptr = NULL;
  LIST_p_t fordyce_list_ptr = NULL;
  LIST_item_p_t fordyce_list_item = NULL;
  int keys[] = {19,30,32,39,45,47,55,65,77,87,88,94,97,-73,0,101};
  int inx;
  int num_recs = 0; 
  
  PERIODIC_read_recs_from_bin(binfile, &periodic_ptr, &num_recs);
  
  fordyce_list_ptr = LIST_create_list(list_name);
  
  for(inx = 0; inx < num_recs; inx++)
    LIST_add_to_list(fordyce_list_ptr, &periodic_ptr[inx]);
  
  
  LIST_operate_on_list(fordyce_list_ptr, print_periodic_list);
  
  
  printf("\n\nDequeueing Records 19,30,32,39,45,47,55,65,77,87,88,94,97\n\n");


  for(inx = 0; inx < 16; inx++)
    {
      fordyce_list_item = LIST_find_item_in_list(fordyce_list_ptr, id_periodic_rec, &keys[inx]);
      
      if(fordyce_list_item)
	LIST_remove_from_list(fordyce_list_ptr, &fordyce_list_item);
    }
  
  
  LIST_operate_on_list(fordyce_list_ptr, print_periodic_list);
    
  LIST_destroy_list(&fordyce_list_ptr, NULL);

  free(periodic_ptr);
}


extern int id_periodic_rec(void * item, void * num)
{
  int * key = num;
  PERIODIC_data_p_t this = item;
  
  if(*key == (-73 || 0 || 101))
    return FALSE;
    
  else if(*key == this->atomic_number)
    return TRUE;
    
  else 
    return FALSE;
}


void print_periodic_list(void * item)
{
  PERIODIC_data_p_t this = item;
  
  fprintf(stdout,"--> %2d %8.4f  %2s %s\n",
	   this->atomic_number,
	   this->atomic_weight,
	   this->symbol,
	   this->name );
}
