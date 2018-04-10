#include <stdio.h>

int main(int argc, char **argv)
{
	int i;
	printf("No. of command line arguments entered: %d\n\n", argc);
	for(i=0;i<argc;++i)
		printf("argv[%d]: %s\n", i, argv[i]);
	printf("\n");
	return 0;
}
