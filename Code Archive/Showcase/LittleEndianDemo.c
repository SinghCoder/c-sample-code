/* to be run on Little Endian type architectues such as a Unix-based OS*/

#include <stdio.h>

typedef union
{
	int a;
	char b;
} EX;

int main()
{
	EX e;
	printf("int: ");
	scanf("%d", &e.a);
	printf("0x%.8x\n\n", e.a);

	getchar();

	printf("char: ");
	scanf("%c", &e.b);
	printf("0x%.8x\n\n", e.a);
	printf("0x%.8x\n\n", e.b);

	return 0;
}
