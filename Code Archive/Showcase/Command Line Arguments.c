#include <stdio.h>

int main(int argc, char **argv)		// note you don't HAVE to call them argc and argv but it's convention.
{
	int i;
	printf("No. of command line arguments entered: %d\n\n", argc);
	for(i=0;i<argc;++i)
		printf("argv[%d]: %s\n", i, argv[i]);
	printf("\n");
	return 0;
}
