#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
int que[100000];
int front1 =0;
int back1 = 0;
int cnt;
int pop()
{
	if (empty() == 1)
		return -1;
	cnt = que[front1];
	front1++;
	return cnt;
}

int size()
{
	return back1 - front1 ;
}

int empty()
{
	if (size() == 0)
		return 1;
	else
		return 0;
}
int front()
{
	if (empty())
		return -1;
	return que[front1];
}
int back()
{
	if (empty())
		return -1;
	return que[back1-1];
}
void push(int num)
{
	que[back1] = num;
	back1++;
}
int main(void)
{
	int n;
	int num;
	scanf("%d", &n);
	char arr[100000];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", arr);
		if (strcmp(arr, "push")==0)
		{
			scanf("%d", &num);
			push(num);
		}
		else if (strcmp(arr, "front") == 0)
		{
			printf("%d\n", front());
		}
		else if (strcmp(arr, "back") == 0)
		{
			printf("%d\n", back());
		}
		else if (strcmp(arr, "pop") == 0)
		{
			printf("%d\n", pop());
		}
		else if (strcmp(arr, "empty") == 0)
		{
			printf("%d\n", empty());
		}
		else if (strcmp(arr, "size") == 0)
		{
			printf("%d\n", size());
		}
	}



}
	