/* Note: the standard library functions: atoi and atof could just as easily handle the string conversion demonstrated here, */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ideally these would go in a seperate header file or something...
struct error{
	int code;
	char *message;
};

struct error err_001 = {001, "You must enter an integer value!\n"};



void print(char *str){
	int i;
	for(i=0;i<strlen(str);++i){
			printf("%c", str[i]);	
		}
		printf("\n");
}


int integer(char *arr){
	int i, x, status;
	status = sscanf(arr ,"%d", &x);
	if(status==0){
		printf("%s",err_001.message);
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
		printf("%d\n", integer(str));		// integer() is equivalent to atoi() from stdlib.h
	}

	return 0;
}

