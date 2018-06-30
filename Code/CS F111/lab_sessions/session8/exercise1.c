#include<stdio.h>
#include<string.h>

void printall(char *arr, int max){
	int i;
	for(i=0;i<max;++i){
		if(arr[i] == '\0'){
			printf("\\0");
		}
		printf("%c ", arr[i]);
	}
	printf("\n");
}

void resetarray(char *arr, int max){
	int i;
	for(i=0;i<max;++i){
		arr[i] = '\0';
	}
}

void spacelessprint(char *arr){
	int i;
	for(i=0;i<strlen(arr);++i){
		if(arr[i] == '\0')
			break;
		else if(arr[i] != ' '){
			printf("%c", arr[i]);
		}
	}
	printf("\n");
}

void recieveInput(char *arr){
	printf("enter something: ");
	scanf("%99[^\n]", arr);
	printf("\n");
	getchar();
}

int main(){
	int i,n;
	char arr[100];
	printf("How many times would you like to do this: ");
	scanf("%d", &n);
	getchar();
	while(n>10 || n<0){
		printf("Out of bounds\nEnter again: ");
		scanf("%d", &n);
	}
	fflush(stdin);
	for(i=0; i<n; ++i){
		recieveInput(arr);
		spacelessprint(arr);
		resetarray(arr, 100);
	}
	return 0;
}
