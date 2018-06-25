/* 
Using an array of pointers to store other arrays (of different types).
An array of arrays.
Not a conventional multidimensional array.
Nested Arrays.
*/


#include <stdio.h>

# define CASE 1

int main()
{
	int x[3] = {10, 20, 30}, y[3] = {'a', 'b', 'c'};
	int *z[2];
	register int i;

	z[0] = &x;
	z[1] = &y;

	/* the idea: z = {
						{10,20,30},
						{1, 2, 3}
					} 
	*/

	printf("z[0]:\n");
	for(i=0; i<=2; ++i)
	{
		printf("%d\n", *(z[0] + i));
	}

	printf("\n");

	printf("z[1]:\n");
	for(i=0; i<=2; ++i)
	{
		printf("%c\n", *(z[1] + i));
	}

return 0;
}
