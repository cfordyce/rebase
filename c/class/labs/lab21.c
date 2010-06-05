#include <stdio.h>
#define FARTOCEL(far) (5.0/9.0) * (far-32)
#define CELTOFAR(cel) ((cel * 9.0) / 5.0) + 32.0

/* fahrenheit / celsius conversion program */

int main(void)
{

int low_limt = 0;
int up_limt = 300;
int step = 20;
float far;
float cel;

/* first, Fahrenheit to Celsius */

printf("Fahrenheit to Celsius Table\n\n");
printf("Fahrenheit     Celsius\n");

far = low_limt;

while (far <= up_limt)
{
        cel = FARTOCEL(far);
        printf("%6.2f%16.2f\n", far, cel);
        far = far + step;
}


/* Now Celsius to Fahrenheit */

printf("\nCelsius to Fahrenheit Table\n\n");
printf("Celsius     Fahrenheit\n"); 

cel = low_limt;

while (cel <= up_limt)
{
        far =  CELTOFAR(cel);
        printf("%6.2f%16.2f\n", cel, far);
        cel = cel + step;
}

return 0;

}
