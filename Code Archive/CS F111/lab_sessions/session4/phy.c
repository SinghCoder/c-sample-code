#include <stdio.h>

int main(){
	float u, a, t;

	printf("enter u, a, and t (in respective order, space/tab seperated): ");
	scanf("%f%f%f", &u, &a, &t);

	printf("the distance travelled is: %f\n", (u*t + 0.5*a*t*t));
return 0;
}
