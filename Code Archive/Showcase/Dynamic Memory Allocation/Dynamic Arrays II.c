#include <stdio.h>
#include <stdlib.h>

/*-----------------------------------------------Generate, Resize, and Safely Delete------------------------------------------------------*/

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


void **resize(int **arr, int old_rows, int old_columns, int new_rows, int new_columns)
{
	int i;

	if(!(new_rows > 0 && new_columns > 0))
	{
		printf("error.");
		exit(0);
	}

	else if(new_rows < old_rows)
	{
		printf("Contracting...\n");

		// first clear delete/free all extra rows
		for(i=new_rows;i<old_rows;++i)
		{
			free(*(arr+i));
		}

		// now resize the array (shell i.e. **arr)
		arr = (int **)malloc(sizeof(int)*new_rows);

		// then resize all of the rows remaining
		if(new_columns != old_columns)
		{
			for(i=0;i<old_rows;++i)
			{
				*(arr + i) = (int *)realloc(*(arr + i), sizeof(int)*new_columns);
			}
		}
	}

	else if(new_rows > old_rows)
	{
		printf("Expanding...\n");

		// first resize all existing rows
		if(new_columns != old_columns)
		{
			for(i=0;i<old_rows;++i)
			{
				*(arr + i) = (int *)realloc(*(arr + i), sizeof(int)*new_columns);
			}
		}

		// now resize array (the "shell")
		arr = (int **)realloc(arr, sizeof(int)*new_rows);
			

		// generate new rows
		printf("generating new rows.\n");	
		for (i=old_rows; i<new_rows; ++i)
		{
			*(arr + i) = (int *)malloc(sizeof(int)*new_columns);
		}
	}
	
	else
	{
		if(new_columns != old_columns)
		{
			for(i=0; i<new_rows; ++i)	// or old_rows, same thing now in this case
			{
				*(arr + i) = (int *)realloc(*(arr + i), sizeof(int)*new_columns);
			}
		}
	}
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

// other ideas: deleting specific rows and columns or inserting them... which would be more useful I suppose

/*--------------------------------------------------Different Filling Functions-----------------------------------------------------------*/

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

void fillExpansion(int **arr, int old_rows, int old_cols, int new_rows, int new_cols)
{
	int i,j;
	if(new_cols > old_cols)
	{
		for(i=0; i<new_rows; ++i)
		{
			for(j=old_cols; j<new_cols; ++j)
			{
				printf("Enter a value for row %d and columns %d: ", i, j);
				scanf("%d", (*(arr + i) + j));
			}
		}
	}
	if(new_rows > old_rows)
	{
		for(j=0; j<new_cols; ++j)
			{
				for(i=old_rows; i<new_rows; ++i)
				{
					printf("Enter a value for row %d and columns %d: ", i, j);
					scanf("%d", (*(arr + i) + j));
				}
			}
	}
	if( (old_rows > new_rows) && (new_cols > old_cols) )
	{
		for(i=old_rows; i<new_cols; ++i)
		{
			for(j=old_cols; j<new_cols; ++j)
			{
				printf("Enter a value for row %d and columns %d: ", i, j);
				scanf("%d", (*(arr + i) + j));
			}
		}
	}
	if( (old_rows < new_rows) && (new_cols < old_cols) )
		printf("The array shrunk in both it's rows and columns so no need to fill anything.\n");
}

/*------------------------------------------------------Printing Functions----------------------------------------------------------------*/

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

/*---------------------------------------------------------Main Function------------------------------------------------------------------*/

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

	printf("\nNow, we'll resize this array.\n");
	printf("enter new no. of rows: ");
	scanf("%d", &a);
	printf("enter new no. of columns: ");
	scanf("%d", &b);
	resize(my_arr, m , n, a, b);
	fillExpansion(my_arr, m , n, a, b);	
	printArr(my_arr, a, b);
	safeDelete(my_arr, a);

	return 0;
}
