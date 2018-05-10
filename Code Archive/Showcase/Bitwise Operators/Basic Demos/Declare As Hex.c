#include <stdio.h>
#include "MyBitFunctions.h"

int main()
{
	unsigned char hex_num = 0x48;
	printf("%x : %d : %c : ", hex_num, hex_num, hex_num);
	showBits(hex_num, 1);
	printf("\n");
	return 0;
}
