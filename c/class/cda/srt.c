/*----------------------------------------------------------------------------
 *
 * File: srt.c
 *
 * Description: Source file for SRT Module - Project 3
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 12-Feb-2001  Charles Fordyce     1.1
 *---------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
 * includes
 *---------------------------------------------------------------------------*/
#include <stdlib.h>
#include <cda.h>
#include <srtp.h> 

/*----------------------------------------------------------------------------
 * Macros
 *---------------------------------------------------------------------------*/
#define MAX_STACK_SIZE (200)

/*----------------------------------------------------------------------------
 * Typedef Equivalencies
 *---------------------------------------------------------------------------*/
typedef unsigned char BYTE_t; 

/*----------------------------------------------------------------------------
 * Local Declarations
 *---------------------------------------------------------------------------*/
static STK_ID_t stack = STK_NULL_ID;

/*-----------------------------------------------------------------------------
 * Local Method Prototypes
 *----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
 * Method: array_merge
 * Description: Performs merge operation using an array.
 *----------------------------------------------------------------------------*/
static void array_merge( BYTE_t *, size_t, BYTE_t *, size_t, size_t, SRT_CMP_PROC_p_t );

/*-----------------------------------------------------------------------------
 * Method: stack_merge
 * Description: Performs merge operation using a stack.
 *----------------------------------------------------------------------------*/
static void stack_merge( void **, size_t, void **, size_t, STK_ID_t, SRT_CMP_PROC_p_t );


/*----------------------------------------------------------------------------
 * Public Method Definitions
 *---------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
 * Method: SRT_mergesort
 *---------------------------------------------------------------------------*/
void  SRT_mergesort( void * array, size_t num_elements, size_t element_size, SRT_CMP_PROC_p_t cmp_proc )
{
  if(num_elements > 1)
    {
      size_t low = num_elements / 2;
      size_t high = num_elements - (int)low;
      BYTE_t *array1 = (BYTE_t*)array;
      BYTE_t *array2 = (BYTE_t*)array + low * element_size;
      SRT_mergesort( array1, (int)low, element_size, cmp_proc );
      SRT_mergesort( array2, (int)high, element_size, cmp_proc );
      array_merge( array1, (int)low, array2, (int)high, element_size, cmp_proc );
    }
}

/*----------------------------------------------------------------------------
 * Method: SRT_poly_mergesort
 *---------------------------------------------------------------------------*/
void SRT_poly_mergesort( void **array, size_t num_elements, SRT_CMP_PROC_p_t cmp_proc )
{
  if( stack == STK_NULL_ID )
    stack = STK_create_stack( MAX_STACK_SIZE );
  
  if(num_elements > 1)
    {
      size_t low = num_elements / 2;
      size_t high = num_elements - (int)low;
      void** array2 = array + (int)low;
      SRT_poly_mergesort( array, (int)low, cmp_proc );
      SRT_poly_mergesort( array2, (int)high, cmp_proc );
      stack_merge( array, (int)low, array2, (int)high, stack, cmp_proc );
    }
}

/*----------------------------------------------------------------------------
 * Local Method Definitions
 *---------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
 * Method: array_merge
 *---------------------------------------------------------------------------*/
static void array_merge( BYTE_t * array1, size_t low, BYTE_t * array2, size_t high, size_t element_size, SRT_CMP_PROC_p_t cmp_proc )
{
  BYTE_t * temp_array;
  int lnx, hnx, tnx;
  lnx = hnx = tnx = 0;
  
  temp_array = CDA_malloc( ( (int)low + (int)high ) * element_size );
  
  while( lnx < (int)low  &&  hnx < (int)high )
    {
      if( cmp_proc( array1 + lnx * element_size , array2 + hnx * element_size ) < 0 )
	{
	  memcpy( temp_array + tnx * element_size, array1 + lnx * element_size, element_size );
	  lnx++;
	  tnx++;
	} 
      else
	{
	  memcpy( temp_array + tnx * element_size, array2 + hnx * element_size, element_size );
	  hnx++;
	  tnx++;
	} 
    }
  
  while(lnx < (int)low)
    {
      memcpy( temp_array + tnx * element_size, array1 + lnx * element_size, element_size );
      lnx++;
      tnx++;
    }
  while(hnx < (int)high)
    {
      memcpy( temp_array + tnx * element_size, array2 + hnx * element_size, element_size );
      hnx++;
      tnx++;
    }
  
  for( lnx = 0; lnx < (int)low + (int)high; lnx++  )
    memcpy( array1 + lnx * element_size, temp_array + lnx * element_size, element_size );
  
  CDA_free( temp_array ); 
}


/*----------------------------------------------------------------------------
 * Method: stack_merge
 *---------------------------------------------------------------------------*/
static void stack_merge( void ** array, size_t low, void ** array2, size_t high, STK_ID_t stack, SRT_CMP_PROC_p_t cmp_proc )
{
  int lnx, hnx;
  lnx = hnx = 0;
  
  while( lnx < (int)low  &&  hnx < (int)high )
    {
      if( cmp_proc( array[lnx], array2[hnx] ) < 0 )
	STK_push_item( stack, array[lnx++] );
      
      else
	STK_push_item( stack, array2[hnx++] );
    }
  
  while( lnx < (int)low )
    STK_push_item( stack, array[lnx++] );
  
  while(hnx < (int)high)
    STK_push_item( stack, array2[hnx++] );
  
  lnx = (int)low + (int)high;
  while ( lnx > 0 )
    array[--lnx] =(void**)STK_pop_item( stack );
  
}

/*----------------------------------------------------------------------------
 * End of File
 *---------------------------------------------------------------------------*/

