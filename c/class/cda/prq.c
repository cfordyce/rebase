/*----------------------------------------------------------------------------
 *
 * File: prq.c
 *
 * Description: Source file for PRQ Module - Project 4
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 24-Feb-2001  Charles Fordyce     1.0
 *---------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
 * includes
 *---------------------------------------------------------------------------*/
#include <stdlib.h>
#include <enq.h>
#include <cda.h>
#include <prqp.h>

/*----------------------------------------------------------------------------
 * Method Definitions
 *---------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
 * Method: PRQ_create_queue()
 *---------------------------------------------------------------------------*/
PRQ_ID_t PRQ_create_queue( const char *name, CDA_UINT32_t max_priority ) 
{ 
  int inx = 0;
  PRQ__CONTROL_p_t queue = CDA_NEW( PRQ__CONTROL_t );
  queue->anchor_array = CDA_calloc(max_priority+1, sizeof(ENQ_ANCHOR_p_t));
  
  for ( ; inx <= max_priority; ++inx )
    queue->anchor_array[inx] = ENQ_create_list( NULL ); 
  
  queue->max_priority = max_priority;
  
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
  if ( item->priority > queue->max_priority || item->priority < 0 ) 
    abort(); 
  
  ENQ_add_tail( (ENQ_ANCHOR_p_t)queue->anchor_array[item->priority] , (ENQ_ITEM_p_t)item );
  
  return item; 
} 


/*----------------------------------------------------------------------------
 * Method: PRQ_remove_item
 *---------------------------------------------------------------------------*/
PRQ_ITEM_p_t PRQ_remove_item( PRQ_ID_t queue ) 
{ 
  int inx = queue->max_priority;
  PRQ_ITEM_p_t item = NULL;
  
  while (item == NULL && inx >= 0 )
    {
      item = (PRQ_ITEM_p_t)ENQ_deq_head( (ENQ_ANCHOR_p_t)queue->anchor_array[inx] ); 
      
      if ( (ENQ_ANCHOR_p_t)item == queue->anchor_array[inx--] ) 
	item = NULL; 
    }
  
  return item; 
} 


/*----------------------------------------------------------------------------
 * Method: PRQ_deq_item
 *---------------------------------------------------------------------------*/
PRQ_ITEM_p_t PRQ_deq_item( PRQ_ITEM_p_t item )
{
  ENQ_deq_item( (ENQ_ITEM_p_t)item );
  
  return item;
}

/*----------------------------------------------------------------------------
 * Method: PRQ_enq_pri_head
 *---------------------------------------------------------------------------*/
PRQ_ITEM_p_t PRQ_enq_pri_head( PRQ_ID_t queue, PRQ_ITEM_p_t item )
{
  if ( item->priority > queue->max_priority || item->priority < 0 ) 
    abort(); 
  
  ENQ_add_head( (ENQ_ANCHOR_p_t)queue->anchor_array[item->priority] , (ENQ_ITEM_p_t)item );
  
  return item; 
}

/*----------------------------------------------------------------------------
 * Method: PRQ_deq_pri_head
 *---------------------------------------------------------------------------*/
PRQ_ITEM_p_t PRQ_deq_pri_head( PRQ_ID_t queue, CDA_UINT32_t priority )
{
  PRQ_ITEM_p_t item = NULL;

  if ( priority > queue->max_priority || priority < 0 ) 
    abort(); 
  
  item = ( PRQ_ITEM_p_t)ENQ_deq_head( (ENQ_ANCHOR_p_t)queue->anchor_array[priority] );
  
  return item;
}

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
  int inx = queue->max_priority;
  CDA_BOOL_t rcode = CDA_FALSE;
  
  while (rcode != CDA_FALSE && inx >= 0 )
    rcode = ENQ_is_list_empty( (ENQ_ANCHOR_p_t)queue->anchor_array[inx--] ); 
  
  return rcode; 
} 


/*----------------------------------------------------------------------------
 * Method: PRQ_empty_queue
 *---------------------------------------------------------------------------*/
PRQ_ID_t PRQ_empty_queue( PRQ_ID_t queue, PRQ_DESTROY_PROC_p_t destroy_proc ) 
{ 
  int inx = queue->max_priority;
  PRQ_ITEM_p_t item = NULL;
  
  for ( ; inx >= 0; --inx )
    while ( ! ENQ_is_list_empty( (ENQ_ANCHOR_p_t)queue->anchor_array[inx] ) ) 
      {
	item = (PRQ_ITEM_p_t)ENQ_deq_head( (ENQ_ANCHOR_p_t)queue->anchor_array[inx] );
	
	if ( destroy_proc != NULL ) 
	  destroy_proc( item->data ); 
	
	PRQ_destroy_item( item );
      }
  
  return queue; 
}


/*----------------------------------------------------------------------------
 * Method: PRQ_destroy_queue
 *---------------------------------------------------------------------------*/
PRQ_ID_t PRQ_destroy_queue( PRQ_ID_t queue, PRQ_DESTROY_PROC_p_t destroy_proc ) 
{ 
  int inx = queue->max_priority;
  
  PRQ_empty_queue( queue, destroy_proc ); 
  
  for ( ; inx >= 0; --inx )
    ENQ_destroy_list( (ENQ_ANCHOR_p_t)queue->anchor_array[inx] ); 
  
  CDA_free( queue->anchor_array );
  CDA_free( queue ); 
  
  return PRQ_NULL_ID; 
  
} 
