#ifndef PERIODIC_H_INCLUDED
#define PERIODIC_H_INCLUDED
/******************************************************************************
 *
 * File: periodic.h
 *
 * System: Periodic Reporting System (PRS)
 * 
 * Description: The include file for PRS  dependencies 
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 01-Jan-2000  Some Programmer     Original
 *****************************************************************************/

/******************************************************************************
 * includes
 ******************************************************************************/
#include <stdio.h>

/******************************************************************************
 * constants
 ******************************************************************************/
#ifndef TRUE
#define TRUE           (1)
#endif

#ifndef FALSE
#define FALSE          (0)
#endif

#define PERIODIC_SYMBOL_LEN    (2)
#define PERIODIC_NAME_LEN       (40)

/******************************************************************************
 * macros
 ******************************************************************************/

/******************************************************************************
 * typedefs
 ******************************************************************************/
typedef struct PERIODIC_data_tag
{
    
    char    symbol[PERIODIC_SYMBOL_LEN + 1];
    char    name[PERIODIC_NAME_LEN + 1];
    int     atomic_number;
    double  atomic_weight;
} PERIODIC_data_t, * PERIODIC_data_p_t;

/******************************************************************************
 * prototypes
 ******************************************************************************/
/***************************************************************************
 * Function: PERIODIC_parse_periodic_rec
 * Description: 
 * Input:
 *   str - string with periodic data
 * Output:
 *   ptr - pointer to structure with fields set from contents 
 *         of str
 * Return:
 *   int - TRUE - parse string OK, set structure fields
 *         FALSE - parse string fialed
 * Special Logic:
 *   If FALSE returned, parse_struct is NOT modified 
 ***************************************************************************/
extern int PERIODIC_parse_periodic_rec( char * str, PERIODIC_data_p_t ptr );

/***************************************************************************
 * Function: PERIODIC_print_recs
 * Description: print periodic recs from an array
 * Input:
 *   arr - array of periodic recs or pointer to periodic rec
 *   num_recs - number of records in array
 * Output:
 *   None
 * Return:
 *   None
 * Special Logic:
 *   None
 ***************************************************************************/
extern void PERIODIC_print_recs( PERIODIC_data_p_t arr, int num_recs );

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
extern int PERIODIC_create_bin_from_ascii( char * ascii_file,
                                           char * binary_file,
                                           int * recs_read,
                                           int * recs_skipped );
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
extern int PERIODIC_read_recs_from_bin( char * binfile,
                                        PERIODIC_data_p_t * periodic_ptr,
                                        int * num_recs );

#endif
