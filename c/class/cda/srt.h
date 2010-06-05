/*-----------------------------------------------------------------------------
 *
 * File: srt.h
 *
 * Description: Public Header for SRT Module - Project (3)
 *
 * Revision History2
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 12-Feb-2001  Charles Fordyce        1.1
 *----------------------------------------------------------------------------*/
#ifndef SRT_H
#define SRT_H

/*-----------------------------------------------------------------------------
 * Required Includes
 *----------------------------------------------------------------------------*/
#include <stddef.h>
#include <stdlib.h>
#include <cda.h>
#include <stk.h>

/*-----------------------------------------------------------------------------
 * Macros
 *----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 * Typedef Equivalencies
 *----------------------------------------------------------------------------*/
typedef int SRT_CMP_PROC_t( const void*, const void * ); 
typedef SRT_CMP_PROC_t *SRT_CMP_PROC_p_t; 


/*-----------------------------------------------------------------------------
 * Method Prototypes
 *----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
 * Method: SRT_mergesort
 * Description: Sorts a generic array
 *----------------------------------------------------------------------------*/
void  SRT_mergesort( void              *array,
		     size_t            num_elements,
		     size_t            element_size,
		     SRT_CMP_PROC_p_t  cmp_proc );

/*-----------------------------------------------------------------------------
 * Method: SRT_poly_mergesort
 * Description: Sorts an array of pointers of data structures
 *----------------------------------------------------------------------------*/
void  SRT_poly_mergesort( void              **array,
			  size_t            num_elements,
			  SRT_CMP_PROC_p_t  cmp_proc );

#endif /* SRT_H */
