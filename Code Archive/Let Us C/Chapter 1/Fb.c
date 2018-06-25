/* Chapter 1; Problem Set F; Problem 2; */
/* date: Dec 20 2017 */

#include <stdio.h>

int main(){

	float km, m, f, in, cm;

	printf("Please enter the distance in km: ");
	scanf("%f", &km);
	printf("\n");

	m = km*1000;
	f = m*3.28084;
	in = f*12;
	cm = m*100;

	printf("Distance in meters: %f \n", m);
	printf("Distance in feet: %f \n", f);
	printf("Distance in inches %f \n", in);
	printf("Distance in centimeters %f \n", cm);

	return 0;

}
