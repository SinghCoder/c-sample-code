# include <stdio.h>
int main(){
	float f;
	printf("Sizeof (char) = % d bytes\n", sizeof(char));	// datatypes
	printf("Sizeof (short) = % d bytes\n", sizeof(short));
	printf("Sizeof (int) = % d bytes\n", sizeof(int));
	printf("Sizeof (long) = % d bytes\n", sizeof(long));
	printf("Sizeof (float) = % d bytes\n", sizeof(float));	// variable
	printf("Sizeof (double) = % d bytes\n", sizeof(double));
	printf("Sizeof (1.55) = % d bytes\n", sizeof(1.55));	// constant
	printf("Sizeof (1.55L) = % d bytes\n", sizeof(1.55L));
	printf("Sizeof (str) = % d bytes\n", sizeof("Hello"));	// string
	return 0;
}
