#include <stdio.h>
#include <stdlib.h>

int **generate(int rows)
{
	int i;
	int **shell = (int **)malloc(sizeof(int *)*rows);
	return shell;
}

// the first element of each row will contain it's remaining length.
void fillArr(int **array, int rows)
{
	int col_len;
	register int i,j;
	for(i=0;i<rows;++i)
	{
		scanf("%d", &col_len);
		*(array + i) = (int *)malloc(sizeof(int)*col_len+1);
		**(array + i) = col_len;
		//printf("no. of columns: %d\n", col_len);
		for(j=1; j<col_len+1; ++j)
		{
			scanf("%d", (*(array + i) + j));
		}
	}
}

void printArr(int **array, int rows)
{
	register int i,j;
	for(i=0;i<rows;++i)
	{
		int columns = **(array + i);
		for(j=1;j<columns+1;++j)
		{
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
}


int main()
{
	int m;
	scanf("%d", &m);
	
	//printf("no. of rows: %d\n", m);

	int **array = generate(m);
	
	fillArr(array, m);
	
	printArr(array, m);
	
	return 0;
}
