#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 200 
#define HEAP_FULL(n) (n==MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)
typedef struct {
	int key;
	/* other fields */
} element;
element heap[MAX_ELEMENTS];
int n = 0;void push(element item, int* n){	int i;	if (HEAP_FULL(*n))	{		fprintf(stderr, "heap if hull\n");		exit(EXIT_FAILURE);	}	i = ++(*n);	while ((i != 1) && (item.key > heap[i / 2].key))	{		heap[i] = heap[i / 2];		i /= 2;	}	heap[i] = item;}element pop(int* n){	int parent, child;	element item, temp;	if (HEAP_EMPTY(*n))	{		fprintf(stderr, "heap if empty\n");		exit(EXIT_FAILURE);	}	item = heap[1];	temp = heap[(*n)--];	parent = 1;	child = 2;	while (child <= (*n))	{		if (child < *n && heap[child].key < heap[child + 1].key)			child++;		if (temp.key >= heap[child].key)			break;		heap[parent] = heap[child];		parent = child;		child *= 2;	}	heap[parent] = temp;	return item;}int main(){	int cnt=0;	int a;	printf("컴퓨터학부 2018111113 노현호\n");	element k;	FILE* fp;	fp = fopen("in.txt", "r");	while (!feof(fp))	{		fscanf(fp, "%d", &k);		push(k, &n);		cnt++;	}	for (int i = 1; i <= cnt; i++)	{		printf("%d ", heap[i]);	}	printf("\n");	scanf("%d", &a);	for (int i = a; i > 0; i--)	{		pop(&n);	}	for (int i = 1; i <= n; i++)	{		printf("%d ", heap[i]);	}}