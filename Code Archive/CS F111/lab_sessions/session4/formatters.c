#include <stdio.h>

int main(){
	int x1=12;
	float x2=234.5678;
	char y = 'Y';

	printf("%5d\n", x1);
	printf("%-5d\n", x1);

	printf("%-8.2f\n", x2);
	printf("%+8.2f\n", x2);
	printf("%+-8.2f\n", x2);

	printf("%c\n", y);

return 0;
}
