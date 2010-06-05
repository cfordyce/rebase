/******************************************************************************
 *
 * File: cda.h
 *
 * Description: Public Header for CDA Project
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 16-Jan-2001  Charles Fordyce        1.1   
 *****************************************************************************/
#ifndef CDA_H

#define CDA_H
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#ifndef CDAP_H
#include <cdap.h>
#endif /* CDAP_H */

/******************************************************************************
 * Macros
 ******************************************************************************/
#define CDA_TRUE    (1)
#define CDA_FALSE   (0)
#define CDA_ASSERT(exp) (assert(exp))
#define CDA_CARD(arr) (sizeof(arr)/sizeof(*arr))
#define CDA_NEW(type) ((type *)CDA_malloc(sizeof(type)))
#define CDA_NEW_STR(str) (strcpy((char *)CDA_malloc(strlen(str) + 1), (str)))
#define CDA_NEW_STR_IF(str) (str == NULL ? NULL: CDA_NEW_STR(str)) 

/******************************************************************************
 * Typedefs
 ******************************************************************************/
typedef int                CDA_BOOL_t;
typedef signed char        CDA_INT8_t;
typedef unsigned char      CDA_UINT8_t;

typedef signed short int         CDA_INT16_t;
typedef unsigned short int       CDA_UINT16_t;

#if defined(ALPHA) && defined (DIGITAL_UNIX)
typedef int CDA_INT32_t;
typedef unsigned int CDA_UINT32_t;
#else
typedef long int CDA_INT32_t;
typedef long unsigned int CDA_UINT32_t;
#endif 

/***************************************************************************
 * Prototypes
 **************************************************************************/
/***************************************************************************
 * Function: CDA_malloc(size_t);
 * Description: Encapsulated malloc()  
 ****************************************************************************/
void * CDA_malloc(size_t);

/***************************************************************************
 * Function: CDA_calloc(int, size_t);
 * Description: Encapsulated calloc()
 ****************************************************************************/
void * CDA_calloc(int, size_t);

/***************************************************************************
 * Function: CDA_realloc(void *, size_t )
 * Description: Encapsulated realloc() 
 ****************************************************************************/
void * CDA_realloc(void *, size_t );

/***************************************************************************
 * Function: CDA_free(void *);
 * Description: Encapsulated free()
 ****************************************************************************/
void CDA_free(void *);

/***************************************************************************
 * External Variables
 **************************************************************************/

#endif
