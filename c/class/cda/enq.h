/******************************************************************************
 *
 * File: enq.h
 *
 * Description: Public Header for ENQ Project
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 21-Jan-2001  Charles Fordyce        1.1   
 *****************************************************************************/
#ifndef ENQ_H
#define ENQ_H

/******************************************************************************
 * Required Includes
 ******************************************************************************/
#include <stddef.h>
#include <stdlib.h>
#include <cda.h>

/******************************************************************************
 * Macros
 ******************************************************************************/
/* My Macro Solutions */
#define ENQ_GET_TAIL(list) ((list)->blink)
#define ENQ_GET_NEXT(item) ((item)->flink)
#define ENQ_GET_PREV(item) ((item)->blink)
#define ENQ_GET_ITEM_NAME(item) ((const char *)((item)->name))

/* Given Macro solutions */ 
#define ENQ_GET_HEAD(list) ((list)->flink)
#define ENQ_GET_LIST_NAME(list) ((const char *)((list)->name))

/******************************************************************************
 * Typedefs
 ******************************************************************************/
typedef struct enq_item_s
{
  struct enq_item_s *flink;
  struct enq_item_s *blink;
  char              *name;
}ENQ_ITEM_t, * ENQ_ITEM_p_t; 

typedef ENQ_ITEM_t ENQ_ANCHOR_t, * ENQ_ANCHOR_p_t;

/***************************************************************************
 * External Variables
 **************************************************************************/

/***************************************************************************
 * Method prototypes, starting with my code first, the given solutions following.
 **************************************************************************/
/***************************************************************************
 * Method: ENQ_is_list_empty
 * Description: Tells whether the list anchor is pointing to itself.
 ****************************************************************************/
CDA_BOOL_t ENQ_is_list_empty(ENQ_ANCHOR_p_t );

/***************************************************************************
 * Method: ENQ_add_head
 * Description: Adds a non-enqueued item to the head of the list.
 ****************************************************************************/
ENQ_ITEM_p_t ENQ_add_head(ENQ_ANCHOR_p_t, ENQ_ITEM_p_t );

/***************************************************************************
 * Method: ENQ_add_tail
 * Description: Adds a non-enqueued item to the tail of the list.
 ****************************************************************************/
ENQ_ITEM_p_t ENQ_add_tail(ENQ_ANCHOR_p_t, ENQ_ITEM_p_t );

/***************************************************************************
 * Method: ENQ_add_after
 * Description: Adds a non-enqueued item after a given item.
 ****************************************************************************/
ENQ_ITEM_p_t ENQ_add_after(ENQ_ITEM_p_t, ENQ_ITEM_p_t );

/***************************************************************************
 * Method: ENQ_add_before
 * Description: Adds a non-enqueued item in front of a given item.
 ****************************************************************************/
ENQ_ITEM_p_t ENQ_add_before(ENQ_ITEM_p_t, ENQ_ITEM_p_t );

/***************************************************************************
 * Method: ENQ_deq_head
 * Description: Removes the item at the head of the list and returns it.
 ****************************************************************************/
ENQ_ITEM_p_t ENQ_deq_head(ENQ_ANCHOR_p_t );

/***************************************************************************
 * Method: ENQ_deq_tail
 * Description: Removes the item at the tail of the list and returns it.
 ****************************************************************************/
ENQ_ITEM_p_t ENQ_deq_tail(ENQ_ANCHOR_p_t );

/***************************************************************************
 * Method: ENQ_destroy_list
 * Description: Empties a list, frees list anchor memory and explicitly returns NULL. 
 ****************************************************************************/
ENQ_ANCHOR_p_t ENQ_destroy_list(ENQ_ANCHOR_p_t );


/***************************************************************************
 * Prototypes for the given method solutions.
 ****************************************************************************/
/***************************************************************************
 * Method: ENQ_create_list
 * Description: 
 ****************************************************************************/
ENQ_ANCHOR_p_t ENQ_create_list(const char *);

/***************************************************************************
 * Method: ENQ_create_item
 * Description: 
 ****************************************************************************/
ENQ_ITEM_p_t ENQ_create_item(const char *, size_t);

/***************************************************************************
 * Method: ENQ_is_item_enqed
 * Description: 
 ****************************************************************************/
CDA_BOOL_t ENQ_is_item_enqed(ENQ_ITEM_p_t );

/***************************************************************************
 * Method: ENQ_deq_item
 * Description: 
 ****************************************************************************/
ENQ_ITEM_p_t ENQ_deq_item(ENQ_ITEM_p_t );

/***************************************************************************
 * Method: ENQ_destroy_item
 * Description: 
 ****************************************************************************/
ENQ_ITEM_p_t ENQ_destroy_item(ENQ_ITEM_p_t );

/***************************************************************************
 * Method: ENQ_empty_list
 * Description: 
 ****************************************************************************/
ENQ_ANCHOR_p_t ENQ_empty_list(ENQ_ANCHOR_p_t );

#endif /* ENQ_H */
