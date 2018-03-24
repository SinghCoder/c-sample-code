/* date: Dec 21st 2017 */
/* purpose: To create a program to calculate the wind chill factor */

#include <stdio.h>
#include <math.h>

int main() {
	float t, v, wcf;

	printf("please enter the current temperature(F): ");
	scanf("%f", &t);
	printf("\n");

	printf("please enter the current velocity of wind(MPH): ");
	scanf("%f", &v);
	printf("\n");

	wcf = 35.74 + 0.6125*t + (0.4275*t - 35.75)*pow(v, 0.16);

	printf("the wind chill factor is: %f\n", wcf);

	return 0;
}
