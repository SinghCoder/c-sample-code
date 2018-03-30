#include <stdio.h>

int main()
{
	int val, term, count=1;
	int a,b,t;
	int range_mode=0;

	// range_mode feature
	printf("would you like to activate range mode?(0/1) ");
	scanf("%d", &range_mode);
	if(range_mode != 0){
		printf("please enter the range (space-seperated): ");
		scanf("%d%d", &a, &b);
		if(a > b){
			t = b;
			b = a;
			a = t;
	}
	}


	// take base input
	printf("Enter a +ve integer to generate the hailstone sequence: ");
	scanf("%d",&val);

	// check to see if the number is positive
	while (val <= 0)
	{
   		printf("Hailstone sequences only for +ve numbers. Please enter a positive number\n");
   		printf("Try again: ");
   		scanf("%d", &val);
	}


	// begin generating the hailstorm sequence
	printf("%d\n", val);
	for (term = val; term != 1; ){
   	 	if (term % 2 == 0)
  	 	   term = term / 2;
  	 	else
  		    term = (3 * term) + 1;
  		 printf("%d\n", term);

 		if(range_mode != 0){
  			if(term<b && term >=a){
				printf("This term falls in the entered range, pre-emptive termination initiated...\n");
				printf("Number of terms = %d\n", count);
				return 0;
  			}
 		}

   		count++;
	};

printf("Number of terms = %d\n",count);
return 0;
}
