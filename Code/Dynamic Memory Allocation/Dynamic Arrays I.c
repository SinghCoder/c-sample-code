#include <stdio.h>
#include <stdlib.h>


void fill(int *array, int start_position, int end_position)
{
	int i;
	for(i=start_position; i<end_position; ++i)
	{
		printf("Enter a number: ");
		scanf("%d", array + i);
	}
}


void print(int *array, int length)
{
	int i;
	for(i=0; i<length; ++i)	
	{
		printf("%d ", array[i]);
	}
	printf("\n");	
}


int main()
{
	int *array = (int *)malloc(sizeof(int)*10);
	putchar('\n');
	printf("Intitialization of an array done via malloc.\narray size == 10.\n");
	putchar('\n');

	printf("Let's fill up the array with integers.\n");
	fill(array, 0, 10);
	putchar('\n');
	printf("Here's the array you just filled:\n");
	print(array, 10);
	putchar('\n');

	array = realloc(array, sizeof(int)*20);
	printf("Now the array has been expanded via realloc.\narray size == 20.\n");
	putchar('\n');
	
	printf("Let's fill up this new expanded memory with more integers.\n");
	fill(array, 10, 20);
	putchar('\n');
	printf("Here's the array now:\n");
	print(array, 20);
	putchar('\n');

	free(array);

	return 0;
}
