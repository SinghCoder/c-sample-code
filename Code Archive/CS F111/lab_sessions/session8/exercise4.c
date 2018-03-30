#include <stdio.h>
#include <ctype.h>
#include <string.h>

void convertLower(char *string);

int main(){
	char arr[99];

	printf("Enter some text: ");
	scanf("%99[^\n]", arr);

	convertLower(arr);

	printf("%s\n", arr);

	return 0;
}

void convertLower(char *string){
	register int i;
	for(i=0;i<strlen(string);++i){
		string[i] = (char)tolower(string[i]);
	}
}
