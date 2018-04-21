#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 40

typedef struct student{
	char name[MAX];
	int count;
	struct student *next;
} STUDENT;

typedef int FLAG;
