#include <stdio.h>
#include "MyBitFunctionsInt.h"

int main()
{
	COUNTER i;
	char space = ' '; 
	int hex_num, result;

	printf("Enter the number: ");
	scanf("%d", &hex_num);

	printf("Original Binary: %20c", space);
	showBits(hex_num, 1);
	printf("  %X", hex_num);
	printf("\n\n");

	for(i=0; i<7; ++i)
	{
		result = hex_num << i;
		printf("left shift by %d: %20c", i, space);
		showBits(result, 0);
		printf("   %X", result);
		printf("\n");
	}
	printf("\n\n");
	
	for(i=0; i<7; ++i)
	{
		result = hex_num >> i;
		printf("Right shift by %d: %19c", i, space);
		showBits(result, 0);
		printf("   %X", result);
		printf("\n");
	}
	printf("\n");

	return 0;
}
