#include <stdio.h>
#include "/usr/include/math.h"

/* 5 function calulator LAB 24 - USING FLOATS */

/* declare the function prototypes */
float get_operand(void);
char get_operator(void);
float add(float, float);
float subtract(float, float);
float multiply(float, float);
float division(float, float);
double exponent(float, float);


/* Main Program */


int main(void)
{
  
  char a, o;    
  int flush, r;
  float digits_a, digits_b;
  
  flush = r = 0; 
  digits_a = digits_b = 0;
 
do
  {
    digits_a = get_operand();
    
    o = get_operator();
    while (o != 'c')
      {

	
	digits_b = get_operand();
	
	
	switch(o)
	  {
	    
	  case '+':
	    r = add(digits_a, digits_b);
	    break;
	    
	    
	  case '-':
	    r = subtract(digits_a, digits_b);
	    
	    
	  case '*':
	    r = multiply(digits_a, digits_b);
	    break;
	    
	    
	  case '/':
	    r = division(digits_a, digits_b);
	    break;
	    	    
	    
	  case 'e':
	    r = exponent(digits_a, digits_b);
	    break;
	    
	    
	  default:
	    printf("\nINVALID OPERATOR\n");
	    break;
	    
	  } /* end of SWITCH */
	
	printf("\n\nResult = %d\n",r);
	
	digits_a = r;
	o = get_operator();
	
      } /* while o != clear */
    
    printf("\nEnter  n  to quit, or\n");
    printf("enter  y  to do another operation: ");
    
    a = getchar();
    
    if (a == 'y')
      {
	while (flush != '\n')
	  {
	    flush = getchar();
	  }
      }
  }while (a == 'y');

return 0;
}




float get_operand(void)
{
  float number = 0.0;
  int r = 0;
  char eol, c;
  
  while (r != 2)
    {
      printf("\nPlease enter one floating point value: ");
      r = scanf("%f%c",&number,&eol);
      
      if (r != 2)
	{
	  while(c != '\n')
	    {
	      c = getchar();
	    }
	  
	  r = 0;
	  c = '\0';
	}
    }
  
  return number;
}



char get_operator(void)
{
    /* This function gets the operator from the user.
     */
  
  char o;
  char eol;
  int r = 0;
  
  do
    {
      printf("\nEnter a single character operator (+ - * / e c): ");
      r = scanf("%c%c",&o,&eol);
    } while((r != 2) && (eol !='\n'));
  
  return o;
}



float add(float digits_a, float digits_b)
{
  float r;
  r = digits_a + digits_b;
  return r;
}



float subtract(float digits_a, float digits_b)
{
  float r;
  r = digits_a - digits_b;
  return r;
}



float multiply(float digits_a, float digits_b)
{
  float r;
  r = digits_a * digits_b;
  return r;
}




float division(float digits_a, float digits_b)
{
  float r;
  
  if (digits_b == 0)
    {
      printf("\n**Illegal division by zero attempted.\n");
      printf("**Please try again.\n");
      return 0;
    }
  
  r = digits_a / digits_b;
  
  return r;
}



double exponent(float digits_a, float digits_b)
{
  double r = 1.0;
  
  if (digits_b == 0)
    {
      return r;
    }
  
  r = pow(digits_a, digits_b);
  
  return r;
}


