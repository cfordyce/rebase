#define MAX 100

#include <stdio.h>

/* decalre functions */
int getline(char str[], int);
void reversit(char str[]);


/* This program gets a string from the user, evaluates its
   length, then prints the string out backward
*/


int main(void)
{

char arr[100];
char c;
int a,b;
a = b = 0;


printf("Enter a string (100 char max): ");
 
a = getline(arr, MAX);

return a;

}



int getline(char str[], int max)
{
  /* This function reads in a line of input from the terminal.
  * It then passes the string to the "reversit" function.
  * After returning from reversit 
  */

    int d = 0;
    char c[MAX];

while (((c[d] = getchar()) != '\n') && (d <= MAX))
  {
    ++d; /* number of chars in the string */
  }

 c[d] = '\0'; 
   
 reversit(c); /* call reversit to print the string backwards */


 if (c[d] == EOF)
   {
     printf("eof found\n");
     return -1;  /* return -1 if/when EOF is encountered */
   }
 
		 
 return d;  /* return number of characters in the string */


}



void reversit(char str[])
  {
    /* This function reverses the string passed to it
    * and prints it out backwards
    */
    
    char tm;
    int u, d, c;
    u = d = c = 0;
    
    while((str[c] != '\0') && (++c));
    
    d = c - 1;
    
    
    for(u; u<=d; u++)
      {
	tm = str[u];
	str[u] = str[d];
	str[d] = tm;
	
	d = d -1;
      }
    
    str[c] = '\0';
    
    /* print the string */
    printf("%s\n", str);
    
  }

