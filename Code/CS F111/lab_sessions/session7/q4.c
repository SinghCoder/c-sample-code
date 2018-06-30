#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findMax(int *arr, int len);
int findMin(int *arr, int len);

int main()
{
	int i, n, seed, arr[10], val;


	seed = time(NULL);
	srand(seed);

	// fill
	for(i=0; i<10; ++i){
		val = rand();
		val %= 40;
		if(val < 20)
			val += 20; // this works since the interval is between 20 and 40 else think of something else.
		*(arr + i) = val;
	}

	// print
	for(i=0; i<10; ++i){
		printf("%d\n", *(arr + i));
	}

	int max, min;

	max = findMax(arr, 10);
	min = findMin(arr, 10);

	printf("the maximum is: %d\nthe minimum is: %d\n", max, min);
}

int findMax(int *arr, int len){
	register int i;
	int max = arr[0];
	for(i=1;i<len;++i){
		if(arr[i] > max)
			max = arr[i]; 
	}
	return max;
}

int findMin(int *arr, int len){
	register int i;
	int min = arr[0];
	for(i=1;i<len;++i){
		if (arr[i] < min)
			min = arr[i]; 
	}
	return min;
}
