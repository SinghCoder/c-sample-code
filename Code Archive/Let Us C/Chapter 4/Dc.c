#include <stdio.h>

int main()
{
	float H,CC,TS;	
	
	printf("Enter the hardness: ");
	scanf("%f",&H);

	printf("Enter the carbon content: ");
	scanf("%f",&CC);

	printf("Enter the tensile strength: ");
	scanf("%f",&TS);

	H>50?H=1:(H=0);
	CC<0.7?(CC==0?CC=1:(CC=1)):(CC=0);
	TS>5000?TS=1:(TS=0);

	if (H && CC && TS)
		printf("Grade 10\n");

	else if (H && CC && !TS)
		printf("Grade 9\n");

	else if (!H && CC && TS)
		printf("Grade 8\n");

	else if (H && !CC && TS)
		printf("Grade 7\n");

	else if (H || CC || TS)
		/* using sequence control to my advantage here */
		printf("Grade 6\n");

	else
		printf("Grade 5\n");

	return 0; 
		
}
