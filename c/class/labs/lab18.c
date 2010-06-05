#include <stdio.h>

/* 5 function calulator */

/* declare the function prototypes */

int get_first_operand(void);
char get_operator(void);
int get_next_operand(void);
void use_switch(char o, int digits_a, int digits_b);
void ask_do_another(void);
void do_consecutive(int previous_digits);
void print_result(int r);
void print_ex_result(int r);
int get_numbers(void);
int do_another(void);
int add(int, int);
int subtract(int, int);
int multiply(int, int);
int division(int, int);
int exponent(int, int);


/* Main Program */


void main(void)
{
  
  char a, b, o, e;    
  int digits_a, digits_b, flush, r;
  
  digits_a = digits_b = flush = r = 0; 
  
  digits_a = get_first_operand();
  
  o = get_operator();
  
  if (o == 'c')
    {
      ask_do_another();
      return;
    }      
  
  digits_b = get_next_operand();
  
  use_switch(o, digits_a, digits_b);
  
}



int get_first_operand(void)
{
  /* Gets the first set of digits to be used in the computation.
     the digits are accumulated by the get_numbers() function
     and returned to main
  */
  
  int digits_a = 0;
  
  printf("Enter the first number (or digit to exponentialize): ");
  digits_a = get_numbers();
  
return digits_a;
}




char get_operator(void)
{
  /* This function gets the operator from the user.
     This function is called from main() and do_consecutive()
    
     */
  
  char o;
  char flush;
  
  printf("\nEnter a single character operator (+ - * / e c): ");
  o = getchar();
  
  while(flush != '\n') /* flush the buffer */
    flush = getchar();
  
  return o;
}




int get_next_operand(void)
{
  int digits_b;
  
  printf("\nEnter the second number (or expo notation): ");
  digits_b =  get_numbers();
  
  return digits_b;
}



void use_switch(char o, int digits_a, int digits_b)
{
  int r;
  
  switch(o)
    {
      
    case '+':
      r = add(digits_a, digits_b);
      print_result(r);
      break;
      
      
    case '-':
      r = subtract(digits_a, digits_b);
      print_result(r);
      break;
      
      
    case '*':
      r = multiply(digits_a, digits_b);
      print_result(r);
      break;
      
      
    case '/':
      r = division(digits_a, digits_b);
      print_result(r);
      break;
      
      
      
    case 'e':
      r = exponent(digits_a, digits_b);
      print_ex_result(r);
      break;
      
      
    case 'c':
      ask_do_another();
      break;

      
    default:
      printf("\nINVALID OPERATOR\n");
      break;
      
    }

}


void ask_do_another(void)
{
  /* If the user selects the operator "c" (clear) he is brought here 
     and asked if he would like to start a new calculation
     
     If he does want to perform a new calc, he is taken back to 
     main() where variables are reinitialized to 0.

*/

  char a;
  char flush;
  
  printf("\nEnter  n  to quit, or\n");
  printf("enter  y  to do another operation: ");
  
  a = getchar();
  
  if (a == 'y')
    {
      while (flush != '\n')
	{
	  flush = getchar();
	}
      main();
    }
  
  return;
}


void do_consecutive(int previous_digits)
{
  /* This function handles looping on continuous computations.
     a "continuous computation" is one where the user uses the result
     of a previous computation as the first operand in the next
     consecutive computation.
     
     */


  char o;
  int digits_a, digits_b;
  digits_a = previous_digits;
  digits_b = 0;
  
  o = get_operator();
  
  if (o == 'c')
    {
      ask_do_another();
      return;
    } 
  
  digits_b = get_next_operand();
  
  use_switch(o, digits_a, digits_b);
}



void print_result(int r)
{
  /* This function prints the result in normal integer values */
  printf("Result = %d\n", r);
  do_consecutive(r);
}


void print_ex_result(int r)
{
  /* This function prints the result in exponent notation */

  printf("Result = %e\n", r);
  do_consecutive(r);
}





int get_numbers(void)
{
     char a;
     int numbers = 0;
     
     while((a = getchar()) != '\n')
       {
         a = a - '0'; /* a is an integer now */
         
         numbers = numbers * 10 + a;   /* accumulate first integers */
       }
     
     
     while (a != '\n')
       a = getchar();
     
     return numbers;
}






int add(int digits_a, int digits_b)
{
  int r;
  r = digits_a + digits_b;
  return r;
}



int subtract(int digits_a, int digits_b)
{
  int r;
  r = digits_a - digits_b;
  return r;
}



int multiply(int digits_a, int digits_b)
{
  int r;
  r = digits_a * digits_b;
  return r;
}




int division(int digits_a, int digits_b)
{
  int r;
  
  if (digits_b == 0)
    {
      printf("\n**Illegal division by zero attempted.\n");
      printf("**Please try again.\n");
      return 0;
    }
  
  r = digits_a / digits_b;

  return r;
}



int exponent(int digits_a, int digits_b)
{
  int r = 1;
  int p;
  
  if (digits_b == 0)
    {
      return r;
    }
  
  for (p = 1; p <= digits_b; p++)
    r *= digits_a;
  
  return r;
}

