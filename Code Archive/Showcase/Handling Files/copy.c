#include <stdio.h>
#include <stdlib.h>

void copy(FILE *source, FILE *target)
{
	printf("begining to make a copy.\n");
	char ch;
	while(ch != EOF)
	{
		ch=getc(source);
		fputc(ch, target);
	}
	printf("done.\n");
}

int main()
{
	FILE *source, *target;
	source = fopen("poem1.txt", "r");
	if(source == NULL)
	{
		printf("source file does not exist :(\n");
		return 1;		
	}
	target = fopen("copy.txt", "w+");
	if(target == NULL)	
	{
		printf("target file could not be created :(\n");
		fclose(source);
		return 1;		
	}
	copy(source, target);
	fclose(source);
	fclose(target);
	return 0;
}
