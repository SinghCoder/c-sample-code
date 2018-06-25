#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
	int value;
	struct node *next;
} NODE;

NODE *HEAD=NULL;	// ALways set the head to NULL initially!!!



