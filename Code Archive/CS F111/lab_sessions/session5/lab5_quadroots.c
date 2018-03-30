#include <stdio.h>
#include <string.h>
#include <math.h>

char type[10];

int main(){

	printf("are you going to enter **float** or **int** values?: ");
	scanf("%s", type);

	if (!strcmp(type, "float")){
	// if float mode
		int a, b, c;
		float d, x1, x2;

		printf("please enter the values for a, b and c (space seperated): ");
		scanf("%d%d%d", &a, &b, &c);

		d = b*b - (4*a*c);

		if(d < 0){
			printf("complex roots obtained\n");
			return 0;
		}
		else{
			x1 = (-b + sqrt(d))/(2*a);
			x2 = (-b + sqrt(d))/(2*a);
		};

		printf("the roots are:\n    x1=%f\n    x2=%f\n", x1, x2);
	}
	else if (!strcmp(type, "int")){
	// if int mode
		float a, b, c;
		float d, x1, x2;

		printf("please enter the values for a, b and c (space seperated): ");
		scanf("%f%f%f", &a, &b, &c);

		d = b*b - (4*a*c);

		if(d < 0){
			printf("complex roots obtained\n");
			return 0;
		}
		else{
			x1 = (-b + sqrt(d))/(2*a);
			x2 = (-b + sqrt(d))/(2*a);
		};
		
		printf("the roots are:\n    x1=%f\n    x2=%f\n", x1, x2);
	}
	else{
		printf("not recognized\n");
		return 1;
	}
return 0;
}
