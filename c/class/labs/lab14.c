#include <stdio.h>

/* 5 function calulator */

/* declare the function prototypes */
int get_numbers(void);
int add(int, int);
int subtract(int, int);
int multiply(int, int);
int division(int, int);
double exponent(int, int);


int main(void)
{

char a, b, o, e;    
int digits_a, digits_b, flush, r;

digits_a = digits_b = flush = r = 0; 


printf("\nFive Function Calculator\n\n");

/* Get the first number */
printf("Enter the first number (or digit to exponentialize): ");
digits_a = get_numbers();


/* get the operator */
printf("\nEnter a single character operator (+ - * / e): ");
         o = getchar();
         
	 while(flush != '\n') /* flush the buffer */
	   flush = getchar();
	 
	 
/* Get the second number */
printf("\nEnter the second number (or expo notation): ");
 digits_b =  get_numbers();
	 
	 
	 
	 
           

 if (o == '+')
   {
    r = add(digits_a, digits_b);
    printf("Result = %d\n", r);
   }

 if (o == '-')
   {
     r = subtract(digits_a, digits_b);
     printf("Result = %d\n", r);
   }

 if (o == '*')
   {
     r = multiply(digits_a, digits_b);
     printf("Result = %d\n", r);
   }

 if (o == '/')
   {
     r = division(digits_a, digits_b);
     printf("Result = %d\n", r);
   }


 if (o == 'e')
   {
     double r = 0;
     r = exponent(digits_a, digits_b);
     printf("Result = %e\n", r);
   }
 
                   
 return 0;
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


            double exponent(int digits_a, int digits_b)
              {
                 double r = 1;
                 int p;
	
                 if (digits_b == 0)
                   {
		     return r;
		   }
  
		 for (p = 1; p <= digits_b; p++)
		   r *= digits_a;
		 
		 return r;
	      }
