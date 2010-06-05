/*-----------------------------------------------------------------------------
 *
 * File: hash.h
 *
 * Description: Public Header for HASH Module - Project 5
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 02-Mar-2001  Charles Fordyce        1.0
 *----------------------------------------------------------------------------*/
#ifndef HASH_H
#define HASH_H

/*-----------------------------------------------------------------------------
 * Required Includes
 *----------------------------------------------------------------------------*/
#include <stddef.h>
#include <stdlib.h>
#include <cda.h>
#include <enq.h>

/*-----------------------------------------------------------------------------
 * Macros
 *----------------------------------------------------------------------------*/
#define HASH_NULL_ID ( NULL ) 

/*-----------------------------------------------------------------------------
 * Typedef Equivalencies
 *----------------------------------------------------------------------------*/
typedef void HASH_DESTROY_PROC_t( void *data ); 
typedef HASH_DESTROY_PROC_t *HASH_DESTROY_PROC_p_t; 

typedef struct hash__control_s *HASH_ID_t; 

typedef struct hash_item_s 
{
  ENQ_ITEM_t     enq_item;
  char           *key;
  void           *value;
}HASH_ITEM_t, *HASH_ITEM_p_t;


/*-----------------------------------------------------------------------------
 * Method Prototypes
 *----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
 * Method: HASH_create_hash
 * Description: Creates a hash table.
 *----------------------------------------------------------------------------*/
HASH_ID_t HASH_create_hash( const char *name );

/*----------------------------------------------------------------------------
 * Method: HASH_add_item
 * Description: Add a new HASH_ITEM_p_t item to the table.
 *---------------------------------------------------------------------------*/
HASH_ITEM_p_t HASH_add_item( HASH_ID_t hash, HASH_ITEM_p_t item ); 

/*----------------------------------------------------------------------------
 * Method: HASH_find_item
 * Description: Locate the entry in the table identified by the item's key and
 *              return a pointer to a HASH_ITEM_p_t that contains the key and 
 *              the value.
 *---------------------------------------------------------------------------*/
HASH_ITEM_p_t HASH_find_item( HASH_ID_t hash, HASH_ITEM_p_t item );


/*----------------------------------------------------------------------------
 * Method: HASH_delete_item
 * Description: Removes a previously entered item from the table.  The caller
 *              may optionally pass the address of a procedure to call prior
 *              to deleting the item in the table.  If specified, the value
 *              of the item will be passed to this procedure.
 *---------------------------------------------------------------------------*/
HASH_ITEM_p_t HASH_delete_item( HASH_ID_t hash, 
				HASH_ITEM_p_t item, 
				HASH_DESTROY_PROC_p_t destroy_proc ); 


/*----------------------------------------------------------------------------
 * Method: HASH_destroy_hash
 * Description: This method will destroy all items in a hash table, and then 
 *              destroy the table. The caller may optionally pass the address 
 *              of a procedure to call prior to destroying each item in the 
 *              table; if specified, the value of each destroyed item will be 
 *              passed to this procedure.
 *---------------------------------------------------------------------------*/
HASH_ID_t HASH_destroy_hash( HASH_ID_t hash, HASH_DESTROY_PROC_p_t destroy_proc ); 


#endif /* HASH_H */

