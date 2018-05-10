/* Logical AND */

#include <stdio.h>
#include "MyBitFunctions.h"

int main()
{
	char space = ' '; 
	unsigned char hex_num = 0x48, and_with = 0x50, result;
	
	printf("%s %20c", "original binary : ", space);
	showBits(hex_num, 1);
	printf("\n");
	
	printf("%s %19c", "Logical and with : ", space);
	showBits(and_with, 1);
	printf("\n");

	result = hex_num & and_with;

	printf("%s %29c", "Result : ", space);
	showBits(result, 1);
	printf("\n");

	return 0;
}
