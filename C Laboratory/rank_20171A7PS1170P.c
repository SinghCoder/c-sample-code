/*
			ID. No.: 2017A7PS1170P
			Name: Hemanth V. Alluri
			Set (A or B): A
*/
			
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct record {
	char name[70];
	char idno[16];
	float compre;
	int rank;
  } STUD;

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

int findMax(float *arr, int len)	// return index of minimum
{
		int i;
		float max=0;
		int index=0;
		for(i=0; i<len; ++i)
		{
			if(arr[i] > max)
			{
				index = i;
				max = arr[i];
			}
		}
		return index;
}

void storeRanks(STUD a[], int max)
{
	int i, j, c=0;
	int exists=0;
	int temp, index;
	float ranks[max];
	
	for(i=0; i<max; ++i)	// i is for each student
	{
		exists = 0;

		for(j=0; j<c; ++j)	// j is the conter variable for testing if the rank exists
		{
			if(a[i].compre - ranks[j] < 0.001)
			{
				exists = 1;
				break;
			}
		}
		
		if(exists)
				break;
			
		ranks[c] = a[i].rank;
		++c;
	}

	// sort
	for(i=0; i<c; ++i)
	{
		temp = ranks[i];
		index = findMax(ranks + i, c-i);
		ranks[i] = ranks[index];
		ranks[index] = temp;
	}

	// store ranks
	for(i=0; i<max; ++i)
	{
		for(j=0; j<c; ++j)
		{
			
		}
		a[i].rank = j + 1;
	}
  return;
}

void displayData(STUD a[], int max)
{
  int i;
  for (i = 0; i < max; ++i)
    printf("%18s %20s\t %.2f %d\n", a[i].idno, a[i].name, a[i].compre, a[i].rank);
  return;
}

int main()
{
  int maxelems;
  scanf("%d", &maxelems);
  STUD arr[maxelems];
  readData(arr,maxelems);	// populates the array of structures
  //storeRanks(arr,maxelems);	// computes rank of each student and stores in the record
  displayData(arr,maxelems);
  return 0;
}
