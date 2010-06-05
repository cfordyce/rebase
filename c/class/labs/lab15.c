#define MAX 100
#include <stdio.h>

/* prototypes */
void squeeze2(char s1[], int a, char s2[], int b);
int getline(char str[]);


/* This program gets a line from the user.
* It then asks for a list of chars to remove from that line.
* It then removes those chars and prints the string 
*/




int main(void)
{
  
  char s1[MAX];
  char s2[MAX];
  int a, b,d;
  a = b = 0;
  
  
  printf("\nEnter a string (100 char max): ");
  
  a = getline(s1);
  
  
  /* get the chars to remove */
  printf("\nEnter the characters to remove: ");
  
  b = getline(s2);
  squeeze2(s1,a, s2, b);
  
  
  return 0;
}


void squeeze2(char s1[], int a, char s2[], int b)
{
  
  /* d is for b */
  /* c is for a */
  int c,d,f;
  c= d = f = 0;
  
  
  for(d; d<=b && s2[d] != '\0'; ++d)  /* remove loop */
    {
      for(c = 0; c<=a; c++) /* s1 loop */ 
      {
	  if(s1[c] == s2[d])  /* if chars match */
	    {
	      s1[c] = s1[c+1]; /* copy right to left */
	      
	      for(f=c+1;f<=a;f++) /* f is eqaul to the string position */
		{
		  s1[f] = s1[f+1]; 
		  s1[a] = '\0';
		}
	    }
	}
    }
  
  printf("\nResult:%s\n", s1);  /* print the result */
  
}




int getline(char str[])
{
  /* This function reads in a line of input from the terminal.
   * and returns it, and the number of chars in the line.
   */
  
  int d = 0;
  char c;
  
  while (((c = getchar()) != EOF) && (c != '\n') && (d < MAX-1))
    {
      str[d] = c;
      d++;
    }
  
  str[d] = '\0'; /* add the null to make this a string */
  
  if (c == EOF)
    return -1;
  
  while (c != '\n')
    {
      c=getchar();
    }
  return d;
}
