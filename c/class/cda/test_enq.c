
/***************************

ENQ Test Driver

***************************/
#include <stdlib.h>
#include <assert.h>
#include <cdap.h>
#include <enqp.h>
void print_list(char *, ENQ_ANCHOR_p_t);

int main(void)
{

  typedef struct person_s
  {
    ENQ_ITEM_t item;
    int ssn;
    char * let;
  }PERSON_t, *PERSON_p_t;
  
  int ssnl[] = {10,20,30,40,50};
  int inx, aa, bb;
  
  char * letter[] = {"a","b","c","d","e"};
  char  * who;
  
  char * list_name = "TEST_LIST_NAME";
  
  CDA_BOOL_t retval;
  
  ENQ_ITEM_p_t first, last, next, dqd;

  ENQ_ITEM_p_t self = (ENQ_ITEM_p_t)CDA_calloc(5, sizeof(ENQ_ITEM_t));

  const ENQ_ANCHOR_p_t anchor = ENQ_create_list(list_name);
  
  printf("\n");
  
  /*  TEST ENQ_deq_head   */
  for(inx = 0; inx < 5; inx++)
    {
      self = (PERSON_p_t)ENQ_create_item(letter[inx], sizeof(PERSON_t));
      
      ENQ_add_head(anchor, self);
      CDA_ASSERT(ENQ_is_item_enqed(self));
      
      printf("Processing: %s\n",self->name);
      
      /*
      last = (PERSON_p_t)ENQ_GET_TAIL(anchor);
      first = (PERSON_p_t)ENQ_GET_HEAD(anchor);
      printf("ENQ_GET_TAIL = %s\n",ENQ_GET_ITEM_NAME(last));
      printf("ENQ_GET_HEAD = %s\n",ENQ_GET_ITEM_NAME(first));
      */
    }
  who = "ENQ_add_head";
  print_list(who,anchor);
  ENQ_empty_list(anchor);


  for(inx = 0; inx < 5; inx++)
    {
      self = (PERSON_p_t)ENQ_create_item(letter[inx], sizeof(PERSON_t));
      ENQ_add_head(anchor, self);
    }

  dqd = ENQ_deq_tail(anchor);
  CDA_ASSERT(!ENQ_is_item_enqed(dqd));
  ENQ_destroy_item(dqd); 
  who = "ENQ_deq_tail";
  print_list(who,anchor);


  dqd = ENQ_deq_tail(anchor);
  CDA_ASSERT(!ENQ_is_item_enqed(dqd));
  ENQ_destroy_item(dqd); 
  who = "ENQ_deq_tail (second)";
  print_list(who,anchor);
  ENQ_empty_list(anchor);


/*
  last = (PERSON_p_t)ENQ_GET_TAIL(anchor);
  first = (PERSON_p_t)ENQ_GET_HEAD(anchor);
  printf("\nDQ: ENQ_GET_TAIL = %s\n",ENQ_GET_ITEM_NAME(last));
  printf("DQ: ENQ_GET_HEAD = %s\n",ENQ_GET_ITEM_NAME(first));
*/


/*  TEST ENQ_add_before  */
  for(inx = 0; inx < 5; inx++)
    {
      self = (PERSON_p_t)ENQ_create_item(letter[inx], sizeof(PERSON_t));
      
      if(inx == 0)
	ENQ_add_tail(anchor, self);	
      else
	{
	  last = ENQ_GET_TAIL(anchor);
	  ENQ_add_before(self,ENQ_GET_PREV(last));
	}
      CDA_ASSERT(ENQ_is_item_enqed(self));
      
      printf("Processing: %s\n",self->name);

      /*
      last = (PERSON_p_t)ENQ_GET_TAIL(anchor);
      first = (PERSON_p_t)ENQ_GET_HEAD(anchor);
      printf("ENQ_GET_TAIL = %s\n",ENQ_GET_ITEM_NAME(last));
      printf("ENQ_GET_HEAD = %s\n",ENQ_GET_ITEM_NAME(first));
      */
    }
  who = "ENQ_add_before";
  print_list(who,anchor);
  ENQ_empty_list(anchor);

  /*  TEST ENQ_add_after  */
  for(inx = 0; inx < 5; inx++)
    {
      self = (PERSON_p_t)ENQ_create_item(letter[inx], sizeof(PERSON_t));
      
      if(inx == 0)
	ENQ_add_head(anchor, self);	
      else
	{
	  last = ENQ_GET_HEAD(anchor);
	  ENQ_add_after(self,ENQ_GET_PREV(last));
	}
      CDA_ASSERT(ENQ_is_item_enqed(self));
      printf("Processing: %s\n",self->name);
      /*
      last = (PERSON_p_t)ENQ_GET_TAIL(anchor);
      first = (PERSON_p_t)ENQ_GET_HEAD(anchor);
      printf("ENQ_GET_TAIL = %s\n",ENQ_GET_ITEM_NAME(last));
      printf("ENQ_GET_HEAD = %s\n",ENQ_GET_ITEM_NAME(first));
      */
    }
  who = "ENQ_add_after";
  print_list(who,anchor);
  ENQ_empty_list(anchor);



    /*  TEST ENQ_add_tail  */
   for(inx = 0; inx < 5; inx++)
    {
      self = (PERSON_p_t)ENQ_create_item(letter[inx], sizeof(PERSON_t));
      
      ENQ_add_tail(anchor, self);	
      
      CDA_ASSERT(ENQ_is_item_enqed(self));
      printf("Processing: %s\n",self->name);

      /*
      last = (PERSON_p_t)ENQ_GET_TAIL(anchor);
      first = (PERSON_p_t)ENQ_GET_HEAD(anchor);
      printf("add_tail: ENQ_GET_TAIL = %s\n",ENQ_GET_ITEM_NAME(last));
      printf("add_tail: ENQ_GET_HEAD = %s\n",ENQ_GET_ITEM_NAME(first));
    */
    }
   who = "TEST ENQ_add_tail";
   print_list(who,anchor);
   ENQ_empty_list(anchor);

    
  /*  TEST ENQ_add_head  */
  for(inx = 0; inx < 5; inx++)
    {
      self = (PERSON_p_t)ENQ_create_item(letter[inx], sizeof(PERSON_t));
      
      ENQ_add_head(anchor, self);	
      
      CDA_ASSERT(ENQ_is_item_enqed(self));
      printf("Processing: %s\n",self->name);

      /*printf("add_head: ENQ_ADD_HEAD = %s\n",ENQ_GET_ITEM_NAME(self)); */
      
      *(self++);
    }
   who = "TEST ENQ_add_tail";
   print_list(who,anchor);
   ENQ_empty_list(anchor);

  ENQ_destroy_list(anchor);

  return 0;
}


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

