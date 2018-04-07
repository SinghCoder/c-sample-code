#include <stdio.h>

typedef union {
	int d;
	float f;
} REAL_NO;

union OVERWRRT {
	char ch;
	int integer;
};

int main()
{
	// demo 1 - but components are of the same size
	REAL_NO num;
	printf("the size of this structure is: %lu\nThis is the bigger of the components of the REAL_NO union data type.\n", sizeof(num));
	num.d = 10;
	printf("%d\n", num.d);
	num.f = 3.14;
	printf("%f\n", num.f);
	printf("%d\n", num.d);
	printf("Because of the IEEE way of storing floating type numbers.\n");

	putchar('\n');

	union OVERWRRT ow;
	ow.ch = 'A';
	printf("one: %c\n", ow.ch);

	ow.integer = 1080;
	printf("two: %d\n", ow.integer);

	printf("before overwritting: 0x%.4x\n", ow.integer);
	ow.ch = 'H';
	printf("three: %c\n", ow.ch);
	printf("hex of H: 0x%0.4x\n", 'H');
	printf("after overwritting: 0x%.4x\n", ow.integer);
	printf("five: %d\n", ow.integer);

	putchar('\n');

	printf("Why it happens this way: Unix based systems follow \"Little Endian\" formats for storing values in memory.\n");
	printf("what this means is that the LSB will get stored in the lowest memory address (usually shown as leftmost end),\n"); 
	printf("and MSB in the highest memory address (ususally shown as rightmost end).\n");
	printf("and the MSB is overwritten first (I suppose always?).\n");
	return 0;
}

