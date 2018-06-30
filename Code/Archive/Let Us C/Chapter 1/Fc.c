/* Chapter 1; Problem Set F; Problem c; */
/* date: Dec 20 2017 */

#include <stdio.h>

int main() {

	float a,b,c,d,e,total,av;

	printf("please enter your grades either space-seperated, tab-seperated or newline-seperated: ");
	scanf("%f%f%f%f%f",&a,&b,&c,&d,&e);
	printf("\n");

	total = a + b + c + d + e;
	av = total/5;

	printf("total: %f\naverage: %f\n",total,av);

	return 0;

}
