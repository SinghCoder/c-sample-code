/* date: Dec 20th 2017 */

#include <stdio.h>

int main(){

	float f,c;

	printf("Enter the temperature in farenheit: ");
	scanf("%f", &f);
	printf("\n");

	c = (f - 32) * 9 / 5;

	printf("the temperature in centigrade is: %f\n", c);

	return 0;

}
