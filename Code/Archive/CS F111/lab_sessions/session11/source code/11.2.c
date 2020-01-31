#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


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

void standardize(char *str)
{
	int i;
	for(i=0;i<strlen(str);++i)
	{
		if( (str[i] > 64) && (str[i] < 91) )
			str[i] = tolower(str[i]);
	}
}


void removeSpaces(char *str)
{
	int i, j;
	int len = strlen(str);
	for(i=0; i<len; ++i)
	{
		if(str[i] == 32)
		{
			for(j=i; j<(len-1); ++j)
			{
				str[j] = str[j+1];
			}
			str[j] = '\0';
		}
	}
}

void isAngram2(char *string1, char *string2)
{
	char str1[strlen(string1)+1];
	strcpy(str1, string1);

	char str2[strlen(string2)+1];
	strcpy(str2, string2);
	
	standardize(str1);
	standardize(str2);

	stringSort(str1);
	stringSort(str2);

	printf("Your standardized sorted strings:\n");
	printf("	%s\n", str1);
	printf("	%s\n", str2);

	if(strcmp(str1, str2) == 0)
		printf("angram.\n");
	else
		printf("not an angram.\n");
}

void isAngram3(char *string1, char *string2)
{
	char str1[strlen(string1)+1];
	strcpy(str1, string1);

	char str2[strlen(string2)+1];
	strcpy(str2, string2);
	
	removeSpaces(str1);
	removeSpaces(str2);

	isAngram2(str1, str2);
}

int main()
{
	char str1[100], str2[200];
	printf("enter a string: ");
	scanf("%99[^\n]s", str1);
	getchar();
	printf("enter another string: ");
	scanf("%99[^\n]s", str2);
	isAngram2(str1, str2);
	isAngram3(str1, str2);
	return 0;
}
