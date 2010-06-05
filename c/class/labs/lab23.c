#include <stdio.h>

/* Towers of Hanoi lab23 
 * Recursive function calls 
 */



/* funtion prototype */
void move_rings(int n, int a, int b, int c);

void main(void)
{
  int n = 5;
  int pole1, pole2, pole3;
  pole1 = 1;
  pole2 = 2;
  pole3 = 3;
  
  move_rings(n,1,3,2);
}

void move_rings(int n, int pole1, int pole2, int pole3)
{
  /*printf("int n = %d\n",n);*/

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
