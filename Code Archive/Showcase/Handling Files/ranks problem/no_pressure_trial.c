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

void insertionSort(float *arr, int len)
// insertion sort highest to lowest
{
	float temp;
	COUNTER i, j;
	for(i=0; i<len; ++i)
	{
		for(j=i; j>0; --j)
		{
			if(arr[j] > arr[j-1])
			{
				temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
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
	FLAG exists=0;
	float ranks[max];
	for(i=0; i<max; ++i)
	{
		// check if it already exists
		for(j=0; j<c; ++j)
		{
			if(a[i].compre == ranks[j])
			{
				exists = 1;
				break;
			}
		}

		if(!exists)
		{
			ranks[c] = a[i].compre;
			++c;
		}

		exists = 0;
	}

	insertionSort(ranks, max);

	for(i=0; i<max; ++i)
	{
		for(j=0; j<c; ++j)
		{
			if(a[i].compre == ranks[j])
			{
				a[i].rank = j+1;
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




/*

The Character-By-Character Parser Method:


void getSingle(STUD *a, FILE *fp)
{

		int c=0;
		char ch;

		char name[70];
		char idno[16];
		char compre[10];
		
    // first parse the idno.
		for(c=0;c<12;++c)
		{		
			idno[c] = fgetc(fp);
		}

		fgetc(fp);		// eliminate the ','

		// now get the name
		for(c=0; ch!=','; ++c)
		{
			ch = fgetc(fp);
			name[c] = ch;
		}
		name[c-1] = '\0';

		// finally get the compre grade
		for(c=0; ch!='\n'; ++c)
		{
			ch = fgetc(fp);
			compre[c] = ch;
		}
		compre[c-1] = '\0';

		// now transfer over the results.
		strcpy(a->idno, idno);
		strcpy(a->name, name);
		a->compre = atof(compre);
		return;
}

void readData(STUD a[], int max)
{
	int i=0;
    FILE *fp = fopen("rank_data.txt", "r");
	while(i<max)
	{
		getSingle(&a[i], fp);
		++i;
	}
	printf("all data parsed!\n");
  fclose(fp);
  return;
}

*/
