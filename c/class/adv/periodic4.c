/******************************************************************************
 *
 * File: periodic4.c
 *
 * System: C Programming Advanced, Exercise 4
 * 
 * Description: This program tests the PERIODIC_create_bin_from_ascii function.
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
 * Function: PERIODIC_create_bin_from_ascii
 * Description: read periodic recs from an ASCII file and creates a
 *     binary file of PERIODIC_data_t records 
 * Input:
 *   ascii_file - ASCII file with periodic records
 *   binary_file - binary file with periodic records
 * Output:
 *   recs_read - number of records parsed and written to binary file
 *   recs_skipped - number of records that failed parsing, excluding comments
 * Return:
 *    TRUE - successully read ascii file and created binary file
 *    FALSE - did NOT successully read ascii file and created binary file
 * Special Logic:
 *    If TRUE returned, binary file was created.
 ***************************************************************************/
extern int PERIODIC_create_bin_from_ascii(char * ascii_file, char * binary_file, int * recs_read, int * recs_skipped )
{
  PERIODIC_data_t periodic_rec;
  FILE * txt_file, * bin_file;
  char periodic_str[90];
  long int total = 0;


  if(NULL != (bin_file = fopen(binary_file,"wb")))
    {
      fseek(bin_file, 0L, SEEK_SET);
      fwrite(&total, sizeof(long int), 1, bin_file);
      
      if(NULL != (txt_file = fopen(ascii_file,"r")))
      {

	while(NULL != fgets(periodic_str,90,txt_file))
	  {
	    if (TRUE == PERIODIC_parse_periodic_rec(periodic_str, &periodic_rec))
	      {
		if (1 == (fwrite(&periodic_rec, sizeof(PERIODIC_data_t), 1, bin_file)))
		  {
		    (*recs_read)++;
		  }
	      }
	    else if (periodic_str[0] != '#')
	      (*recs_skipped)++;
	  } /* end while */
      
	
	(int) total = *recs_read;
	(long int) total;
	fseek(bin_file, 0L, SEEK_SET);
	fwrite(&total, sizeof(long int), 1, bin_file);
	printf("total = %ld\n", total);
	

      }
    }
  if(*recs_read > 0)
    return TRUE;
  else 
    return FALSE;
}
