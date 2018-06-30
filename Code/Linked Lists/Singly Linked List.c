#include "Linked List.h"

NODE *generateNode(int value, NODE *prev)
{
	NODE *new_node = (NODE *)malloc(sizeof(NODE)*1);
	new_node->value = value;
	prev->next = new_node;
	return new_node;
}

NODE *prepend(int value)
{
	// remember that HEAD is only a pointer.

	NODE *new_head = (NODE *)malloc(sizeof(NODE)*1);
	new_head->value = value;

	new_head->next = HEAD;
	HEAD = new_head;

	printf("Head updated, value at head: %d.\n", HEAD->value);

	return new_head;
}

int delete(NODE *node)
{
	if(node != NULL)
	{
		free(node);
		return 1;
	}
	return 0;
}

int main()
{
	int i;
	int val;
	NODE *current;

	printf("enter a value: ");

	scanf("%d", &val);
	current = prepend(val);
	printf("New node generated.\n\n");

	for(i=0;i<4;++i)
	{
		printf("enter a value: ");
		scanf("%d", &val);
		current = generateNode(val, current);
		printf("New node generated.\n\n");
	}

	current = HEAD;

	printf("Replaying linked list data:\n");
	for(i=0;i<5;++i)
	{
		printf("%d\t", current->value);
		current = current->next;
	}

	printf("\n\n");

	current = HEAD;
	NODE *temp;

	printf("Now safely deleting all of the nodes.\n");
	for(i=0;i<5;++i)
	{
		temp = current->next;
		delete(current);
		current = temp;
	}

	printf("All nodes successfully deleted.\n");

	printf("\nLinked List implimentation successful.\n");
	return 0;
}
