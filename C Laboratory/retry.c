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

void readData(STUD a[], int max)
{
	/* 
		code goes here ...
	*/
}


void storeRanks(STUD a[], int max)
{
	/*
		code goes here...
	*/
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
  storeRanks(arr,maxelems);	// computes rank of each student and stores in the record
  displayData(arr,maxelems);
  return 0;
}
