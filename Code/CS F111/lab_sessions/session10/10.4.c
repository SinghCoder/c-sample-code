#include <stdio.h>

void printArr(int *array, int len)
{
	register int i;
	for(i=0; i<len; ++i)
	{
		printf("%d ", array[i]);
	}
	putchar('\n');
}

void fill(int *array, int len)
{
	register int i;
	for(i=0; i<len;++i)
	{
		printf("enter a number for position %d: ", i);
		scanf("%d", array+i);
	}
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void insertionSort(int *array, int len)
{
	register int i,j,c;
	for(i=1; i<len; ++i)
	{
		c = i;
		for(j=i-1; j>=0; --j)
		{
			if(array[c]<array[j])
				swap(&array[c], &array[j]);
				c = j;
		}
	}
}

int main()
{
	int len;

	printf("how many numbers: ");
	scanf("%d", &len);

	int array[len];

	fill(array, len);

	printf("your array pre-sorting: ");
	printArr(array, len);

	insertionSort(array, len);

	printf("your array post-sorting: ");
	printArr(array, len);

	return 0;
}
