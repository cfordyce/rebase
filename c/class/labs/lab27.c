#include <stdio.h>
int getint(char *, int *);
void getline(char *);

/* LAB 27 - Turn a number character string into an integer */




int main(void)
{
  int r, number;
  char str[50];
  number = 0;
  
  
  
  printf("Enter a string of integers: ");
  getline(str);
  
  getint(str, &number);
  
  printf("The string: %s.  Integer form: %d.\n", str, number);
  
  return 0;
  
}


int getint(char *str, int *number)
{
  int i, val, sign;
  i = val = 0;
  
  /* initialiaze the sign to positive */
  sign = +1;

  /* if the first char in the string is a -, make the sign negative and increment the pointer */
  if (*str == '-')
    {
      sign = -1;
      str++; 
    }
    
  /* if the user supplies a + sign, recognize it and increment the pointer */
  else if (*str == '+')
    str++;
    

/* Convert the string into an integer */
  while (*str != '\0')
    {
      if ((*str < '0') || (*str > '9'))
	return 0;
      
      else
	val = (val * 10) + (*str - '0');
      
      str++;
    }
  
  *number = (val * sign);
  return 1;
}



void getline(char *str)
{
  int d = 0; /* number of chars in the string */
  
  while (((*(str + d) = getchar()) != '\n') && (d <= 49))
    d++;
  
  *(str +d) = '\0'; 
}
