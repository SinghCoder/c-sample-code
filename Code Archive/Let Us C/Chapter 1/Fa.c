/* Chapter 1; Problem Set F; Problem a; */
/* date: Dec 20th, 2017 */

#include <stdio.h>

int main(){
	float sal, gross_sal;

	/* input */
	printf("Enter your salary Ramesh: \n");
	scanf("%f", &sal);

	/* calculations */
	gross_sal = sal + (0.4*sal) - (0.2*sal);
	/* could be simplified to gross_sal = 1.2*sal */

	/* output */
	printf("Here is your gross salary Ramesh: %f \n", gross_sal);

	return 0; 
}
