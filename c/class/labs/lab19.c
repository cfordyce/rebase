#include <stdio.h>

#define MAX 100
#define MASK 32

/*
 * This program compares two strings by dictionary sort order.
 *
 * a '1' is returned if string 1 is has a higher value than string 2.
 *
 * a '-1' is returned if string 2 has a higher value than string 1.
 *
 * a '0' is returned if the strings are the exact same.
 */


/* Function Prototypes */
int getline(int str[]);
int strcomp(int a, int s1[], int b, int s2[]);

/* Get 2 character strings and compare them. */
int main(void)
{
  int s1[MAX];
  int s2[MAX];

  int a,b;
  a = b = 0;
  
  printf("\nEnter string 1: ");
  a = getline(s1);
 
  printf("\nEnter string 2: ");
  b = getline(s2);
  
  strcomp(a, s1, b, s2);
  
  return 0;
}




int strcomp(int a, int s1[], int b, int s2[])
{
  /*
   * This function compares the dec notation of
   * 2 strings and returns a result based on the 
   * dictionary sort order of the strings.
   */
  
  int n, i, j, k, result;
  i = j = k = result = 0;
  

  /* assign n to the number of characters in the longest string */
  n = (a > b) ? a : b;
  

  /* make all letters in the string 1 uppercase */
  for(i; i<=a; i++)
    {
      if(s1[i] <= 96) /* if s1[i] is already an uppercase letter, meta-characters included */ 
	continue;  
      
      if(s1[i] > 122) /* if s1[i] is { or | or  } or ~ (meta-characters) */
 	continue;
      
      else  /* use bit mask of 32 to turn off bit 5 in (binary) lowercase letters */
      s1[i] &=  ~MASK;




    }
  
  
  /* make all letters in the string 2 uppercase */
  for(j; j<=b; j++)
    {
      if(s2[j] <= 96) /* if s2[j] is already an uppercase letter, meta-characters included */ 
	continue;  
      
      if(s2[j] > 122) /* if s2[j] is { or | or  } or ~ (meta-characters)  */
 	continue;
      
      else  /* use bit mask of 32 to turn off bit 5 in (binary) lowercase letters */
	s2[j] &=  ~MASK;
    }




/* Now loop through the strings and find the one that comes later in dictionary order */

  for(k; k <= n; k++)
    {
      if (k == n) /* if we reach the end of the strings and they're equal, Result = 0. */
	{
	  printf("\nResult = 0\n");
	  return 0;
	}
      
      if(s1[k] == s2[k]) /* If the characters are the same, skip them */
	continue;
      
      if(s1[k] > s2[k]) /* If we come across a character in string 1 that comes later in the alphabet, Result = 1 */
	{
	  printf("\nResult = 1\n");
	  return 0;
	}
      
      if(s2[k] > s1[k]) /* If we come across a character in string 2 that comes later in the alphabet, Result = -1 */
	{
	  printf("\nResult = -1\n");
	  return 0;
	}
    }
}




int getline(int str[])
{
  /* This function reads in a line of input from the terminal.
   * and returns it, and the number of chars in the line.
   */
  
  int d = 0;
  char c;
  
  while (((c = getchar()) != '\n') && (d < MAX-1))
    {
      c = c -'0';
      str[d] = c;
      d++;
    }
  
  str[d] = '\0'; /* add the null char to make this a string */
  
  while (c != '\n')
    {
      c=getchar();
    }
  return d;
}
