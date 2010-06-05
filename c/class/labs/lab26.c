#define MAX 100

#include <stdio.h>

/* function prototypes */
int getline(char *str);
void reversit(char *str);

/* POINTER VERSION -- LAB 26 */


/* This program gets a string from the user, evaluates its
 * length, then prints the string out backward.
 */

int main(void)
{
  int a = 0;
  char arr[MAX];
  char*str = arr;
 
  
  printf("Enter a string (100 char max): ");
  
  a = getline(str);
  
  return a;
  
}



int getline(char *str)
{
  /* This function reads in a line of input from the terminal.
   * It then passes the string to the "reversit" function.
  * After returning from reversit 
  */
  
  int d = 0;
    
    while (((*(str + d) = getchar()) != '\n') && (d <= MAX))
      {
	++d; /* number of chars in the string */
      }
    
    *(str +d) = '\0'; 
    

    reversit(str); /* call reversit to print the string backwards */

    
    
    if (*(str +d) == EOF)
      {
	printf("eof found\n");
	return -1;  /* return -1 if/when EOF is encountered */
      }
    
    
    return d;  /* return number of characters in the string */
}





void reversit(char *str)
{
  /* This function reverses the string passed to it
   * and prints it out backwards
   */
  
  char tm;
  int u, d, c;
  u = d = c = 0;
  
  while((*(str + c) != '\0') && (++c));
  
  d = c - 1;
  
  
  for(u; u<=d; u++)
    {
      tm = *(str + u);
      *(str + u) = *(str + d);
      *(str + d) = tm;
      
      d--;
    }
  
  *(str + c) = '\0';
    

  /* print the string */
  printf("%s\n", str);
  
}






