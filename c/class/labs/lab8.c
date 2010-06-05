#include <stdio.h>
int main(void)
{

int arr[20] = {0};

int a, i, w, r, t;
i = w = r = t = 0;

printf("\nCharacter-per-word Counter\n");
printf("Enter a string: ");

/* enter a while loop to count the chars between whitespace chars */

while((a = getchar()) != EOF)
  {

   if ((a != '\t') && (a != ' ') && (a != '\n'))
     {
       ++w;      /* add up chars (not whitespace) */
       continue;
       
     }
   
    if (w >= 20)  /* if w is 20 or more, put w into arr[20] */
     { 
       arr[20] = arr[20] + 1;   
       w = 0;
       continue;
       
     }
    
    arr[w] = arr[w] + 1;  /* else put the count into its arr value */
    w = 0;
    continue;
    
  }

/* now print the histogram! */

for(r = 1; r <= 20; ++r)
  {
    t = arr[r];
    printf("%d Character Words: ",r);


for(i = 1; i <= t; ++i)
    {
      printf("*");
    }
  printf("\n");
      
}

return 0;

}



