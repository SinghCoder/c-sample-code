#include<stdio.h>

void disp(int *n);

int main()
{
	register int i;
	int marks[] = {12,43,46,78,56,56,65};
	for(i=0;i<=6;i++)
	{
		printf("a = %d \n&a = %d\n*&a = %d\n",marks[i], &marks[i],*&marks[i]);
		disp(&marks[i]);
		printf("\n");
	}
return 0;
}

void disp(int *n)
{
	printf("n = %d\n&n = %d\n*&n= %d\n ",n,&n,*&n);
}

