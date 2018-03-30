#include <stdio.h>
#include <stdlib.h>


int **generate(int rows, int columns)
{
	/* the shell pointer will point to a dynamic 1D-array-pointer which will in turn point to a memory location for an int in this case. */
	if(!(rows > 0 && columns > 0))
	{
		printf("error.");
		exit(0);
	}	
	int i;
	int **shell = malloc(sizeof(int *)*rows);	
	for(i=0;i<rows;++i)
	{
		*(shell + i) = (int *)malloc(sizeof(int)*columns);
		// alternatively: shell[i] = malloc(sizeof(int)*columns)
	}
	return shell;
}


void safeDelete(int **arr, int rows)
{
	/* the right, and safe and right way to free up memory of a 2D array is to free each "subarray" i.e. shell[i], then the "shell" */
	int i;
	for(i=0; i<rows; ++i)
	{
		free(*(arr + i));
		// alternatively: free(arr[i])
	}
	free(arr);
}


void fill(int **arr, int rows, int columns)
{ 
	int i,j;
	for(i=0;i<rows;++i)
	{
		for(j=0;j<columns;++j)
		{
			printf("Enter a value for row %d and columns %d: ", i, j);
			// if this was to be consumer facing then we could use i+1 and j+1 instead of counting from 0/
			scanf("%d", (*(arr + i) + j));
			// alternative way: (*arr + i*columns + j )
			// alternative way: &arr[i][j]
		}
	}
}


void printArr(int **arr, int rows, int columns)
{
	register int i,j;	// register is just specifying how to store the variables, storing counter vars on the register == speed!
	for(i=0; i<rows; ++i)
	{
		for(j=0; j<columns; ++j)
		{
			printf("%d ", *(*(arr + i) + j));
			// alternative way: *(*arr + i*columns + j )
			// alternative way: arr[i][j]
		}
		putchar('\n');
	}
}


int main()
{
	int m,n;
	int a,b;
	printf("enter no. of rows: ");
	scanf("%d", &m);
	printf("enter no. of columns: ");
	scanf("%d", &n);
	printf("Generating a %dx%d matrix.\n", m, n);
	int **my_arr = generate(m, n);
	fill(my_arr, m, n);
	printArr(my_arr, m, n);

	safeDelete(my_arr, m);

	return 0;
}
