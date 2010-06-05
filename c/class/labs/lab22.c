#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define ulong ULONG_MAX


/* function prototypes */
void reversit(char s1[]);
int is_it_palindrome(char s1[], char s2[]);
int add_strings(char s1[], char s2[]);
void getline(char str[]);

/*
*  This program asks for a numbner and tries converting it to a Palindrome.
*  It stops when a palindrome ins found and asks if the user wants to 
*  do it again.
*/

int main(void)
{
  int ans = 0;
  char s1[100];
  char s2[100];

  do
    {
      printf("Enter a starting integer (no larger than 4294967295): ");
      getline(s1);
      printf("Is %s a Palindrome?", s1);
  
      while((ans != 1) && (ans != 2))
        {
          strcpy(s2, s1);
          
          reversit(s1);
          
          ans = is_it_palindrome(s1,s2);
	  if ((ans == 1) || (ans == 2))
            continue;
          
          printf("  No it's not.\n");
          
          printf("Flipped the number is %s\n", s1);
          
          ans = add_strings(s1, s2);
          
          printf("Well, how about %s?", s1);
        }

      if (ans == 1)
	ans = 0;
      
    
    } while(ans != 2);
  
  return 0;
}



int is_it_palindrome(char s1[], char s2[])
{
  /* This function uses strcmp to see if the 2 strings are equal. 
   * If they are its a Palindrome and I tell the user and break out of the loop.
   * If not, we send the strings off to be added together, and retry the operation
   */
  
  char again;
  char flush;
  
  if(strcmp(s1,s2) == 0)
    {
      printf("\n\n%s is a Palindrome!\n", s1);
      
      printf("\nAgain? y or n: ");
      
      again = getchar();
      
      while(flush != '\n') /* flush the buffer */
	flush = getchar();
      
      if((again == 'y') || (again == 'Y'))
	return 1;
      
      if ((again == 'n') || (again == 'N'))
	return 2;
    }
  
return 0;
    
}


void reversit(char s1[])
  {
    /* This function reverses the string passed to it
    * and prints it out backwards
    */
    
    char tm;
    int u, d, c;
    u = d = c = 0;
    
    while((s1[c] != '\0') && (++c));
    
    d = c - 1;
        
    for(u; u<=d; u++)
      {
        tm = s1[u];
        s1[u] = s1[d];
        s1[d] = tm;
	
        d = d -1;
      }
    
    s1[c] = '\0';
    
  }



int add_strings(char s1[], char s2[])
{
  /* This function turns the strings into long ints and adds them together.
   * It then tests the product of that addition to see if we've over shot 
   * ulong.  If so we let the user know, and ask if they want to do another.
   */

  unsigned long int c = 0;
  unsigned long int d = 0;
  unsigned long int product = 0;
  double testproduct = 0;
  
  c = atol(s1);
  d = atol(s2);

  product = c + d;
  
  testproduct = product;

  if (testproduct > ulong)
    {
      printf("\nThe number has grown too large for the operation.\n");
      return 1;
    }
  
  sprintf(s1,"%u",product); 
  
  printf("Well, how about %s?", s1);
  return 0;
}


void getline(char str[])
{
  /* This function reads in a line of input from the terminal.
   * and returns it, and the number of chars in the line.
   */
  
  int d = 0;
  char c;
  
  while (((c = getchar()) != EOF) && (c != '\n') && (d < 100-1))
    {
      str[d] = c;
      d++;
    }
  
  str[d] = '\0'; /* add the null to make this a string */
  
   while (c != '\n')
    {
      c=getchar();
    }
}



