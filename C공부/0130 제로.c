#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct _stack
{
	int arr[1000000];
	int topIndex;
}Stack;

void stackinit(Stack* pstack)
{
	pstack->topIndex = -1;
}

void push(Stack * pstack, int data)
{
	pstack->topIndex += 1;
	pstack->arr[pstack->topIndex] = data;
	
}

int pop(Stack* pstack)
{
	int rdx;

	rdx = pstack->topIndex;
	pstack->topIndex -= 1;

	return pstack->arr[rdx];
}

int sum(Stack* pstack)
{
	int i = pstack->topIndex;
	int answer = 0;
	while (i > -1)
	{
		answer += pstack->arr[i];
		i--;
	}
	return answer;
}

int main(void)
{
	int N;
	int K;
	scanf("%d", &N);
	Stack stack;
	stackinit(&stack);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &K);
		if (K == 0)
		{
			pop(&stack);
		}
		else
			push(&stack, K);
	}
	printf("%d", sum(&stack));
}
