#include <stdio.h>

int main()
{
	char another = 'Y';

	struct person{
		char name[100];
		int age;
	} p;

	FILE *pseudodb = fopen("people.dat", "a+");

	if(pseudodb == NULL)
	{
		printf("cannot open the people.dat file.\n");
		return 1;
	}

	while(another == 'Y')
	{
		printf("Enter the first name and age of the person: ");
		scanf("%s %d", p.name, &p.age);
		getchar();	// get rid of the remaining \n
		fprintf(pseudodb, "%s %d\n", p.name, p.age);
		printf("enter another?(Y/N)");	
		scanf("%c", &another);
		getchar();
	}	

	fclose(pseudodb);
	return 0;
}
