#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int stack[100000];
int topidx = -1;


void push(int data)
{
	stack[++topidx] = data;
	
}


int top()

{
	return stack[topidx];
}

int pop()
{
	int rdx;
	rdx = topidx;
	topidx -= 1;

	
	return stack[rdx];

}



int main(void)
{
	int N;
	int K[100000];
	scanf("%d", &N);
	char arr[100000];

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &K[i]);
	}
	int i = 0;
	int num = 1;
	int j = 0;
	while (1)
	{
		if (topidx == -1 || top() < K[i])
		{
			push(num);
			arr[j++] = '+';
			num++;
		}
		else if (top() == K[i])
		{
			pop();
			arr[j++] = '-';
			i++;
		}
		else
		{
			printf("NO\n");
			return 0;
		}
		if (N * 2==j)
		{
			break;
		}
	}

	for (int i = 0; i < j; i++)
	{
		printf("%c\n", arr[i]);
	}
	
		
		


	
}
