#include <stdio.h>

/* program to print a character in different formats:
*  Normal, Decimal, Octal, Hex
*/

int main(void)
{ 

int a;
float b;

printf("Enter a character: "); 

while(a = getchar())
{
	b = a;

	printf("\nCharacter: %c\tDecimal: %.0f\tOctal: %o\tHex: %x\n\n",a,b,a,a);

	 printf("Enter a character: "); 

	a = getchar();
}
return 0;

}
