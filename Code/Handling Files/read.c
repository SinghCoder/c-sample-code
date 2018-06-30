#include <stdio.h>
#include <stdlib.h>

int main()
{
	char ch;
	FILE *file = fopen("poem1.txt", "r");	// an example of a file pointer.
	if(file == NULL)
		{
			printf("no poem :(\n");
			exit(1);
		}	
		while(1)
		{
			ch = fgetc(file);
			if(ch == EOF)
				break;
			else
				printf("%c", ch);
		}
		putchar('\n');
	fclose(file);	
	return 0;
}
