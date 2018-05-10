#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int inSet(char *set, char ch, int till)
{
	int i;
	for(i=0;i<=till;++i)
	{
		if(ch == set[i])
			return 1;
	}
	return 0;
}

char *getSet(char *str)
{
	int i, j=-1;
	char *set = (char *)malloc(sizeof(char)*(strlen(str) + 1));
	for(i=0; str[i]; ++i)
	{
		if(!(inSet(set, str[i], j+1)))
		{
			++j;
			set[j] = str[i];
		}
	}
	set[j+1] = '\0';
	set = (char *)realloc(set, j+1);
	return set;
}

int main()
{
	char string[100];
	printf("Enter a string: ");
	scanf("%s", string);
	char *set = getSet(string);
	printf("Set: %s\n", set);
	free(set);
	return 0;
}
