#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

int **generateMatrix(int rows, int cols)
{
	register int i;
	int **shell = (int **)malloc(sizeof(int *)*ROWS);	// this will hold all of the rows
	for(i=0; i<ROWS; ++i)
		shell[i] = (int *)malloc(sizeof(int)*COLS);		// generate each induvisual row
	return shell;
}

void populateMatrix(int **matrix)
{
	register int i,j;
	for(i=0; i<ROWS; ++i)
	{
		for(j=0; j<COLS; ++j)
		{
			printf("enter value for pos [%d, %d]: ", i, j);
			scanf("%d", *(matrix + i) + j);
		}
	}
	printf("Done filling!\n");
	return;
}

void printColsTotals(int **matrix)
{
	int row_total;
	register int i,j;
	for(j=0; j<COLS; ++j)
	{
		for(i=0, row_total=0; i<ROWS; ++i)
		{
			row_total += *(*(matrix + i) + j);
		}
		printf("%d ", row_total);
	}
	printf("\n");
	return;
}

void printMatrixAndColsTotals(int **matrix)
{
	register int i,j;
	for(i=0; i<ROWS; ++i)
	{
		for(j=0; j<COLS; ++j)
		{
			printf("%d ", *(*(matrix + i) + j));
		}
		printf("\n");
	}
	printf("----------------------\n");
	printColsTotals(matrix);
	return;
}

void purgeMatrix(int **matrix)
{
	register int i;
	for(i=0; i<ROWS; ++i)
	{
		free(matrix[i]);
	}
	free(matrix);
}

int *effectiveChanges(int *shift)
{
	register int i;

	for(i=0;i<ROWS;++i)
	{
		shift[i] = shift[i]%COLS;
	}
	return shift;
}

void rightShiftRow(int *row, int val)
{
	register int i;

	int copy[COLS];
	for(i=0; i<COLS; ++i)
		copy[i] = row[i];

	for(i=0; i<COLS; ++i)
		row[(i + val)%COLS] = copy[i];

	return;
}

void performShifts(int **matrix, int *shift)
{
	register int i;
	shift = effectiveChanges(shift);	// find the effective number of shifts	
	for(i=0; i<ROWS; ++i)
	{
		rightShiftRow(matrix[i], shift[i]);
	}
	return;	
}

int main()
{
	int  **mat = generateMatrix(ROWS, COLS);
	populateMatrix(mat);
	printMatrixAndColsTotals(mat);
	
	// generate the shift array
	register int i;
	int *shift = (int *)malloc(sizeof(int)*COLS);
	for(i=0; i<ROWS; ++i)
	{
		do
		{
			printf("Enter shift value for row %d: ", i);
			scanf("%d", (shift + i));
			if(shift[i] < 0)
			{
				printf("negative numbers are not acceptable.\n");
			}
		}
		while(shift[i] < 0);
	}

	performShifts(mat, shift);

	printMatrixAndColsTotals(mat);

	free(shift);
	purgeMatrix(mat);
	return 0;
}
