/******************************************************************************
 *
 * File: periodic5.c
 *
 * System: C Programming Advanced, Exercise 5
 * 
 * Description: This program performs the PERIODIC_read_recs_from_bin function.
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 27-Oct-2000  Charles Fordyce     1.0
 *****************************************************************************/

/*****************************************************************************
 * includes
 *****************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <periodic.h>

/***************************************************************************
 * Function: PERIODIC_read_recs_from_bin
 * Description: read periodic recs from a binary file
 * Input:
 *  datafile - binary file with periodic records
 * Output:
 *   periodic_ptr - pointer to array of periodic records
 *   num_recs - pointer to integer representing number of records in array
 * Return:
 *    TRUE - read the records without error
 *    FALSE - some error encountered
 * Special Logic:
 *    if this function returns TRUE, memory has been allocated and
 *    assigned to periodic_ptr
 *
 ***************************************************************************/
extern int PERIODIC_read_recs_from_bin(char * binfile, PERIODIC_data_p_t * periodic_ptr, int * num_recs)
{
  PERIODIC_data_p_t ptr_array = NULL;
  FILE * bin_file_ptr = NULL;
  int x = 0;
  
  if(bin_file_ptr == NULL)
    bin_file_ptr = fopen(binfile,"rb");
  
    
  if(*num_recs == 0)
    {
      fseek(bin_file_ptr, 0L, SEEK_SET);
      
      x = fread(num_recs, sizeof(long int), 1, bin_file_ptr);
  
      ptr_array = (PERIODIC_data_p_t) malloc(*num_recs*sizeof(PERIODIC_data_t));
      
      x = fread(ptr_array, sizeof(PERIODIC_data_t), *num_recs, bin_file_ptr);
  
      *periodic_ptr = ptr_array;
            
    }

  if(x == *num_recs)
    return TRUE;
  else
    return FALSE;

}
