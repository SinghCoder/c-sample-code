/* always start each linked list by setting the head of that list to NULL*/

#include "13.h"

STUDENT *prepend(STUDENT *old_head, char *name)
{
	STUDENT *new_head = (STUDENT *)malloc(sizeof(STUDENT));
	new_head->next = old_head;
	new_head->count = 0;
	strcpy(new_head->name, name);
	return new_head; 
}


STUDENT *append(STUDENT *old_tail, char *name)
{
	STUDENT *new_tail = (STUDENT *)malloc(sizeof(STUDENT));
	old_tail->next = new_tail;
	strcpy(new_tail->name, name);
	return new_tail; 
}

STUDENT *Insert(STUDENT *before, STUDENT *after, char *name)
{
	/* the head must exist, can't be an empty linked list */
	STUDENT *new_node;

	if(before==NULL)
		new_node = prepend(after, name);
	else
	{
		new_node = (STUDENT *)malloc(sizeof(STUDENT));
		before->next = new_node;
		new_node->next = after;
		strcpy(new_node->name, name);
	}
	return new_node;
		
}


STUDENT *addName(STUDENT *head, char *name)
{
	FLAG exists=0;

	if(head==NULL)
	{
		head = prepend(head, name);
	}

	STUDENT *cursor = head;

	while(cursor)
	{
		if(!strcmp(cursor->name, name))
		{
			exists = 1;
			break;
		}
		if(cursor->next == NULL)
			break;
		cursor = cursor->next;
	}

	if(exists)
		cursor->count += 1;
	else
	{
		cursor = append(cursor, name);
		cursor->count += 1;
	}

	return head;
}


STUDENT *addSortOrder(STUDENT *head, char *name)
{
	FLAG exists=0;

	if(head==NULL)
	{
		head = prepend(head, name);
	}

	STUDENT *cursor = head, *prev = NULL;

	while(cursor)
	{
		if(!strcmp(cursor->name, name))
		{
			printf("0");
			exists = 1;
			break;
		}
		else if(strcmp(cursor->name, name) < 0)
		{			
			printf("1");
			cursor = Insert(prev, cursor, name);		
			break;
		}
		else if(cursor->next == NULL)
		{
			printf("2");
			append(cursor, name);
			break;
		}
		prev = cursor;
		cursor = cursor->next;
	}

	if(exists)
		cursor->count += 1;
	else
	{
		
		cursor->count += 1;
	}
	return head;
}


void generateUnique(STUDENT *head)
{
	int unique_count=0;
	FILE *out = fopen("unique.txt", "w");
	STUDENT *cursor = head;
	
	while(cursor)
	{
		++unique_count;
		printf("adding entry: %s\t%d\n", cursor->name, cursor->count);
		fprintf(out, "%s\t%d\n", cursor->name, cursor->count);
		cursor = cursor->next;
	}
	
	fclose(out);
	printf("\n\nUnique.txt file successfully generated. %d unique entries detected.\n", unique_count);
	return;
}


void purgeLinkedList(STUDENT *head)
{
	STUDENT *next;
	while(head)
	{
		
		next = head->next;
		free(head);
		head = next;
	}
	printf("Linked list successfully purged.\n");
	return;
} 


STUDENT *generateLinkedList(STUDENT *head, int len, int sorted)
{
	register int i;
	char name[MAX];
	if(sorted)
	{
		for(i=0; i<len; ++i)
		{
			scanf("%s", name);
			head = addSortOrder(head, name);
		}
	}
	else
	{
		for(i=0; i<len; ++i)
		{
			scanf("%s", name);
			head = addName(head, name);
		}
	}
	return head;
}


STUDENT *findMostFrequent(STUDENT *head)
{
	int max=0;
	STUDENT *cursor = head, *abundent;
	while(cursor)
	{
		if(cursor->count > max)
		{
			max = cursor->count;
			abundent = cursor;
		}
		cursor = cursor->next;
	}
	return abundent;
}


STUDENT *deleteSingle(STUDENT *head, char *name)
{
	FLAG exists=0;
	STUDENT *cursor = head, *prev = head;
	while(cursor)
	{
		if(!strcmp(cursor->name, name))
		{
			exists = 1;
			break;
		}
		if(cursor->next == NULL)
		{
			break;
		}
		prev = cursor;
		cursor = cursor->next;
	}
	if(exists)
	{
		if(cursor->count <= 1)
		{
			if(cursor == head)
			{
				head = cursor->next;
				free(cursor);
			}
			else
			{
				prev->next = cursor->next;
				free(cursor);
			}
		}

		else
		{
			cursor->count -= 1;
		}

	}
	return head;

}


int main()
{
	int N;
	STUDENT *head=NULL, *abundent;		// setting head to NULL is VERY important!!!
	
	scanf("%d", &N);
	head = generateLinkedList(head, N, 1);

	
	abundent = findMostFrequent(head);
	printf("the most abundent name is: %s with %d occurances.\n", abundent->name, abundent->count);

	deleteSingle(head, abundent->name);

	printf("reduced %s by 1\n", abundent->name);
	abundent = findMostFrequent(head);
	printf("the most abundent name is: %s with %d occurances.\n", abundent->name, abundent->count);
	
	generateUnique(head);
	purgeLinkedList(head);
}

