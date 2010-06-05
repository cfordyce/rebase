
#include <stdio.h>

# pifndef GOLD
#  	define GOLD
#endif

/* fahrenheit / celsius conversion program */


int main(void)
{

int low_limt;
int up_limt;
int step;

float far;
float cel;

low_limt = 0;
up_limt = 300;
step = 20;

/* first, Fahrenheit to Celsius */

#if defined GOLD

printf("DEFINED Fahrenheit to Celsius Table\n\n");

#endif

printf("Fahrenheit     Celsius\n");
far = low_limt;

while (far <= up_limt)
{
	cel = (5.0/9.0) * (far-32);
	printf("%6.2f%16.2f\n", far, cel);
	far = far + step;
}


/* Now Celsius to Fahrenheit */

printf("\nCelsius to Fahrenheit Table\n\n");
printf("Celsius     Fahrenheit\n"); 

cel = low_limt;

while (cel <= up_limt)
{
	far = ((cel * 9.0) / 5.0) + 32.0;
	printf("%6.2f%16.2f\n", cel, far);
	cel = cel + step;
}

return 0;

}
