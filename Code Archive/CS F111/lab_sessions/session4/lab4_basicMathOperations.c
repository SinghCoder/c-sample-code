#include <stdio.h>

int main(){
	float a, b;
	printf("Please enter two numbers (spaace seperated): ");
	scanf("%f%f", &a, &b);
	printf("Sum: %f\nDifference: %f\nProduct: %f\nQuotient: %f\n", a+b, a-b, a*b, a/b);
return 0;
}
