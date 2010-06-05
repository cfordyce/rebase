/***************************************************************************
 *
 * File: periodic.c
 *
 * System: Periodic Reporting System (PRS)
 * 
 * Description: 
 *
 * External Functions:
 *  PERIODIC_print_recs
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 19-Oct-2000  Charles Fordyce     1.0
 *****************************************************************************/
#include <stdlib.h>
#include <periodic.h>

/***************************************************************************
 * Function: PERIODIC_print_recs
 * Description: print periodic recs from an array
 * Input:
 *   arr - array of periodic recs
 *   num_recs - number of records in array
 * Output:
 *   None
 * Return:
 *   None
 * Special Logic:
 *   None
 ***************************************************************************/
extern void PERIODIC_print_recs(PERIODIC_data_p_t periodic_arr, int num_recs )
{
  int inx = 0;
   
  for (; inx < num_recs; inx++)
    {
        fprintf( stdout,
                 "==> %2d %8.4f  %2s %s   %p\n",
                 periodic_arr[inx].atomic_number,
                 periodic_arr[inx].atomic_weight,
                 periodic_arr[inx].symbol,
                 periodic_arr[inx].name, &periodic_arr[inx] );
    }
}
