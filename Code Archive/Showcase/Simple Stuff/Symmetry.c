#include <stdio.h>

int test_sym(int *li, int len);
int main()
{
	int l,i;
	printf("array length: ");
	scanf("%d", &l);

	int li[l];
	for(i=0; i<l; ++i)
	{
		printf("value %d: ", i);
		scanf("%d", (li + i));
	}

	test_sym(&li[0], l);
return 0;
}

int test_sym(int *arr, int len)
{
	int i;
	printf("list filled.\n");
	for(i=0; i<(len-1)/2; ++i)
	{
		if (*(arr + i) == *(arr + len - i - 1))
			printf("symmetry detected between positions %d and %d: %d\n", i, len-i-1, *(arr + i));
	}
}
