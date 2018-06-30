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

int findMindex(int *arr, int start, int end)
{
	int i=start + 1;
	int min_index=start;
	int min=arr[start];
	for(i;i<end;++i)
	{
		if(arr[i] < min)
		{
			min = arr[i];
			min_index = i;
		}
	}
	return min_index;
}

void selectionSort(int *array, int len)
{
	int mindex;
	register int i;
	for(i=0;i<len;++i)
	{
		mindex = findMindex(array, i, len);
		swap(&array[i], &array[mindex]);
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

	selectionSort(array, len);

	printf("your array post-sorting: ");
	printArr(array, len);

	return 0;
}
