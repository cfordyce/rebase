
/******************************************************************************
 *
 * File: ex4.c
 *
 * System: C Programming Advanced, Exercise 4
 * 
 * Description: This program tests parsing mulitple files and
 *              writes data to a binary file.
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 27-Oct-2000  Charles Fordyce     1.0
 *****************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <periodic.h>
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
 * Test Files Used
 ***************************************************************************
periodic_nogood.txt
periodic_various.txt
periodic_100_good.txt
periodic_comments_only.txt
periodic_short_1.txt
periodic_400.txt

***************************************************************************/

/***************************************************************************
 * main function
 ***************************************************************************/
int main( void )
{
  char * ascii_file = {"periodic_100_good.txt"};
  char * binary_file = {"periodic.bin"};
  int recs_read, recs_skipped;
  recs_read = recs_skipped = 0;

      
  if(TRUE == PERIODIC_create_bin_from_ascii(ascii_file, binary_file, &recs_read, &recs_skipped))
    {
      printf( "Binary File Created.\n%d Records Written.\n%d Records Skipped.\n",recs_read, recs_skipped);
    }
  else
    {
      printf("Binary File Creation Failed.\n");
    }
     
}
