#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *raw_input()		// THIS FUNCTION IS BUGGY!!! PLEASE DON'T USE IT ANYWHERE!!!
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
	char *str = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
	strcpy(str, buffer);
	fseek(stdin, 0, SEEK_END);
	return str;
}


int findMindex(char *str, int start, int end)
{
	int i=start + 1;
	int min_index=start;
	int min=str[start];
	for(i;i<end;++i)
	{
		if(str[i] < min)
		{
			min = str[i];
			min_index = i;
		}
	}
	return min_index;
}


void stringSort(char *str)
{
	int i;
	char temp;
	int mindex;
	int len = strlen(str);
	for(i=0; i<len; ++i)
	{
		mindex = findMindex(str, i, len);
		if(mindex != i)
		{
			temp = str[i];
			str[i] = str[mindex];
			str[mindex] = temp; 
		}
	}
}


int main()
{
	printf("Enter a string: ");	
	char *str1;
	str1 = raw_input();

	printf("Enter another string: ");
	char *str2;	
	str2 = raw_input();
	
	printf("Your strings:\n");
	printf("	%s\n", str1);
	printf("	%s\n", str2);	

	stringSort(str1);
	stringSort(str2);

	printf("Your sorted strings:\n");
	printf("	%s\n", str1);
	printf("	%s\n", str2);

	if(strcmp(str1, str2) == 0)
		printf("angram.\n");
	else
		printf("not an angram.\n");

	free(str1);
	free(str2);
	return 0;
}
