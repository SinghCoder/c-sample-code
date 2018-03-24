/* Write a program to calculate the sum of digits of a 5 digit number recursively. */

#include <stdio.h>
void dsum(int, int *);
int main(){
	int inp,a,b,out=0;
	
	printf("Enter a 5 (or less) digit number: ");
	scanf("%d", &inp);

	dsum(inp, &out);

	printf("the sum of it's digits: %d\n",out);
return 0;
}

void dsum(int inp, int *out){
	if (inp>99999){
		printf("The number is too big.\n");
	}
	
	else if (inp<=99999 && inp>=10000){
		*out += inp/10000;
		dsum(inp%10000, out);		
	}
	
	else if (inp<=9999 && inp>=1000){
		*out += inp/1000;
		dsum(inp%1000, out);		
	}

	else if (inp<=999 && inp>=100){
		*out += inp/100;
		dsum(inp%100, out);		
	}

	else if (inp<=99 && inp>=10){
		*out += inp/10;
		dsum(inp%10, out);		
	}

	else if (inp<=9 && inp>=1){
		*out += inp;	
	}

	else
		printf("How'd we get here?");
}
