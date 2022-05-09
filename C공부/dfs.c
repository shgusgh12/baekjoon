#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1;
typedef struct node* nodePointer;
typedef struct node
{
	int vertex;
	nodePointer link;
}node;
nodePointer graph[1000];
int visited[10];
nodePointer temp[100];

void init(int num)
{
	for (int i = 1; i < num; i++)
	{
		graph[i]->link = NULL;
		graph[i]->vertex = 0;
	}
}


void dfs(int v)
{
	nodePointer w;
	visited[v] = TRUE; //현재 방문 노드
	printf("%d ", v); 
	for (w = graph[v]; w; w = w->link) //인접한 방문 노드 
		if (!visited[w->vertex])
			dfs(w->vertex);
}


void create(int vertex, int i)
{
    
	node* newNode = (node*)malloc(sizeof(node));
	newNode->vertex = vertex;
	newNode->link = NULL;
    if(graph[i]==NULL)
    {
        newNode->link = graph[i];
	    graph[i] = newNode;
        temp[i] = newNode;
    }
    else
    {
        temp[i]->link = newNode;
        temp[i] = temp[i]->link;
    }
	

	
}

int main()
{
	printf("2018111113 노현호\n");
	FILE* fp;
	fp = fopen("in.txt", "r");
	int vnum;

	fscanf(fp, "%d", &vnum);
	

	int arr[10][10];
	for (int i = 0;i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			arr[i][j]= 0;
		}
	}
	for (int i = 2; i <= vnum; i++)
	{
		for (int j = 1; j < i; j++)
		{
			fscanf(fp, "%d", &arr[i][j]);
		}
	}
	for (int i = 0;i <= vnum; i++)
	{
		for (int j = 0; j <= vnum; j++)
		{
			if (arr[i][j] == 1)
			{
				create(i, j);
                create(j, i);
			}
			
		}
	}


	
	
	while (1)
	{
		int start;
		printf("\n");
		scanf("%d", &start);
		if (start == -1)
		{
			break;
		}
		dfs(start);
		for (int i = 0; i < 10; i++)
		{
			visited[i] = 0;
		}
	}
}
