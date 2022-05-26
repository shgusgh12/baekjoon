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
int all[10];

void dfs(int v)
{
	nodePointer w;
	visited[v] = TRUE; //현재 방문 노드
	all[v] = TRUE;
	for (w = graph[v]; w; w = w->link) //인접한 방문 노드 
		if (!visited[w->vertex])
			dfs(w->vertex);
}


void create(int vertex, int i)
{

	node* newNode = (node*)malloc(sizeof(node));
	newNode->vertex = vertex;
	newNode->link = NULL;
	if (graph[i] == NULL)
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
	
	FILE* fp;
	fp = fopen("in.txt", "r");
	int vnum;
	fscanf(fp, "%d", &vnum);


	int arr[10][10];
	for (int i = 0; i <= vnum; i++)
	{
		for (int j = 0; j <= vnum; j++)
		{
			arr[i][j] = 0;
		}
	}
	for (int i = 2; i <= vnum; i++)
	{
		for (int j = 1; j < i; j++)
		{
			fscanf(fp, "%d", &arr[i][j]);
		}
	}

	for (int i = 0; i <= vnum; i++)
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
	int pre[10];
	for (int j = 0; j < 10; j++)
	{
		pre[j] = 0;
		all[j] = 0;
	}
	int cnt = 0;
	for (int i = 1; i <= vnum; i++)
	{
		dfs(i); //visited  1 1 1
		for (int i = 0; i < 10; i++)
		{
			if (visited[i] == 1 && pre[i] != visited[i])
			{
				cnt++;
				for (int j = 0; j < 10; j++)
				{
					pre[j] = visited[j];
					visited[j] = 0;
				}
				break;
			}
		}
	}
	printf("문제 1 : %d", cnt);


}
