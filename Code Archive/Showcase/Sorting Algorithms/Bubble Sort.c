#include <stdio.h>
void BubbleSort(int *arr, int l);
int main()
{
	register int i;
	int x;

/* INPUT */
	int l; 
	printf("How long should the array be: ");
	scanf("%d",&l);

	int arr[l];

	printf("begin filling values\n");
	for(i=0;i<l;++i)
	{
		printf("value %d: ",i);
		scanf("%d",&x);
		arr[i] = x;
	}
	
	printf("the array before sorting: ");
	printf("{ ");
	for (i=0;i<l;++i)
	{
		printf("%d, ",arr[i]);
	}
	printf("}\n");

/* SORT */
	BubbleSort(arr, l);

/* OUTPUT */
	printf("the array after sorting: ");
	printf("{ ");
	for (i=0;i<l;++i)
	{
		printf("%d, ",arr[i]);
	}
	printf("}\n");

return 0;
}

void BubbleSort(int *arr, int l)
{
	int temp;
	register int i,j;

	for(j=0;j<l;++j)
	{	
		for(i=0;i<l-1;++i)
		{
			if (*(arr + i) > *(arr + i + 1))
			{
				/* switch positions */
				temp = *(arr + i);
				*(arr + i) = *(arr + i +1);
				*(arr + i + 1) = temp;
			} 
		}
	}
}
