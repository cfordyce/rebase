/*-----------------------------------------------------------------------------
 *
 * File: stk.h
 *
 * Description: Public Header for STK Module - Project 3
 *
 * Revision History2
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 11-Feb-2001  Charles Fordyce        1.0
 *----------------------------------------------------------------------------*/
#ifndef STK_H
#define STK_H

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
#define STK_NULL_ID (NULL)

/*-----------------------------------------------------------------------------
 * Typedefs
 *----------------------------------------------------------------------------*/
typedef struct stk__control_s * STK_ID_t;

/*-----------------------------------------------------------------------------
 * Method Prototypes
 *----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
 * Method: STK_create_stack
 * Description: Create a stack of a given size.
 *----------------------------------------------------------------------------*/
STK_ID_t STK_create_stack(size_t size);

/*-----------------------------------------------------------------------------
 * Method: STK_push_item
 * Description: Push an item onto the stack.
 *----------------------------------------------------------------------------*/
void STK_push_item(STK_ID_t stack, void *item);

/*-----------------------------------------------------------------------------
 * Method: STK_pop_item
 * Description: Pop an item off the stack.
 *----------------------------------------------------------------------------*/
void *STK_pop_item(STK_ID_t stack);

/*-----------------------------------------------------------------------------
 * Method: STK_peek_item
 * Description: Returns the top item from the stack without removing it.
 *----------------------------------------------------------------------------*/
void * STK_peek_item(STK_ID_t stack);

/*-----------------------------------------------------------------------------
 * Method: STK_is_stack_empty
 * Description: Returns true or false depending on stack population.
 *----------------------------------------------------------------------------*/
CDA_BOOL_t STK_is_stack_empty(STK_ID_t stack);

/*-----------------------------------------------------------------------------
 * Method: STK_is_stack_full
 * Description: Returns true or false depending on stack population.
 *----------------------------------------------------------------------------*/
CDA_BOOL_t STK_is_stack_full(STK_ID_t stack);

/*-----------------------------------------------------------------------------
 * Method: STK_clear_stack
 * Description: Removes all items from stack, leaving it empty.
 *----------------------------------------------------------------------------*/
void STK_clear_stack(STK_ID_t stack);

/*-----------------------------------------------------------------------------
 * Method: STK_destroy_stack
 * Description: Frees all resources allocated for the stack.
 *----------------------------------------------------------------------------*/
STK_ID_t STK_destroy_stack(STK_ID_t stack); 

#endif /* STK_H */
