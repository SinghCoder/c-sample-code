/* Logical NOT or One's Compliment */

/* Since we are dealing with signed integers, the binary representations of the numbers are their two's compliment form. For positive numbers this is the same as their regular representations. But for negative integers, which are indicated by starting with an ON or 1 bit, we will need to convert back from two's compliment form (either by applying another two's compliment to the existing representation or by undoing the two's compliment of the existing representation) to find the magnitude of this negative number */

#include <stdio.h>
#include "MyBitFunctions.h"

int main()
{
	char space = ' '; 
	int hex_num, result;
	
	printf("enter: ");
	scanf("%d", &hex_num);

	printf("%s %20c", "original binary : ", space);
	showBits(hex_num, 1);
	printf("\n");
	
	result = ~hex_num;

	printf("%s %5c", "Logical NOT (One's Compliment) : ", space);
	showBits(result, 1);
	printf("\n");

	printf("result: %d\n", result);

	return 0;
}
