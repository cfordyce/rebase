#include <stdio.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
#define MAX 13
#define LIMIT 20
#define SIZE 50

/*
 * Program to print histograms for multiple strings 
 * using 2 dimensional array.
 */




/* function protos */
void histogram(char *, int *);



void main(void)
{
  char input[LIMIT][SIZE] ;
  int arr[MAX];  
  int *p = arr;
  int x, i;
  x = i = 0;

  
    while((x < LIMIT) && (fgets(input[x],SIZE,stdin)!= '\0') && (input[x][0] != '\n'))
    {
      x++;
    }
  

  for (; i < x; i++)
    {
      printf("\nHistogram. String: %d\n",i);
      fputs(input[i],stdout);
      histogram(input[i], p) ;      
    }
}




void histogram(char *string , int *p)
{
  int test = FALSE;
  char c ;
  int j,t,i,k,r;
  
  j = t = i = r = 0;
  k = 1;
  
    

  for(j=0; j < MAX; j++)
    p[j] = 0;
  
  j = 0 ;
  

  while ((c = string[t++]))
    {
      if (!isspace(c))
	{
	  test = TRUE;
	  j++;
	}
      
      if (isspace(c) && (test == TRUE))
	{
	  p[j]++;
	  test = FALSE;
	  k++;
	  j = 0 ;
	}
    }
  

  for(r=1 ; r < MAX; r++)
    {
      printf(" %d Character Words: ",r);
      
      for (i=0; i < p[r]; i++)
	printf("*");
      
      printf("\n") ;
    }
}






