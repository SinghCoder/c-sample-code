#include <stdio.h>
#include <stdlib.h>

void read1(){
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
}

void read2(){
	char ch;
	FILE *file = fopen("poem2.txt", "r");	// an example of a file pointer.
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
}

int choosePoem()
{
	int p;
	printf("Which poem do you want? Choose 1 or 2: ");
	int x = scanf("%d", &p);
	if(x!=0 && (p==1||p==2))
		return p;
	else
	{
		printf("Invalid.\n");
		exit(1);
	}
}

int main()
{
	void (*read[2])() = {read1, read2}; // an example of a function pointer, and how it can be used to replace switch statements
	read[choosePoem()]();	
	return 0;
}
