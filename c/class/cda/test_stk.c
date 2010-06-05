
/***************************

STK Test Driver

***************************/
#include <stdlib.h>
#include <stdio.h>
#include <cdap.h>
#include <enqp.h>
#include <stkp.h>

void print_list(char *, ENQ_ANCHOR_p_t);

int main(void)
{
  
  
/*-----------------------------------

gcc -c -g stk.c test_stk.c cda.c; gcc -o stkk stk.o test_stk.o cda.o

-----------------------------------*/


  char * letter[] = {"a","b","c","d","e","f","g","h"};
  //  char * letter[] = {"aaaaa", "bbbbb", "ccccc", "ddddd", "eeeee", "fffff", "ggggg"};
  int inx, stack_size = 8;

  const STK_ID_t stack = STK_create_stack(stack_size);

  /*  TEST STK_push_item   */
  for(inx = 0; inx < sizeof(letter)/sizeof(char *); inx++)
    {
      STK_push_item(stack, letter[inx]);
      printf("peeked %s\n",(char *)STK_peek_item(stack));
    }
  
  printf("\nPOPS\n\n");
  
  /*  TEST STK_pop_item   */
  for(inx = 0; inx < sizeof(letter)/sizeof(char *); inx++)
    printf("popped %s\n",(char *)STK_pop_item(stack));
  
  
  STK_destroy_stack(stack);
  
}














/*   
     void print_list(char * name, ENQ_ANCHOR_p_t anchor)
     {
     int inx;
     
     ENQ_ITEM_p_t first, last, next, dqd;
     
     
     printf("\nPrinting list results for %s\n",name);
     
     for(inx = 0; inx < 4; inx++)
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
*/
