#include <stdio.h>

#define TRUNCATE 0

int main()
{
	float a, b, prod;
	printf("Enter value of a: ");
	scanf("%f", &a);
	printf("Enter value of b: ");
	scanf("%f", &b);
	prod = a * b;
#if TRUNCATE == 0
	printf("Product of %f and %f is: %f\n", a,b,prod);
#elif TRUNCATE == 1
	printf("Product of %0.2f and %0.2f is %0.2f \n", a,b,prod);
#else
	printf("invalid mode.");
#endif
return 0;
}
