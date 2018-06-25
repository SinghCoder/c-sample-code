/* Obtaining the prime factors of a number recursively */

#include <stdio.h>
void prime_decomposition(int, int *);

int main(){
	int inp,i;
	
	printf("Enter a Number: ");
	scanf("%d", &inp);

	printf("prime decomposition: \n");
	for (i=1; i++<inp;){
	/* starts at 2 and increment is done before comparision as per precedence of operators. */
		if (inp != 1)
			prime_decomposition(i, &inp);
		else
			break;	
	}

	return 0;
}

void prime_decomposition(int i, int *inp){
	int c=0;
	while (*inp%i == 0){
		*inp = *inp/i;
		c++;
	}
	if (c!=0)
		printf("    %d^%d\n",i,c);
}
