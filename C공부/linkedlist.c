#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define REALLOC(p,s) \
if(!((p) = realloc(p,s))){ \
fprintf(stderr, "insufficient memory"); \
exit(EXIT_FAILURE); \
}
#define MALLOC(p,s) \
if(!((p) = malloc(s))){ \
fprintf(stderr, "insufficient memory"); \
exit(EXIT_FAILURE); \
}
#define MAX_STACK_SIZE 100
typedef struct listNode* listPointer;
typedef struct listNode {
	int data;
	listPointer link;
}node;
listPointer head;
listPointer first;
listPointer tail;
listPointer cur;
listPointer temp;

void P2(int y)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = y;
	if (first == NULL)
	{
		first = newNode;
		tail = newNode;
		tail->link = NULL;
	}
	else
	{
		newNode->link = first;
		first = newNode;
	}
}

void P1(int x)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = x;
	newNode->link = NULL;
	temp = head;
	if (head == NULL)
	{
		head = newNode;
		cur = newNode;
	}
	else
	{
		while (temp != NULL) {
			if (temp->data == x) {
				return;
			}
			temp = temp->link;
		}
		cur->link = newNode;
		cur = cur->link;
	}
}



int main()
{

	int x;
	int y;
	FILE* fp;
	FILE* fp1;
	fp = fopen("in2.txt", "r");
	fp1 = fopen("in1.txt", "r");

	while (!feof(fp1))
	{
		fscanf(fp1, "%d ", &x);
		P1(x);
	}
	


	printf("문제1: ");
	while (1)
	{
		if (head == NULL)
		{
			break;
		}
		printf("%d ", head->data);
		head = head->link;
	}

	printf("\n");


	while (!feof(fp))
	{
		fscanf(fp, "%d ", &y);
		P2(y);
	}
	printf("문제2: ");
	while (1)
	{
		if (first == NULL)
		{
			break;
		}
		printf("%d ", first->data);
		first = first->link;
		
	}
}