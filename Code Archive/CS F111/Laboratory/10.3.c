#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *raw_input()
{
	char ch;
	int counter=0;
	char buffer[1000];
	while(ch!='\n' && counter<998)
	{
		ch = getchar();
		if(ch!='\n')
		{
			buffer[counter] = ch;
			++counter;
		}
		else
		{
			++counter;
			buffer[counter] = '\0';	
			break;
		}
	}
	char *str = (char *)malloc(sizeof(char)*counter);
	strcpy(str, buffer);
	return str;
}

int main()
{
	printf("Enter a string: ");
	char *str1 = raw_input();
	char *str2 = raw_input();
	// create the sort function and the angram function
	return 0;
}
