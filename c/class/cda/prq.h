/*-----------------------------------------------------------------------------
 *
 * File: prq.h
 *
 * Description: Public Header for PRQ Module - Project 4
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 24-Feb-2001  Charles Fordyce        1.0
 *----------------------------------------------------------------------------*/
#ifndef PRQ_H
#define PRQ_H

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
#define PRQ_NULL_ID ( NULL ) 

#define PRQ_GET_DATA( item ) ( item->data )

#define PRQ_GET_PRIORITY( item ) ( item->priority ) 

/*-----------------------------------------------------------------------------
 * Typedef Equivalencies
 *----------------------------------------------------------------------------*/
typedef void PRQ_DESTROY_PROC_t( void *data ); 
typedef PRQ_DESTROY_PROC_t *PRQ_DESTROY_PROC_p_t; 

typedef struct prq__control_s *PRQ_ID_t; 

typedef struct prq_item_s 
{ 
  ENQ_ITEM_t     enq_item; 
  void           *data; 
  CDA_UINT32_t   priority; 
} PRQ_ITEM_t, *PRQ_ITEM_p_t; 

/*-----------------------------------------------------------------------------
 * External Variables
 *----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
 * Method Prototypes
 *----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
 * Method: PRQ_create_queue
 * Description: Creates a priority queue
 *----------------------------------------------------------------------------*/
PRQ_ID_t PRQ_create_queue( const char *, CDA_UINT32_t );

/*----------------------------------------------------------------------------
 * Method: PRQ_create_item
 * Description:This method will create an item that is a subclass of ENQ_ITEM_t, and that can be added 
 * to a priority queue. The item is created in an unenqueued state. 
 *---------------------------------------------------------------------------*/
PRQ_ITEM_p_t PRQ_create_item( void *value, CDA_UINT32_t priority ); 

/*----------------------------------------------------------------------------
 * Method: PRQ_is_queue_empty
 * Description: This method will determine whether a priority queue is empty. 
 *---------------------------------------------------------------------------*/
CDA_BOOL_t PRQ_is_queue_empty( PRQ_ID_t queue );

/*----------------------------------------------------------------------------
 * Method: PRQ_add_item
 * Description: This method will add an item to a priority queue. 
 *---------------------------------------------------------------------------*/
PRQ_ITEM_p_t PRQ_add_item( PRQ_ID_t queue, PRQ_ITEM_p_t item ); 

/*----------------------------------------------------------------------------
 * Method: PRQ_remove_item
 * Description: This method removes and returns the highest priority item from a priority queue. 
 *---------------------------------------------------------------------------*/
PRQ_ITEM_p_t PRQ_remove_item( PRQ_ID_t queue ); 

/*----------------------------------------------------------------------------
 * Method: PRQ_deq_item
 * Description: Dequeues an item and returns it.
 *---------------------------------------------------------------------------*/
PRQ_ITEM_p_t PRQ_deq_item( PRQ_ITEM_p_t );

/*----------------------------------------------------------------------------
 * Method: PRQ_enq_pri_head
 * Description: Enqueues an item at the head of its priority class in queue, returns itself.
 *---------------------------------------------------------------------------*/
PRQ_ITEM_p_t PRQ_enq_pri_head( PRQ_ID_t, PRQ_ITEM_p_t );

/*----------------------------------------------------------------------------
 * Method: PRQ_deq_pri_head
 * Description: Dequeues and returns the item at the head of a priority class.
 *---------------------------------------------------------------------------*/
PRQ_ITEM_p_t PRQ_deq_pri_head( PRQ_ID_t, CDA_UINT32_t );

/*----------------------------------------------------------------------------
 * Method: PRQ_destroy_item
 * Description: This method will destroy a priority queue item. 
 *---------------------------------------------------------------------------*/
PRQ_ITEM_p_t PRQ_destroy_item( PRQ_ITEM_p_t item ); 

/*----------------------------------------------------------------------------
 * Method: PRQ_empty_queue
 * Description: This method will remove and destroy all items in a priority queue. The caller may 
 * optionally pass the address of a procedure to call prior to destroying the item; if specified, 
 * the value of each destroyed item will be passed to this procedure. 
 *---------------------------------------------------------------------------*/
PRQ_ID_t PRQ_empty_queue( PRQ_ID_t queue, PRQ_DESTROY_PROC_p_t destroy_proc ); 

/*----------------------------------------------------------------------------
 * Method: PRQ_destroy_queue
 * Description: This method will destroy all items in a priority queue, and then destroy the queue. The 
 * caller may optionally pass the address of a procedure to call prior to destroying each item 
 * in the queue; if specified, the value of each destroyed item will be passed to this 
 * procedure. 
 *---------------------------------------------------------------------------*/
PRQ_ID_t PRQ_destroy_queue( PRQ_ID_t queue, PRQ_DESTROY_PROC_p_t destroy_proc ); 


#endif /* PRQ_H */

