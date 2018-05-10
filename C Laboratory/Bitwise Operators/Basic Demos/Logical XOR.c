/* Logical XOR */

#include <stdio.h>
#include "MyBitFunctions.h"

int main()
{
	char space = ' '; 
	unsigned char hex_num = 0x48, xor_with = 0x50, result;
	
	printf("%s %20c", "original binary : ", space);
	showBits(hex_num, 1);
	printf("\n");
	
	printf("%s %19c", "Logical xor with : ", space);
	showBits(xor_with, 1);
	printf("\n");

	result = hex_num ^ xor_with;

	printf("%s %29c", "Result : ", space);
	showBits(result, 1);
	printf("\n");

	return 0;
}
