/******************************************************************************
 *
 * File: ex5.c
 *
 * System: C Programming Advanced, Exercise 5
 * 
 * Description:This program tests the PERIODIC_read_recs_from_bin function
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 05-Nov-2000  Charles Fordyce     1.0
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

#define PROJ_FREE( ptr ) ( (ptr==NULL) ? (NULL) : (free(ptr),ptr=NULL) )

/***************************************************************************
 * main function
 ***************************************************************************/
int main( void )
{
  char * binfile = "periodic.bin";
  PERIODIC_data_p_t periodic_ptr = NULL;
  int num_recs = 0; 
  
  if(num_recs == 0)
    {
      PERIODIC_read_recs_from_bin(binfile, &periodic_ptr, &num_recs);
      
      PERIODIC_print_recs(periodic_ptr, num_recs); 
      PROJ_FREE( periodic_ptr );
    }
  
  return 0;
}
