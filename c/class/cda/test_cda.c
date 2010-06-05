/***************************

CDA Test Driver

__cda.h macros__:
CDA_ASSERT(exp) (assert(exp))
CDA_CARD(arr) (sizeof(arr)/sizeof(*arr))
CDA_NEW(type) ((type *)CDA_malloc(sizeof(type)))
CDA_NEW_STR(str) (strcpy(char *)CDA_malloc(strlen(str) + 1, str))
CDA_NEW_STR_IF(str) (str == NULL ? NULL: CDA_NEW_STR(str))

 __cda.c functions__:
CDA_malloc
CDA_realloc
CDA_calloc
CDA_free


***************************/
#include <stdlib.h>
#include <assert.h>
#include "cdap.h"

int main(void)
{
  
  int tin = 0,
    arr[] = {10,20,30,40,50},
    *inew = NULL, *inew_2 = NULL;

    
  char * new = NULL,
    * new_2 = NULL,
    * fail = NULL,
    * name = "Charles";
    

  double * dbl = NULL;

  inew = CDA_calloc(10,sizeof(int));
  tin = CDA_CARD(inew);
  CDA_ASSERT(inew[9] == 0);

  
  inew_2 = CDA_realloc(inew, 100*sizeof(int));
  tin = CDA_CARD(inew_2);
  CDA_ASSERT(inew_2 != NULL);

  inew_2[99] = 55;

  CDA_ASSERT(inew_2[99] == 55);


  
  /* CDA_ASSERT */
  CDA_ASSERT(tin > 0);
  

  /* CDA_CARD */
  tin = CDA_CARD(arr);
  CDA_ASSERT(tin == 5);
  
  /* CDA_NEW  */
  dbl = CDA_NEW(double);
  CDA_ASSERT(dbl != NULL);
  CDA_free(dbl);
  
  /* CDA_NEW_STR  */
  new = CDA_NEW_STR(name);
  printf("\nnew = %s\n",new);

  /* CDA_NEW_STR_IF */
  new_2 = CDA_NEW_STR_IF(new);
  CDA_ASSERT(new_2);
  printf("\nnew_2 = %s\n",new_2);

  CDA_free(new);
  CDA_ASSERT(new);

  CDA_free(new_2);
  CDA_ASSERT(new_2);
  
  
  return 0;
  
}

