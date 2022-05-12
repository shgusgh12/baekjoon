#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int age;
	char name[101];
	int idx;
}node;


int compare(node* a, node* b)
{
	if (a->age < b->age)
		return -1;
	else if (a->age > b->age)
		return 1;
	else
	{
		if (a->idx < b->idx)
			return -1;
		else
			return 1;
	}
}

int main()
{
	
	int N;
	scanf("%d", &N);
	node* id;
	id = (node*)malloc(N * sizeof(node));
	for (int i = 0; i < N; i++)
	{
		scanf("%d %s", &id[i].age, id[i].name);
		id[i].idx = i;
	}
	qsort(id, N, sizeof(node), compare);
	for (int i = 0; i < N; i++)
	{
		printf("%d %s\n", id[i].age, id[i].name);
	}
	
	

}