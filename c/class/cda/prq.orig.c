/*----------------------------------------------------------------------------
 *
 * File: prq.c
 *
 * Description: Source file for PRQ Module - Project 4
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 21-Jan-2001  Charles Fordyce     1.0
 *---------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
 * includes
 *---------------------------------------------------------------------------*/
#include <stdlib.h>
#include <enq.h>
#include <cda.h>
#include <prqp.h>

/*----------------------------------------------------------------------------
 * Definitions
 *---------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 * Method Definitions
 *---------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
 * Method: PRQ_create_queue()
 *---------------------------------------------------------------------------*/
PRQ_ID_t PRQ_create_queue( const char *name, CDA_UINT32_t max_priority ) 
{ 
  /*
 In the robust implementation we will have to allocate a control structure, then allocate an array of 
pointers-to-anchors, then create a list for each element of the array. And to remove an 
item from the queue, we must first locate the non-empty queue associated with the 
highest priority class and then remove its head. 
 e.g. remove_head(if queue->head->list->flink != list)
*/
  int inx = 0;
  
  PRQ__CONTROL_p_t queue = CDA_NEW( PRQ__CONTROL_t );
  queue->anchor_array = (ENQ_ANCHOR_p_t)CDA_calloc(max_priority, sizeof(ENQ_ANCHOR_p_t));
  queue->max_priority = max_priority;
  queue->name = CDA_NEW_STR_IF( name );
  
  for( ; max_priority > inx; ++inx )
    {
      queue->anchor_array = ENQ_create_list( NULL );
      queue->anchor_array++;
    }

  return queue;
} 

/*----------------------------------------------------------------------------
 * Method: PRQ_create_item
 *---------------------------------------------------------------------------*/
PRQ_ITEM_p_t PRQ_create_item( void *data, CDA_UINT32_t priority ) 
{ 
  PRQ_ITEM_p_t item = NULL; 
  
  item = (PRQ_ITEM_p_t)ENQ_create_item( NULL, sizeof(PRQ_ITEM_t) );
  
  item->data = data; 
  item->priority = priority; 
  return item; 
} 


/*----------------------------------------------------------------------------
 * Method:  PRQ_add_item
 *---------------------------------------------------------------------------*/
PRQ_ITEM_p_t PRQ_add_item( PRQ_ID_t queue, PRQ_ITEM_p_t item ) 
{ 
    CDA_BOOL_t     found  = CDA_FALSE; 
    PRQ_ITEM_p_t   temp   = NULL; 
    ENQ_ANCHOR_p_t anchor = queue->anchor_array+item->priority; 

    if ( item->priority > queue->max_priority ) 
      abort(); 

    temp = (PRQ_ITEM_p_t)ENQ_GET_HEAD( anchor ); 

    while ( !found && temp != NULL ) 
      if ( temp == (PRQ_ITEM_p_t)anchor) 
	temp = NULL; 
      else if ( temp->priority < item->priority ) 
	found = CDA_TRUE; 
      else 
	temp = (PRQ_ITEM_p_t)ENQ_GET_NEXT( (ENQ_ITEM_p_t)temp ); 

    if ( temp != NULL ) 
      ENQ_add_before( (ENQ_ITEM_p_t)item, (ENQ_ITEM_p_t)temp ); 
    else 
      ENQ_add_tail( anchor, (ENQ_ITEM_p_t)item ); 

    return item; 
} 

/*----------------------------------------------------------------------------
 * Method: PRQ_remove_item
 *---------------------------------------------------------------------------*/
PRQ_ITEM_p_t PRQ_remove_item( PRQ_ID_t queue ) 
{ 
  ENQ_ITEM_p_t item = ENQ_deq_head( queue->anchor_array); 
  if ( item == queue->anchor_array) 
    item = NULL; 
  return (PRQ_ITEM_p_t)item; 
} 


/*----------------------------------------------------------------------------
 * Method: PRQ_deq_item
 *---------------------------------------------------------------------------*/
PRQ_ITEM_p_t PRQ_deq_item( PRQ_ITEM_p_t );

/*----------------------------------------------------------------------------
 * Method: PRQ_enq_pri_head
 *---------------------------------------------------------------------------*/
PRQ_ITEM_p_t PRQ_enq_pri_head( PRQ_ID_t, PRQ_ITEM_p_t );

/*----------------------------------------------------------------------------
 * Method: PRQ_deq_pri_head
 *---------------------------------------------------------------------------*/
PRQ_ITEM_p_t PRQ_deq_pri_head( PRQ_ID_t, PRQ_ITEM_p_t );

/*----------------------------------------------------------------------------
 * Method: PRQ_destroy_item
 *---------------------------------------------------------------------------*/
PRQ_ITEM_p_t PRQ_destroy_item( PRQ_ITEM_p_t item ) 
{ 
  ENQ_destroy_item( (ENQ_ITEM_p_t)item ); 
  return NULL; 
} 
 
/*----------------------------------------------------------------------------
 * Method: PRQ_is_queue_empty
 *---------------------------------------------------------------------------*/
CDA_BOOL_t PRQ_is_queue_empty( PRQ_ID_t queue ) 
{ 
    CDA_BOOL_t  rcode   = ENQ_is_list_empty( queue->anchor_array); 
         return rcode; 
} 

/*----------------------------------------------------------------------------
 * Method: PRQ_empty_queue
 *---------------------------------------------------------------------------*/
PRQ_ID_t PRQ_empty_queue( PRQ_ID_t queue, PRQ_DESTROY_PROC_p_t destroy_proc ) 
{ 
  ENQ_ANCHOR_p_t anchor= queue->anchor_array; 
  PRQ_ITEM_p_t   item   = NULL; 
  while ( !ENQ_is_list_empty( anchor) ) 
    { 
      item = (PRQ_ITEM_p_t)ENQ_GET_HEAD( anchor); 
      if ( destroy_proc != NULL ) 
	destroy_proc( item->data ); 
      ENQ_destroy_item( (ENQ_ITEM_p_t)item ); 
    } 
  return queue; 
}

/*----------------------------------------------------------------------------
 * Method: PRQ_destroy_queue
 *---------------------------------------------------------------------------*/
PRQ_ID_t PRQ_destroy_queue( PRQ_ID_t queue, PRQ_DESTROY_PROC_p_t destroy_proc ) 
{ 
  PRQ_empty_queue( queue, destroy_proc ); 
  ENQ_destroy_list( queue->anchor_array); 
  CDA_free( queue ); 
  return PRQ_NULL_ID; 
} 
