#include <stdio.h>

/* Towers of Hanoi lab 30  -- Command Line Args  
 * Recursive function calls 
 */



/* funtion prototype */
void move_rings(int n, int a, int b, int c);

void main(int argc, char * argv[])
{
  int pole1, pole2, pole3, n;
  pole1 = 1;
  pole2 = 2;
  pole3 = 3;
  
 
  if ((argc < 2) || (argc > 2))
    {
      printf("\nPlease use 1 argument (the number of rings.)\n");
      return;
    }
  
  
  n =  atoi(*(argv + 1));
  
  
  if (n < 2)
    {
      printf("Please use a number greater than 2.\n");
      return;
    }
  
  
  if (n > 10)
    {
      printf("Please use a number less than 10.\n");
      return;
    }
  
    
  move_rings(n,1,3,2);
}



void move_rings(int n, int pole1, int pole2, int pole3)
{
  if (n==1)
  printf("move a ring from tower %d to tower %d\n",pole1,pole2);
 
 else
   {
     move_rings(n-1, pole1,pole3,pole2);

     printf("move a ring from tower %d to tower %d\n",pole1,pole2);

     move_rings(n-1, pole3,pole2,pole1);
  }
 return; 
}
