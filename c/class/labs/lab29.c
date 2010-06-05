#include <stdio.h>


/* function prototypes */
void bsort(int *, int);
int dump_array(int *, int);
int swap (int *, int *);



int main(void)
{
  int arr[9] = {'1','9','6','5','7','8','2','4','3'};
  
  int max = (sizeof(arr) / sizeof(int));
  
  bsort(arr, max);
  
  printf("Array Sorted by Bubble Method.\n");
  
  dump_array(arr , max);
  
  return 0;
  
}



void bsort(int * arr, int max)
{
  int v, x;
  
  
  for (v=0; (v < (max-1)) && ((max -1 - v ) != 0); v++)
    {
      
      for (x=0; (x < (max -1 -v)); x++)
	{
	  
	  if (*(arr + x) > *(arr + (x+1)))
	    {
	      swap((arr + x), (arr + (x+1)));
	    }
	}
    }
}



int dump_array(int * arr, int r )
{
  int x = 0;
  
    while(x < r)
    {
      printf("\t%c\n",*(arr + x));
      x++;
    }
  return 0;
  
}


int swap (int *px, int *py)
{
  /* function that swaps the values of the pointer addresses
   * that are passed to it.  The swap takes place only if
   * *px is greater than *py.
   */
  
  int temp;
  
  if (*px > *py)
    {
      temp = *py;
      *py = *px;
      *px = temp;
      return 1;
    }
  return 0;
}



