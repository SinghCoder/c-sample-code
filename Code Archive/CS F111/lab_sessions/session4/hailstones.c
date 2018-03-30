#include <stdio.h>

int main(){
	int x, i;
	int *p;
	p = &x;
	printf("Enter a +ve integer to generate the hailstone sequence: ");
	scanf("%d", &x);

	printf("%d\n", x);

	do{
		if(*p%2 == 0){
			*p /= 2;
			printf("%d\n", *p);
			i++;
		}
		else{
			*p *= 3;
			*p += 1;
			printf("%d\n", *p);
			i++;
		}
	} while(*p != 1);

printf("Number of terms: %d\n", i);
return 0;
}
