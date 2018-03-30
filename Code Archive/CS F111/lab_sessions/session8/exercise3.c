#include <stdio.h>

int my_strlen1(char *arr){
	int i;
	for(i=0;i<99;++i){
		if(arr[i]!='\0')
			continue;
		else
			break;
	}
	return i;
}

int main(){
	int len;
	char arr[99];

	printf("enter something: ");
	scanf("%99[^\n]", arr);
	len = my_strlen1(arr);
	printf("%d\n", len);
	return 0;
}
