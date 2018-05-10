#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int COUNTER;
typedef int FLAG;

typedef struct record {
	char name[70];
	char idno[16];
	float compre;
	int rank;
  } STUD;

void readData(STUD a[], int max, char *file_name)
{
	COUNTER i=0;
	FILE *fp = fopen(file_name, "r");
	if(fp == NULL)
	{
		printf("could not open the file %s\n", file_name);
		return;
	}
	while(fp != NULL && i < max)
	{
		fscanf(fp, "%[^',']s", a[i].idno);
		fgetc(fp);							// remove the ','
		fscanf(fp, "%[^',']s", a[i].name);
		fgetc(fp);							// remove the ','
		fscanf(fp, "%f", &a[i].compre);
		fgetc(fp); 							// remove the '\n' before the next round
		i += 1;
	}
	return;
}

void insertionSort(float arr[][2], int len)
// insertion sort highest to lowest
{
	float temp1, temp2;
	COUNTER i, j;
	for(i=0; i<len; ++i)
	{
		for(j=i; j>0; --j)
		{
			if(arr[j][0] > arr[j-1][0])
			{
				temp1 = arr[j][0];
				temp2 = arr[j][1];
				arr[j][0] = arr[j-1][0];
				arr[j][1] = arr[j-1][1];
				arr[j-1][0] = temp1;
				arr[j-1][1] = temp2;
			}
			else
				break;
		}
	}
	return;
}

void storeRanks(STUD a[], int max)
{
	COUNTER i, j, c=0;
	int offset=0;	
	// to be used when there are multiple occurances of the same grade, causing an offset in the ranks e.g. 5, 5 ,7 not 5, 5, 6 
	FLAG exists=0;
	float ranks[max][2];	// [compre grade, no of extra occurances]
	for(i=0; i<max; ++i)
	{
		// check if it already exists
		for(j=0; j<c; ++j)
		{
			if(a[i].compre == ranks[j][0])
			{
				ranks[j][1] += 1;
				exists = 1;
				break;
			}
		}

		if(!exists)
		{
			ranks[c][0] = a[i].compre;
			ranks[c][1] = 0;
			++c; 
		}

		exists = 0;
	}

	insertionSort(ranks, max);

	for(i=0; i<max; ++i)
	{
		offset = 0;
		for(j=0; j<c; ++j)
		{
			offset += ranks[j][1]; 
			// this adds the offset of the jth rank itself but I wrote it this way instead of [j-1] to avoid -1 index (invalid read)
			if(a[i].compre == ranks[j][0])
			{
				offset -= ranks[j][1]; // to remove own offset
				a[i].rank = j+1+offset;
				break;
			}
		}
	}

	return;
}

void displayData(STUD a[], int max)
{
  int i;
  for (i = 0; i < max; ++i)
    printf("%18s %30s\t %5.2f %d\n", a[i].idno, a[i].name, a[i].compre, a[i].rank);
  return;
}

int main()
{
  int maxelems;
  printf("enter the number of elements you want to extract (must be less than 50): ");
  scanf("%d", &maxelems);
  STUD arr[maxelems];
  readData(arr, maxelems, "rank_data.txt");	// populates the array of structures
  storeRanks(arr,maxelems);	// computes rank of each student and stores in the record
  displayData(arr,maxelems);
  return 0;
}

