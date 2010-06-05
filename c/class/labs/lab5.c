
#include <stdio.h>

/* 4 function calulator */

int main(void)
{

char a, b, o, e;    
int digits_a, digits_b, flush, r; 

digits_a = digits_b = flush = r = 0; 


printf("\nFour Function Calculator\n\n");

/* Get the first number */
printf("Enter the first number: ");

	while((a = getchar()) != '\n')
	{
	a = a - '0'; /* a is an integer now */
	
	digits_a = digits_a * 10 + a;   /* accumulate first integers */
	}




	/* Now get the operator */
printf("\nEnter a single character operator (+ - * /): ");

	 o = getchar();
	 
	 while((flush = getchar()) != '\n')
	   {
	     flush = flush;
	   }
	   
	   
	  
	 /* get the second number */

printf("\nEnter the second number: ");

        while((b = getchar()) != '\n')
        {
        b = b - '0';

        digits_b = digits_b  * 10 +  b;
        }




	/* 
	 *    Operation Loop
	 */
	
	while(digits_b != 0)
	  {

	    if (o == '+')
	      {
		r = digits_a + digits_b;
		printf("\nResult = %d\n", r);
	      }
	    
	    if (o == '-')
	      {
		r = digits_a - digits_b;
		printf("\nResult = %d\n", r);
	      }
	    
	    if (o == '*')
	      {
		r = digits_a * digits_b;
		printf("\nResult = %d\n", r);
	      }
	    
	    if (o == '/')
	      {
		r = digits_a / digits_b;
		printf("\nResult = %d\n", r);
	      }
	    break;
	  }



	if (digits_b == 0 && o == '/')
         {
	    printf("\n**Illegal division by zero attempted.\n");
	    printf("**Please try again.\n");
	    
	  }
	

	return 0;
}






