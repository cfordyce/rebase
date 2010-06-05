#include <stdio.h>

/* 4 function calulator */

/* declare the function prototypes */
int get_numbers(void);
int add(int, int);
int subtract(int, int);
int multiply(int, int);
int division(int, int);


int main(void)
{

char a, b, o, e;    
int digits_a, digits_b, flush, r; 

digits_a = digits_b = flush = r = 0; 


printf("\nFour Function Calculator\n\n");

/* Get the first number */
printf("Enter the first number: ");
digits_a = get_numbers();


/* Get the second number */
printf("\nEnter the second number: ");
digits_b =  get_numbers();



/* Now get the operator */
printf("\nEnter a single character operator (+ - * /): ");

         o = getchar();
         
         while((flush = getchar()) != '\n');
           
           

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
	     





