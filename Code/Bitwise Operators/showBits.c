#include <stdio.h>

typedef int COUNTER;

void showBits(unsigned char ch)
{
	COUNTER i, beauty_space;
	unsigned char andmask, postmask;
	// now starting at the left most bit check which bits are on and then yield the result	
	for(i=8, beauty_space=0; i>=0; --i, ++beauty_space)
	{
		if(!(beauty_space % 4) && (beauty_space != 0))
			printf(" ");
		andmask = 0x01 << i;
		postmask = ch & andmask;
		postmask ? printf("1") : printf("0");
	}
}

int main()
{
	int buf;
	unsigned char n;
	printf("enter a number between 0 and 255: ");
	scanf("%d", &buf);
	if(buf <= 255 && buf >= 0)
		n = buf;
	showBits(n);
	printf("\n");
	return 0;
}
