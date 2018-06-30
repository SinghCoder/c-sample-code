#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int arr[255];

void runCount(char *str, int len)
{
	register int i;
	int max;
	char max_char;
	for(i=0;i<len;++i)
	{
		arr[str[i]] += 1;
		if (arr[str[i]] > max)
		{
			max_char = str[i];
			max = arr[str[i]];
		}
	}
	printf("%c with %d.\n", max_char, max);
}

int main()
{
	char string[100];
	printf("enter a string: ");
	scanf("%[^\n]s", string);
	runCount(string, strlen(string));
	return 0;
}
