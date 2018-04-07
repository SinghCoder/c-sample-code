#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ideally these would go in a seperate header file or something...
typedef struct {
	int code;
	char *message;
} ERROR;

ERROR err_001 = {001, "You must enter an integer value!\n"};


void print(char *str){
	int i;
	for(i=0;i<strlen(str);++i){
			printf("%c", str[i]);	
		}
		printf("\n");
}


int integer(char *arr){
	int i, x, status;
	ERROR *err_001p;
	status = sscanf(arr ,"%d", &x);
	if(status==0){
		printf("%s\n", err_001.message);
		printf("%s\n", err_001p->message);
		exit(1);	// self-raised runtime error
	}
	else
		return x;
}


int main()
{
	int a=10, a1, i, x;
	char b='b', b1;
	float c=3.14, c1;
	char str[50];

	sprintf(str,"%d-%c-%f",a,b,c);
	print(str);
	sscanf(str, "%d-%c-%f",&a1,&b1,&c1);

	printf("a1: %d\n", a1);

	for(i=0; i<3; ++i){
		printf("convert a string to an integer: ");
		scanf("%s", str);
		printf("%d\n", integer(str));
	}

	return 0;
}

