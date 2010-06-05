
#include <stdio.h>
#include <limits.h>
#include <float.h>

#define ulong ULONG_MAX
#define float_min FLT_MIN
#define float_max FLT_MAX

#define dbl_min DBL_MIN
#define dbl_max DBL_MAX

#define ldbl_min LDBL_MIN
#define ldbl_max LDBL_MAX

#define int_min INT_MIN
#define int_max INT_MAX

#define shrt_min SHRT_MIN
#define shrt_max SHRT_MAX

#define long_min LONG_MIN
#define long_max LONG_MAX

/*
* This program will tell me what my system limits are;
* min/max for each type of number defined in C.
*
*
* My OS is UNIX.  My complier is CXX.
*
*/


int main(void)
{

/*Reassign constants to new variables that can be altered. */

int intg_min = int_min;
int intg_max = int_max;

short int shrt_int_min = shrt_min;
short int shrt_int_max = shrt_max;

long int long_int_min = long_min;
long int long_int_max = long_max;

float flt_min =  float_min;
float flt_max = float_max;

double dubl_min =  dbl_min;
double dubl_max = dbl_max;

long double ldubl_min = ldbl_min;
long double ldubl_max = ldbl_max;



/* make min / max calculations */

intg_min = intg_min - 1;
intg_max = intg_max + 1;

shrt_int_min = shrt_int_min - 1;
shrt_int_max = shrt_int_max + 1;

long_int_min = long_int_min - 1; 
long_int_max = long_int_max + 1;

flt_min = flt_min - 1;
flt_max = flt_max + 1;

dubl_min = dubl_min - 1;
ldubl_max = ldubl_max + 1;

ldubl_min = ldubl_min - 1;
ldubl_max = ldubl_max + 1;

printf("unlong = %u\n\n", ulong);

/* Now use printf to show the values */

printf("Data Type     Size                      Min                        Max                      Min-1                      Max+1\n");

printf("int             %d                %12d                %12d               %12d               %12d\n", sizeof(int_min), int_min, int_max, intg_min, intg_max);

printf("short           %d                %12d                %12d               %12d               %12d\n", sizeof(shrt_min), shrt_min, shrt_max, shrt_int_min, shrt_int_max);

printf("long            %d        %12ld         %12ld        %12ld       %12ld\n", sizeof(long_min), long_min, long_max, long_int_min, long_int_max);

printf("float           %d                %12e                %12e               %12.0f               %12e\n", sizeof(float_min), float_min, float_max, flt_min, flt_max);

printf("double          %d               %12e               %12e               %12.0f              %12e\n", sizeof(dbl_min), dbl_min, dbl_max, dubl_min, dubl_max);
  
printf("long double     %d               %12e               %12e               %12.0f              %12e\n", sizeof(ldbl_min), ldbl_min, ldbl_max, ldubl_min, ldbl_max);



return 0;

}
