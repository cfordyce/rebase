/*--------------------------------
  PRQ Test Driver

--------------------------------*/
  
#include <stdlib.h>
#include <enq.h>
#include <cda.h>
#include <prqp.h>

/*------------------------------------------------------------
  
  gcc -c -g -ansi -pedantic test_prq.c prq.c; gcc -o prqq cda.o enq.o test_prq.o prq.o

  -----------------------------------------------------------*/

PRQ_ID_t PRQ_create_queue( const char *, CDA_UINT32_t );
void print_list(char *, ENQ_ANCHOR_p_t);

int main(void)
{
  CDA_UINT32_t max_test[] = {9,9,9,3,4,5,6,7,8,9};
  char * name = "PRQ_TEST_QUEUE";
  int * data[] = {0,1,2,3,4,5,6,7,8,9}; 
  int inx = 0;
  PRQ_ITEM_p_t item = NULL, rmitem = NULL;
  PRQ_ITEM_p_t item_array[10];
  
    
  PRQ_ID_t queue =  PRQ_create_queue( name, 10 );
  
  
  /*-----------PRQ_create_item-------------------*/
  for (; inx < 10; ++inx )
    {
      item_array[inx] = PRQ_create_item( data[inx], max_test[inx] );
      printf("item_array[%d] = %p : priority =  %d\n",inx, item_array[inx], max_test[inx]);
    }
  
  
  
  /*CDA_ASSERT( (ENQ_ITEM_p_t)item->flink == (ENQ_ITEM_p_t)item->blink ); 
  
  CDA_ASSERT( item != NULL );
  
  CDA_ASSERT( item->priority >= 0 );
  printf("PRQ_create_item passed\n");
  */

  /*-----------PRQ_add_item-------------------*/
  for (inx = 0; inx < 10; ++inx )
    {
      item = PRQ_add_item( queue, item_array[inx] ); 
      CDA_ASSERT( ENQ_is_item_enqed( (ENQ_ITEM_p_t)item ) );
      CDA_ASSERT( item == item_array[inx]);
    }
  printf("PRQ_add_item passed\n");
  
  
  /*-----------PRQ_remove_item-------------------*/
  rmitem = PRQ_remove_item( queue );
  CDA_ASSERT( ! ENQ_is_item_enqed( (ENQ_ITEM_p_t)rmitem ) );
  CDA_ASSERT( rmitem == item_array[10] );
  
  PRQ_add_item( queue, rmitem );
  CDA_ASSERT( ENQ_is_item_enqed( (ENQ_ITEM_p_t)rmitem ) );
  printf("PRQ_remove_item passed\n");


  /*-----------PRQ_deq_item-------------------*/
  rmitem = PRQ_deq_item( item_array[5] );
  CDA_ASSERT( rmitem != NULL );
  CDA_ASSERT( rmitem->priority == 5 );
  printf("PRQ_deq_item passed\n");
  
  
  /*-----------PRQ_enq_pri_head-------------------*/
  item = PRQ_enq_pri_head( queue, rmitem );
  CDA_ASSERT( ENQ_is_item_enqed( (ENQ_ITEM_p_t)item ) );
  printf("PRQ_enq_pri_head passed\n");
  
  
  /*-----------PRQ_deq_pri_head-------------------*/
  rmitem = PRQ_deq_pri_head( queue, 5 );
  CDA_ASSERT( ! ENQ_is_item_enqed( (ENQ_ITEM_p_t)rmitem ) );
  CDA_ASSERT( rmitem->priority == 5 );
  printf("PRQ_deq_pri_head passed\n");
  
  
  /*-----------PRQ_GET_DATA-------------------
    
    CDA_ASSERT( 5 == (int)PRQ_GET_DATA(rmitem) );
    
    
    /*-----------PRQ_GET_PRIORITY-------------------
      CDA_ASSERT( 5 == (CDA_UINT32_t)PRQ_GET_PRIORITY( rmitem ) );
      
      /*-----------PRQ_destroy_item-------------------
	PRQ_destroy_item( item );
	CDA_ASSERT( ! ENQ_is_item_enqed( (ENQ_ITEM_p_t)item ) );
	printf("PRQ_destroy_item passed\n");
	-----------------------------------------------*/
  

  /*-----------PRQ_empty_queue-------------------*/
  PRQ_empty_queue( queue, NULL );
  for (inx = 0; inx < 10; ++inx )
    {
      printf("assert died - inx = %d\n", inx);
      CDA_ASSERT( ENQ_is_list_empty( (ENQ_ANCHOR_p_t)queue->anchor_array[inx] ) );
    }
  printf("PRQ_empty_queue passed\n");


  /*-----------PRQ_destroy_queue-------------------*/
  printf("destroying queue %d\n", sizeof(queue));
  PRQ_destroy_queue( queue, NULL );
  printf("destroyed queue %d\n", sizeof(queue));
  CDA_ASSERT( ! queue );
  printf("PRQ_destroy_queue passed\n");

  return 0;
}



void print_list(char * name, ENQ_ANCHOR_p_t anchor)
{
  int inx;
  
  ENQ_ITEM_p_t first, last, next, dqd;


  printf("\nPrinting list results for %s\n",name);
  
     for(inx = 0; inx < 7; inx++)
       {
	 if(inx == 0)
	   {
	     last = ENQ_GET_TAIL(anchor);
	     next = ENQ_GET_PREV(last);
	     printf("last = %s\n", last->name);
	     printf("next = %s\n", next->name);
	   }
	 else if(next->flink != anchor)
	   {
	     next = ENQ_GET_PREV(next);
	     printf("next = %s\n", next->name);
	   }
       }
}
