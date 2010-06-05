/***************************************************************************
 *
 * File: periodic3.c
 *
 * System: Periodic Reporting System (PRS), Exercise 3
 * 
 * Description: 
 *
 * External Functions:
 *         PERIODIC_parse_periodic_rec
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 19-Oct-2000  Charles Fordyce     1.0
 *****************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <periodic.h>

/***************************************************************************
 * Function: PERIODIC_parse_periodic_rec
 * Description:  parse the input buffer periodic information and
 *              initialize the structure fields
 * Input:
 *    buf - char array that contains periodic information 
 * Output:
 *    periodic_rec - pointer to periodic record
 * Return:
 *    TRUE - translated buffer without error
 *    FALSE - error translating buffer
 * Special Logic:
 *   If FALSE returned, parse_struct is NOT modified 
 ***************************************************************************/
extern int PERIODIC_parse_periodic_rec( char * buf, PERIODIC_data_p_t ptr )
{
  char wk_str[100], sym[3], nam[20];
  int num = 0;
  float wgt = 0;
  
  strcpy(wk_str, buf);
  
  if(4 != sscanf(wk_str,"%d %f %s %s",&num, &wgt, sym, nam))
    return FALSE;
  
  if(strlen(sym) > 3 || strlen(nam) > 20)
    return FALSE;
  
  else
    {
      ptr->atomic_number = num;
      ptr->atomic_weight = wgt;
      strcpy(ptr->symbol,sym);
      strcpy(ptr->name,nam);
    }
  return TRUE;

}
