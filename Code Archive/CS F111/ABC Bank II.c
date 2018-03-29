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
		for(j=1; j<col_len+1; ++j)
		{
			scanf("%d", (*(array + i) + j));
		}
	}
}


int branchSum(int **array, int row)
{
	int sum=0;
	register int j;
	int *line = *(array+row);
	for(j=0;j<line[0]+1;++j)
	{
		sum += line[j];
	}
	return sum;
}


void printArr(int **array, int rows)
{
	register int i,j;
	for(i=0;i<rows;++i)
	{
		int columns = **(array + i);
		printf("branch no. %d: ", i);
		for(j=1;j<columns+1;++j)
		{
			printf("%d ", array[i][j]);
		}
		putchar('\n');
	}
}

void maxDepositBranch(int **array, int rows)
{
	int max_net_deposit=0, max_branch=0, branch_sum=0;
	register int i;
	for(i=0;i<rows;++i)
	{
		branch_sum = branchSum(array, i);
		if(branch_sum > max_net_deposit)
		{
			max_net_deposit = branch_sum;
			max_branch = i;
		}
	}
	printf("\nBranch no. %d had the maximum net deposit of %d\n", max_branch, max_net_deposit);
}

int abs(int num)
{
	if(num >= 0)
		return num;
	else
		return -num;
}

void maxSingleTransaction(int **array, int rows)
{
	int max=0, branch, transaction;
	register int i,j;
	for(i=0;i<rows;++i)
	{
		for(j=0;j<**(array + i);++j)
		{
			transaction = abs(*(*(array + i) + j));
			if(transaction > max){
				max = transaction;
				branch = i;
			}
		}
	}
	printf("The maximum observed transaction was of value %d at branch %d.\n", max, branch);
}

int main()
{
	int m;
	scanf("%d", &m);

	int **array = generate(m);
	
	fillArr(array, m);
	
	printArr(array, m);	
	
	maxDepositBranch(array, m);
	maxSingleTransaction(array, m);
	
	return 0;
}
