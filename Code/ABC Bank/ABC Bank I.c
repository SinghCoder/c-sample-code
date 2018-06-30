/* 
when passing a mulit-dimensional array, always dereference it all the way down to base address of the inner most array then use *matrix on the other side.
*/

#include "9.3_functions.c"

int main()
{
	int rows,columns;
	scanf("%d %d", &rows, &columns);
	int matrix[rows][columns];
	
	printf("initialized a matrix of %d rows and %d columns.\n\n", rows, columns);

	fill(*matrix, rows, columns);

	computeMaxDepositOnly(*matrix, rows, columns);
	computeMaxSingleTransaction(*matrix, rows, columns);

	printf("\n\nNote: I'm making my answer consumer facing (I'm nice that way) ....\n");

	return 0;
}

