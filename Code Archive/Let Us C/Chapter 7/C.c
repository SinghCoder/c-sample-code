#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int c,x,y,i,half_value;
	int EARLY_BREAK=0;
	while(c!=4){
		printf("\nEnter:\n	1: factorial program\n	2: Prime determination\n	3: Odd/Even\n	4. Exit\nOption: ");
		scanf("%d",&c);
		switch(c){
			case 1:
				fflush(stdin);
				printf("enter a number: ");
				scanf("%d",&x);
				for(y=1;x>1;){
					y *= x*(x-1);
					x -= 2;				
				}
				printf("it's factorial is: %d\n",y);
				break;
			case 2:
				fflush(stdin);
				printf("enter a number: ");
				scanf("%d", &x);
				if (x%2==0 && x!=2){
					printf("not a prime number\n");
					break;
				}
				half_value = ceil(sqrt(x));
				for (i=3;i<half_value;i+=2){
					if (x%i == 0){
						printf("not a prime number\n");
						EARLY_BREAK = 1;						
						break;
					}
				}
				if (EARLY_BREAK != 1)
					printf("prime number\n");
				break;
			case 3:
				fflush(stdin);
				printf("enter a number: ");
				scanf("%d", &x);
				if (x%2==0)
					printf("even number\n");
				else
					printf("odd number\n");
				break;
			default:
				if (c!= 4)
					printf("		number not recognised\n");
				break;			
		}
    }
printf("bye!\n");
return 0;
}
