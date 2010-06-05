/*----------------------------------------------------------------------------
 *
 * File: stk.c
 *
 * Description: Source file for STK Module - Project 3
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 11-Feb-2001  Charles Fordyce     1.0
 *---------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
 * includes
 *---------------------------------------------------------------------------*/
#include <stdlib.h>
#include <enq.h>
#include <cda.h>
#include <stkp.h>

/*----------------------------------------------------------------------------
 * Methods starting with my code first, then the given solutions.
 *---------------------------------------------------------------------------*/
void STK_push_item( STK_ID_t stack, void * item )
{
  if( STK_is_stack_full( stack ) )
    abort();
  
  *stack->sptr = item;
  ++stack->sptr;
}


void *STK_pop_item( STK_ID_t stack )
{
  CDA_ASSERT( ! STK_is_stack_empty( stack ) );

  --stack->sptr;
  return *stack->sptr;
}


CDA_BOOL_t STK_is_stack_full( STK_ID_t stack )
{
  CDA_BOOL_t rcode =
    stack->stack + stack->size == stack->sptr ? CDA_TRUE : CDA_FALSE;
  
  return rcode;
}

/*----------------------------------------------------------------------------
 *  The given method solutions.
 *---------------------------------------------------------------------------*/

STK_ID_t  STK_create_stack(size_t size)
{
  STK__CONTROL_p_t stack = CDA_NEW(STK__CONTROL_t);

  stack->stack = CDA_calloc(size, sizeof(void *));
  stack->sptr = stack->stack;
  stack->size = size;
  
  return (STK_ID_t)stack;
}


void *STK_peek_item(STK_ID_t stack)
{
  CDA_ASSERT(stack->sptr != stack->stack);
  return *(stack->sptr - 1);
}


CDA_BOOL_t STK_is_stack_empty(STK_ID_t stack)
{
  CDA_BOOL_t rcode =
    stack->sptr == stack->stack ? CDA_TRUE : CDA_FALSE;

  return rcode;
}


void STK_clear_stack(STK_ID_t stack)
{
  stack->sptr = stack->stack;
}


STK_ID_t STK_destroy_stack(STK_ID_t stack)
{
  CDA_free(stack->stack);
  CDA_free(stack);

  return STK_NULL_ID;
}

