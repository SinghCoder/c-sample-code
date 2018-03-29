#include <stdio.h>
#include <stdlib.h>

struct tracker
{
	int **shell;
	int rows;
	int columns;
};
struct tracker *trackers = (struct tracker *)calloc(1, sizeof(struct tracker));
int TRACKERS_LEN = 0;


void addTracker(int **shell, int rows, int columns)
{
	trackers = (struct tracker *)realloc(trackers, 	sizeof(struct tracker)*(TRACKERS_LEN+1));
	struct tracker tracker_object = {**shell, rows, columns};
	*(trackers + TRACKERS_LEN - 1) = tracker_object;
}


int **generate(int rows, int columns)
{
	int i;
	int **shell = (int **)malloc(sizeof(int *)*rows);
	for(i=0;i<columns;++i)
		*(shell + i) = (int *)malloc(sizeof(int)*columns);
	
	
	// record the new array in trackers
	addTracker(shell, rows, columns);
	TRACKERS_LEN += 1;
	
	return shell;
}


void printArr(int **array)
{
	// find the array in trackers -- since I'm no pro, I can't set up hash tables for faster lookups .... yet.
	int i,j;
	int rows,columns;
	for(i=0; i<TRACKERS_LEN; ++i)
	{
		if(**array = trackers[i]->shell)
		{
			rows = trackers[i].rows;
			columns = trackers[i].columns;
			break;
		}
		printf("array not found.\n");
		exit(0);
	}
	for(i=0;i<rows;++i)
	{
		for(j=0;j<rows;++j)
		{
			printf("%d ", *(*(array + i) + j));
		}
		printf("\n");
	}
}


int main()
{
	int m,n;
	scanf("%d %d", &m, &n);
	int **array = generate(m, n);
	printArr(array);
	return 0;
}
