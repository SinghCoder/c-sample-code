typedef int COUNTER;

void showBits(unsigned char ch, int add_space)
{
	if(add_space)
	{
		COUNTER i, beauty_space;
		unsigned char andmask, postmask;
		// now starting at the left most bit check which bits are on and then yield the result	
		for(i=7, beauty_space=0; i>=0; --i, ++beauty_space)
		{
			if(beauty_space == 4)
				printf(" ");
			andmask = 0x01 << i;
			postmask = ch & andmask;
			postmask ? printf("1") : printf("0");
		}
	}

	else
	{
		COUNTER i;
		unsigned char andmask, postmask;
		// now starting at the left most bit check which bits are on and then yield the result	
		for(i=7; i>=0; --i)
		{
			andmask = 0x01 << i;
			postmask = ch & andmask;
			postmask ? printf("1") : printf("0");
		}
	}
	return;
}
