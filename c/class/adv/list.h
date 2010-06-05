#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
/******************************************************************************
 *
 * File: list.h
 *
 * System: abstract linked list tool kit
 * 
 * Description: TBD
 *
 * Revision History
 * Date         Programmer Name     Description
 * -----------  ------------------  ----------------
 * 01-Jan-2000  Some Programmer     Original
 *****************************************************************************/

#define LIST_NAME_LEN (40)

typedef struct LIST_s * LIST_p_t;
typedef struct LIST_item_s * LIST_item_p_t;

/*---------------------------------------------------------------------------*
 * LIST_create_list 
 * Description: create abstract singly linked list
 *---------------------------------------------------------------------------*/
extern LIST_p_t LIST_create_list( 
        const char * list_name  /* <I> - list name or NULL */
);
/*---------------------------------------------------------------------------*
 * LIST_destroy_list 
 * Description: deletes abstract list memory - 
 *    given list head, a desctroy proc is applied to each item's data
 *    Pass item_destroy_proc == NULL, to ignore destroy proc 
 *---------------------------------------------------------------------------*/
extern void LIST_destroy_list( 
        LIST_p_t * list_head,                         /* <I> the list */
        void (*item_destroy_proc)( void * user_data ) /* <I> destroy proc OR NULL */ 
);
/*---------------------------------------------------------------------------*
 * LIST_operate_on_list 
 *---------------------------------------------------------------------------*/
extern void LIST_operate_on_list( 
        LIST_p_t list_head,                  /* <I> the list */
        void (*item_operate_proc)( void * )  /* <I> proc to apply to each list item */
);

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
);

/*---------------------------------------------------------------------------*
 * LIST_add_to_list 
 * Description: add user object to list
 *---------------------------------------------------------------------------*/
extern LIST_item_p_t LIST_add_to_list( 
        LIST_p_t list_head,   /* <I> the list */
        void * user_data      /* <I> pointer to user object */
);

/*---------------------------------------------------------------------------*
 * LIST_remove_from_list
 * Description: remove and destroy item from list - does not destroy 
 *    user object!!
 * Returns:  pointer to user object
 *---------------------------------------------------------------------------*/
extern void * LIST_remove_from_list( 
        LIST_p_t list_head, 
        LIST_item_p_t * list_item 
);

/*---------------------------------------------------------------------------*
 * LIST_operate_on_item 
 * Description: apply user proc to user data of each item 
 *---------------------------------------------------------------------------*/
extern void LIST_operate_on_item( 
        LIST_item_p_t list_item,                       /* <I> the list */
        void (*item_operate_proc)( void * user_data )  /* <I> proc to user data */
);


#endif
