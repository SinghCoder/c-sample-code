#include <stdio.h>

int main()
{
	int temp;
	int i,j;

	int arr[5] = {1, 5, 3, 8, 2};

	int len = sizeof(arr)/4;	
/* note if arr is passed as a pointer to another function this trick won't work as it will just return the size of a pointer and not the size of the array. */

	for(i=0; i<len; ++i)
		printf("%d ", arr[i]);
	printf("\n");

	// insertion sort	
	for(i=0; i<len; ++i)
	{
		for(j=i; j>0; --j)
		{
			if(arr[j]<arr[j-1])
			{
				temp =arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	}

	for(i=0; i<len; ++i)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
