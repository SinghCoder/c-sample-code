#include <stdio.h>
#include <stdlib.h>

int **generate(int rows, int columns)
{
	int i;
	int **shell = (int **)malloc(sizeof(int *)*rows);

	for(i=0;i<columns;++i)
		*(shell + i) = (int *)malloc(sizeof(int)*columns);
	
	return shell;
}


void fillArr(int **array, int rows, int columns)
{
	register int i,j;
	for(i=0;i<rows;++i)
	{
		for(j=0;j<columns;++j)
		{
			scanf("%d", (*(array + i) + j));
		}
	}
}

void printArr(int **array, int rows, int columns)
{
	register int i,j;
	for(i=0;i<rows;++i)
	{
		for(j=0;j<columns;++j)
		{
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int m,n;
	scanf("%d %d", &m, &n);


	int **array = generate(m, n);
	
	fillArr(array, m, n);
	
	printArr(array, m, n);
	
	return 0;

}
