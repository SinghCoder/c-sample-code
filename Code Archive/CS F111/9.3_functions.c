#include <stdio.h>


// List of all Functions - Function Prototypes/Declerations
void fill(int *matrix, int rows, int columns);
void printRow(int *row, int length);
int printExplicitRowSum(int *row, int length);
void printMatrix(int *matrix, int rows, int columns);
void printMatrixWithSums(int *matrix, int rows, int columns);
void printExplicitMatrixSum(int *matrix, int rows, int columns);
int computeSumOfDeposits(int row[], int size);
int computeSumOfDepositsOnly(int row[], int size);
int computeMaxNetDeposit(int *matrix, int rows, int columns);
int computeMaxDepositOnly(int *matrix, int rows, int columns);
int computeMaxSingleDeposit(int *matrix, int rows, int columns);
int computeFlow(int row[], int size);
int computeMaxFlow(int *matrix, int rows, int columns);
int computeMaxSingleTransaction(int *matrix, int rows, int columns);


// Function Definitions
void fill(int *matrix, int rows, int columns)
{
	int i,j;
	for(i=0; i<rows; ++i)
	{	
		for(j=0; j<columns; ++j)
		{
			scanf("%d", (matrix + i*columns + j));
		}
	}
}


void printRow(int *row, int length)
{
	int i;
	for(i=0; i<length; ++i)
	{
		printf("%d ", *(row + i));
	}
	printf("\n");	
}


int printExplicitRowSum(int *row, int length)
{
	int i;
	int sum=0;
	for(i=0; i<length; ++i)
	{
		printf("%d + %d", sum, row[i]);
		sum += row[i];
		printf("= %d\n", sum);
	}
	return sum;	
}



void printMatrix(int *matrix, int rows, int columns)
{
	int i,j;
	int sum;
	for(i=0; i<rows; ++i)
	{	
		printf("row no. %d\t", i+1);
		printRow((matrix + i*columns), columns);
	}
}


void printMatrixWithSums(int *matrix, int rows, int columns)
{
	int i,j;
	int sum;
	for(i=0; i<rows; ++i)
	{	
		printf("row no. %d\t", i+1);
		printRow((matrix + i*columns), columns);
		sum = computeSumOfDeposits((matrix + i*columns), columns);
		printf("sum is: %d\n\n", sum);
	}
}


void printExplicitMatrixSum(int *matrix, int rows, int columns)
{
	int i,j;
	for(i=0; i<rows; ++i)
	{	
		printf("row no. %d\t", i+1);
		printExplicitRowSum((matrix + i*columns), columns);
	}
}


int computeSumOfDeposits(int row[], int size)
{
	int i;
	int sum=0;
	for(i=0; i<size; ++i)
	{
		sum += row[i];
	}
	return sum;
}


int computeSumOfDepositsOnly(int row[], int size)
{
	int i;
	int sum=0;
	for(i=0; i<size; ++i)
	{
		if(row[i] > 0)
			sum += row[i];
	}
	return sum;
}



int computeMaxNetDeposit(int *matrix, int rows, int columns)
{
	int i;
	int row_sum=0, max=0, branch=0;
	for(i=0; i<rows; ++i)
	{
		row_sum = computeSumOfDeposits((matrix + i*columns), columns);
		if(row_sum > max)
		{
			max = row_sum;
			branch = i + 1;
		}
	}
	printf("The maximum net deposit was recorded in branch no. %d at a value of %d\n", branch, max);
	printRow(&matrix[branch], columns);
	return 0;
}


int computeMaxDepositOnly(int *matrix, int rows, int columns)
{
	int i;
	int row_sum=0, max=0, branch=0;
	for(i=0; i<rows; ++i)
	{
		row_sum = computeSumOfDepositsOnly((matrix + i*columns), columns);
		if(row_sum > max)
		{
			max = row_sum;
			branch = i + 1;
		}
	}
	printf("The maximum deposits (excl. withdrawls) was recorded in branch no. %d at a value of %d\n", branch, max);
	printRow(&matrix[branch], columns);
	return 0;
}


int computeMaxSingleDeposit(int *matrix, int rows, int columns)
{
	int i,j;
	int max=0, branch=0;
	for(i=0;i<rows;++i)
	{
		for(j=0;j<columns;++j)
		{
			if(*(matrix + i*columns + j) > max)
			{
				max = *(matrix + i*columns + j);
				branch = i+1;
			}
		}
	}
	printf("The maximum single deposit was recorded in branch no. %d at a value of %d\n", branch, max);
}


int computeFlow(int row[], int size)
{
	int i;
	int sum=0;
	for(i=0; i<size; ++i)
	{
		if(row[i] > 0)
			sum += row[i];
		else
			sum -+ row[i];
	}
	return sum;
}


int computeMaxFlow(int *matrix, int rows, int columns)
{
	int i;
	int row_sum=0, max=0, branch=0;
	for(i=0; i<rows; ++i)
	{
		row_sum = computeFlow((matrix + i*columns), columns);
		if(row_sum > max)
		{
			max = row_sum;
			branch = i + 1;
		}
	}
	printf("The maximum net deposit was recorded in branch no. %d at a value of %d\n", branch, max);
	printRow(&matrix[branch], columns);
	return 0;
}

int computeMaxSingleTransaction(int *matrix, int rows, int columns)
{
	int i,j;
	int max=0, branch=0, val=0;	// Val acts as a placeholder so that we don't change the original data
	for(i=0;i<rows;++i)
	{
		for(j=0;j<columns;++j)
		{
			val = *(matrix + i*columns + j);
			if(val < 0)
				val *= -1;
			if(val > max)
			{
				max = val;
				branch = i+1;
			}
		}
	}
	printf("The maximum single transaction was recorded in branch no. %d at a value of %d\n", branch, max);
}

