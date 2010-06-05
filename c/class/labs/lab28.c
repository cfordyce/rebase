#include <stdio.h>

#define MAX 100


/*
 * LAB 28.  Fill array and dump_array 
 *
 */




/* function prototypes */
int fill_array(int*, int);
int dump_array(int*, int);

int arr[MAX];

int main(void)
{
  int r = 0;
  
  r = fill_array(arr, MAX);
  
  dump_array(arr, r);
  
  return 0;
}



int fill_array(int * arr, int z)
{
  int r = 0;
  
  printf("\nEnter a 100 digit integer, EOF to stop: ");
  
  while((r < z) && 1 == (scanf("%c", arr++)))
     r++;
     
  return r;
}




int dump_array(int * arr, int r )
{
  int x = 0;
  
  printf("\n");
  
  while(x < r)
    {
      printf("%c\n",*(arr + x));
      x++;
    }
  return 0;
  
}






