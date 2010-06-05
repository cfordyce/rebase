#include <stdio.h>

int main(void)
{
  
char arr[100];

char tm; /* dynamic variable */

int u,d,c;

u = c = d = 0;

printf("Enter a string (100 char max): ");

while (((arr[c] = getchar()) != '\n' ) && (c <=100))
  {
	++c;
      }

arr[c] = '\0';
	     
        /* set d one less than the last element '\0' */ 
	     d = c - 1;
	     
	     for(u; u<=d; u++)
	       {
		     tm = arr[u];
		 arr[u] = arr[d];
		 arr[d] = tm;
		 
		 d = d -1;
	       }
		
		
/* print the string */
printf("%s\n", arr);


return 0;

}
