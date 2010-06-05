#include <stdio.h>

/* function prototypes */
int swap (int *fst, int *scd);

void main(void)
{
	int r,x,y; 
	r = x = y = 0;


	printf("Enter two integers: ");
	scanf("%d%d", &x, &y);

	r = swap(&x, &y);

	printf("The return value is %d. The values you entered are %d and %d.", r,x,y);
}


int swap (int *px, int *py)
{
	/* function that swaps the values of the pointer addresses
	 * that are passed to it.  The swap takes place only if
	 * *px is greater than *py.
	 */

	int temp;

	if (*px > *py)
	{
		temp = *py;
		*py = *px;
		*px = temp;
		return 1;
	}

	return 0;
}
