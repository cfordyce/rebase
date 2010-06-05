/******************************************************************************
 *
 * File: enq.c
 *
 * Description: Source file for Project 2 functions
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 25-Jan-2001  Charles Fordyce     1.1
 *****************************************************************************/
/*****************************************************************************
 * includes
 *****************************************************************************/
#include <stdlib.h>
#include <stddef.h>
#include <enq.h>
#include <cda.h>

/*****************************************************************************
 * Methods, starting with my code, then the given solutions.
 *****************************************************************************/

CDA_BOOL_t ENQ_is_list_empty(ENQ_ANCHOR_p_t list)
{
  CDA_BOOL_t rcode =
    (list->flink == list ? CDA_TRUE : CDA_FALSE);
  
  return rcode;
}


ENQ_ITEM_p_t ENQ_add_head(ENQ_ANCHOR_p_t list, ENQ_ITEM_p_t item)
{
  CDA_ASSERT(!ENQ_is_item_enqed(item));
  
  list->flink->blink = item;
  item->flink = list->flink;
  item->blink = list;
  list->flink = item;

  return item;
}


ENQ_ITEM_p_t ENQ_add_tail(ENQ_ANCHOR_p_t list, ENQ_ITEM_p_t item)
{
  CDA_ASSERT(!ENQ_is_item_enqed(item));
  
  item->flink = list;
  item->blink = list->blink;
  list->blink->flink = item;
  list->blink = item;

  return item;
}


ENQ_ITEM_p_t ENQ_add_before(ENQ_ITEM_p_t item, ENQ_ITEM_p_t before)
{
  CDA_ASSERT(!ENQ_is_item_enqed(item));

  item->flink = before;
  item->blink = before->blink;
  before->blink->flink = item;
  before->blink = item;

  return item;
}


ENQ_ITEM_p_t ENQ_add_after(ENQ_ITEM_p_t item, ENQ_ITEM_p_t after)
{
  CDA_ASSERT(!ENQ_is_item_enqed(item));

  item->blink = after;
  item->flink = after->flink;
  after->flink->blink = item;
  after->flink = item;
  
  return item;
}


ENQ_ITEM_p_t ENQ_deq_head(ENQ_ANCHOR_p_t list)
{
  ENQ_ITEM_p_t item = list->flink;
  list->flink = list->flink->flink;
  list->flink->blink = list;
  item->flink = item;
  item->blink = item;
  
  return item;
}     


ENQ_ITEM_p_t ENQ_deq_tail(ENQ_ANCHOR_p_t list)
{
  ENQ_ITEM_p_t item = list->blink;
  list->blink = list->blink->blink;
  list->blink->flink = list;
  item->flink = item;
  item->blink = item;
  
  return item;
}


ENQ_ANCHOR_p_t ENQ_destroy_list(ENQ_ANCHOR_p_t list)
{
  while(!ENQ_is_list_empty(list))
      ENQ_destroy_item(list->flink);
  
  CDA_free(list->name); 
  CDA_free(list);
  
  return NULL;
}


/***************************************************************************
 *  The given method solutions.
 ***************************************************************************/

ENQ_ANCHOR_p_t ENQ_create_list(const char *name)
{
  ENQ_ANCHOR_p_t list = CDA_NEW(ENQ_ANCHOR_t);

  list->flink = list;
  list->blink = list;
  list->name = CDA_NEW_STR_IF(name);
  return list;
}
     

ENQ_ITEM_p_t ENQ_create_item(const char * name, size_t size)
{
  ENQ_ITEM_p_t item = (ENQ_ITEM_p_t)CDA_malloc(size);
  
  CDA_ASSERT(size >= sizeof(ENQ_ITEM_t));
  item->flink = item;
  item->blink = item;
  item->name = CDA_NEW_STR_IF(name);
  return item;
}


CDA_BOOL_t ENQ_is_item_enqed(ENQ_ITEM_p_t item)
{
  CDA_BOOL_t rcode =
    (item->flink == item ? CDA_FALSE : CDA_TRUE);

  return rcode;
}


ENQ_ITEM_p_t ENQ_deq_item(ENQ_ITEM_p_t item)
{
  item->blink->flink = item->flink;
  item->flink->blink = item->blink;
  item->flink = item;
  item->blink = item;
  return item;
}


ENQ_ITEM_p_t ENQ_destroy_item(ENQ_ITEM_p_t item)
{
  ENQ_deq_item(item);
  CDA_free(item->name);
  CDA_free(item);
  
  return NULL;
}


ENQ_ANCHOR_p_t ENQ_empty_list(ENQ_ANCHOR_p_t list)
{
  while(!ENQ_is_list_empty(list))
    ENQ_destroy_item(list->flink);
  
  return list;
}

