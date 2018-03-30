#include <stdio.h>
void scan(int *arr, int len);
int main(){
	int N,X;
	printf("How long will your list be? ");
	scanf("%d", &N);

	int arr[N];
	register int i;
	for (i=0; i<N; ++i){
		printf("enter a value to store at the %d index: ", i);
		scanf("%d", (arr + i));
	};

	scan(arr, N);

return 0;
}

void scan(int *arr, int len){
	int X, count;
	register int i;
	printf("please enter a value that you'd like to scan for: ");
	scanf("%d", &X);

	printf("Scanning");

	for(i=0; i<len; ++i){
		if(*(arr+i) == X)
			count++;
		printf(".");
	};

	printf("total number of occurrances of %d are %d\n", X, count);
}
