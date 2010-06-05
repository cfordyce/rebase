/******************************************************************************
 *
 * File: list.c
 *
 * System: abstract linked list tool kit
 * 
 * Description:  TBD
 *
 * External Functions:
 *   
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 01-Jan-2000  Some Programmer     Original
 *****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <list.h>

/* LIST_item_s: internal list item type */
typedef struct LIST_item_s
{
    LIST_item_p_t next;
    void * user_data;
} LIST_item_t;

/* LIST_s: internal list type */
typedef struct LIST_s
{
    LIST_item_p_t head;
    LIST_item_p_t tail;
    /* currently, list name is not used in the module */
    char list_name[LIST_NAME_LEN+1];
} LIST_t;

/*---------------------------------------------------------------------------*
 * LIST__create_item 
 * Description: Internal function to create a list item
 * Returns: pointer to list item
 *---------------------------------------------------------------------------*/
static LIST_item_p_t LIST__create_item( 
        void * user_data    /* <I> item data pointer */
)
{
    LIST_item_p_t new_item = NULL;

    new_item = malloc( sizeof( LIST_item_t ) );
    if ( new_item == NULL )
        abort();
    new_item->user_data = user_data;
    new_item->next = NULL;
    return new_item;
}
/*---------------------------------------------------------------------------*
 * LIST_create_list 
 * Description: create abstract singly linked list
 *---------------------------------------------------------------------------*/
extern LIST_p_t LIST_create_list( 
        const char * list_name  /* <I> - list name or NULL */
)
{
    LIST_p_t ptr = NULL;
    ptr = malloc( sizeof( LIST_t) );

    ptr->head = NULL;
    ptr->tail = NULL;
    strncpy( ptr->list_name, list_name, LIST_NAME_LEN );
    ptr->list_name[LIST_NAME_LEN] = '\0';
    if ( list_name )
    {
        strncpy( ptr->list_name, list_name, LIST_NAME_LEN );
        ptr->list_name[LIST_NAME_LEN] = '\0';
    }
    return ptr;
}
/*---------------------------------------------------------------------------*
 * LIST_destroy_list 
 * Description: deletes abstract list memory - 
 *    given list head, a desctroy proc is applied to each item's data
 *    Pass item_destroy_proc == NULL, to ignore destroy proc 
 *---------------------------------------------------------------------------*/
extern void LIST_destroy_list( 
        LIST_p_t * list_head,                         /* <I> the list */
        void (*item_destroy_proc)( void * user_data ) /* <I> destroy proc OR NULL */ 
)
{
    LIST_item_p_t list_item = (*list_head)->head;

    while( list_item )
    {
        LIST_item_p_t tmp_item = NULL;

        if ( item_destroy_proc )
            item_destroy_proc( list_item->user_data );

        tmp_item = list_item;
        list_item = list_item->next;
        free( tmp_item );
    }
    *list_head = NULL;
}
/*---------------------------------------------------------------------------*
 * LIST_operate_on_list 
 *---------------------------------------------------------------------------*/
extern void LIST_operate_on_list( 
        LIST_p_t list_head,                  /* <I> the list */
        void (*item_operate_proc)( void * )  /* <I> proc to apply to each list item */
)
{
    LIST_item_p_t list_item = list_head->head;

    while( list_item )
    {
        LIST_operate_on_item( list_item, item_operate_proc );
        list_item = list_item->next;
    }
}

/*---------------------------------------------------------------------------*
 * LIST_find_item_in_list 
 * Description: finds an item in the list.  The item_find_proc returns
 *       TRUE, when list item is found. key_data is passed through
 *       to item_find_proc.
 * Returns:  item pointer when item found, otherwise NULL
 *---------------------------------------------------------------------------*/
extern LIST_item_p_t LIST_find_item_in_list( 
        LIST_p_t list_head,                                         /* <I> the list */
        int (*item_find_proc)( void * user_data, void * key_data ), /* <I> find proc */
        void * key_data                                             /*  <I> pass through data */
)
{
    LIST_item_p_t list_item = list_head->head;

    while ( list_item && !item_find_proc( list_item->user_data, key_data ) )
       list_item = list_item->next;
    return list_item;
}

/*---------------------------------------------------------------------------*
 * LIST_add_to_list 
 * Description: add user object to list
 *---------------------------------------------------------------------------*/
extern LIST_item_p_t LIST_add_to_list( 
        LIST_p_t list_head,   /* <I> the list */
        void * user_data      /* <I> pointer to user object */
)
{
    LIST_item_p_t new_item = NULL;


    new_item = LIST__create_item( user_data );

    if ( list_head->head == NULL )
    {
        list_head->head = new_item;
        list_head->tail = new_item;
    }
    else 
    {
        list_head->tail->next = new_item;
        list_head->tail = new_item;
    }
    return new_item;
}

/*---------------------------------------------------------------------------*
 * LIST_remove_from_list
 * Description: remove and destroy item from list - does not destroy 
 *    user object!!
 * Returns:  pointer to user object
 *---------------------------------------------------------------------------*/
extern void * LIST_remove_from_list( 
        LIST_p_t list_head, 
        LIST_item_p_t * list_item )
{
    void * ptr = (*list_item)->user_data;
    LIST_item_p_t list_ptr = list_head->head;
    LIST_item_p_t prev = list_head->head;

    while ( list_ptr && list_ptr != *list_item )
    {
        prev = list_ptr;
        list_ptr = list_ptr->next;
    }

    if ( list_ptr )
    {
        if ( list_ptr == list_head->head )
        {
           list_head->head = list_ptr->next;
        }
        else 
        {
           prev->next = list_ptr->next;
        }
        free( list_ptr );
    }

    return ptr;
}

/*---------------------------------------------------------------------------*
 * LIST_operate_on_item 
 * Description: apply user proc to user data of each item 
 *---------------------------------------------------------------------------*/
extern void LIST_operate_on_item( 
        LIST_item_p_t list_item,                       /* <I> the list */
        void (*item_operate_proc)( void * user_data )  /* <I> proc to user data */
)
{
    assert( list_item );
    assert( item_operate_proc );
    item_operate_proc( list_item->user_data );
}
