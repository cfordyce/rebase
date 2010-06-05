/***************************

SRT Test Driver

***************************/
#include <stdlib.h>
#include <stdio.h>
#include <cdap.h>
#include <enqp.h>
#include <stkp.h>
#include <srtp.h> 

//static SRT_CMP_PROC_p_t int_comp;
//static SRT_CMP_PROC_p_t double_comp;

static int int_cmp(const void * p1, const void * p2);
static int dbl_cmp(const void * p1, const void * p2);

static int pints_cmp(const void * p1, const void * p2);
static int str_cmp(const void * p1, const void * p2);

int main(void)
{
  
  /*-----------------------------------
    
    gcc -c -g srt.c test_srt.c cda.c stk.c; gcc -o srtt srt.o stk.o test_srt.o cda.o
    
    -----------------------------------*/
  
  int inx, num_elem = 5;
  // int ints[] = {5,4,3,1,2};
  int ints[] = {45,25,20,10,5,15,30,40,35,50,80,65,85,55,60,75,70};  /* 5 to 85 */
  int * pints[] = { &ints[0], &ints[1], &ints[2], &ints[3], &ints[4], &ints[5], &ints[6], &ints[7], &ints[8], &ints[9], 
		    &ints[10], &ints[11], &ints[12], &ints[13], &ints[14], &ints[15], &ints[16] };
  

/*  int * pints[] = { &ints[0], &ints[1], &ints[2], &ints[3], &ints[4] };*/
  

  double dbls[] = {25.1,20.2,10.3,5.4,15.5,30.6,40.7,35.8,50.9,80.11,65.12,85.13,55.14,60.15,75.16,70.17,45.18};
  
//  char ** name[] = { 'f', 'b', 'a', 'c', 'e', 'd' };
  
  
  SRT_poly_mergesort( (void **)pints, 17, pints_cmp );
  for( inx = 0; inx < 17; ++inx)
    printf("pints[%d] = %d\n", inx, *pints[inx] );
  
  

  /*
    SRT_poly_mergesort( (void**)pints, CDA_CARD(name), pints_cmp );
    for( inx = 0; inx < 5; ++inx)
    printf("[%d] = %s\n", inx, &name[inx] );
    
  */
  /********* */
  SRT_mergesort( ints, sizeof(ints)/sizeof(int), sizeof(int), int_cmp );
  for(inx = 0; inx < sizeof(ints)/sizeof(int); inx++)
    printf("ints[%d] = %d\n", inx, ints[inx]);
     
  /* ******/
  /******* 
	   for(inx = 0; inx < sizeof(dbls)/sizeof(double); inx++)
	   printf("dbls[%d] = %f\n", inx, dbls[inx]);
	   
	   SRT_mergesort( dbls, sizeof(dbls)/sizeof(double), sizeof(double), dbl_cmp );
	   printf("Dbls\n");
	   for(inx = 0; inx < sizeof(dbls)/sizeof(double); inx++)
	   printf("dbls[%d] = %f\n", inx, dbls[inx]);
  ******/

}



static int pints_cmp(const void * p1, const void * p2)
{
  const int * a = p1;
  const int * b = p2;
  
  //printf("a = %d   b = %d   return = %d\n", *a, *b, *a < *b ? -1 : 1 );
  
  return *a < *b ? -1 : 1;
  
}



static int int_cmp(const void * p1, const void * p2)
{
  const int * a = p1;
  const int * b = p2;
  
   //printf("a = %d   b = %d   return = %d\n", *a, *b, *a < *b ? -1 : 1 );

  return *a < *b ? -1 : 1;

}

static int dbl_cmp(const void * p1, const void * p2)
{
  const double * a = p1;
  const double * b = p2;
  
  return *a < *b ? -1 : 1;
  
}

static int str_cmp(const void * p1, const void * p2)
{
  /*char * a,b;
  int j = 0;  
  (char *)a = p1;
  (char *)b = p2;
  
 j = strcmp(a, b);
  
  printf("&a = %s  &b = %s  j = %d\n", (char*)p1, (char*)p2, j );
  */
  return 0;
  
}
