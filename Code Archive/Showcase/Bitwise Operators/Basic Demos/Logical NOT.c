/* Logical NOT or One's Compliment */

#include <stdio.h>
#include "MyBitFunctions.h"

int main()
{
	char space = ' '; 
	unsigned char hex_num = 0x48;
	
	printf("%s %20c", "original binary : ", space);
	showBits(hex_num, 1);
	printf("\n");
	
	printf("%s %5c", "Logical NOT (One's Compliment) : ", space);
	showBits(~hex_num, 1);
	printf("\n");

	return 0;
}
