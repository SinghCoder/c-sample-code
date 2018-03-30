#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void clearStdin()
{
	fseek(stdin,0,SEEK_END);
}

char *raw_input()
{
	char ch= '\0';
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
			buffer[counter] = '\0';	
			break;
		}
	}
	clearStdin();
	char *str = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
	strcpy(str, buffer);
	return str;
}

int main()
{
	printf("Enter a string: ");	
	char *str1;
	str1 = raw_input();
	
	printf("Your string:\n");
	printf("	%s\n", str1);

	free(str1);

	return 0;
}
