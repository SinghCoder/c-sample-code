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

void traverse(NODE *node, int (*function)(NODE *))		// implimentation of callback functions
{
	NODE *next;
	while(node != NULL)
	{
		next = node->next;
		function(node);
		node = next;
		/* why "next"? Because if the current "node" gets deleted such as in the function delete, 
		then we need to have a record of the next pointer. Can't lose that handle. */
	}
}

int printNode(NODE *node)
{
	if(node != NULL)
	{
		printf("%d\t", node->value);
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

	printf("Replaying linked list data:\n");

	int (*del)(NODE *) = &delete;
	int (*print)(NODE *) = &printNode;

	traverse(HEAD, print);
	printf("\n\n");
	traverse(HEAD, del);

	printf("All nodes successfully deleted.\n");

	printf("\nLinked List implimentation with Callback Functions successful.\n");
	return 0;
}
