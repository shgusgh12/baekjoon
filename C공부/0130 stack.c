#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct _stack
{
	int arr[1000];
	int topIndex;
}Stack;

int cnt = 0;

int stackisempty(Stack* pstack)
{
	if (pstack->topIndex == -1)
	{
		return 1;
	}
	else
		return 0;
}

void stackinit(Stack* pstack)
{
	pstack->topIndex = -1;
}

void push(Stack * pstack, int data)
{
	pstack->topIndex += 1;
	pstack->arr[pstack->topIndex] = data;
	cnt++;
}

int pop(Stack* pstack)
{
	int rdx;
	if (pstack->topIndex == -1)
	{
		return -1;
	}

	rdx = pstack->topIndex;
	pstack->topIndex -= 1;

	cnt--;
	return pstack->arr[rdx];
}



int top(Stack* pstack)
{
	if (pstack->topIndex == -1)
		return -1;
	return pstack->arr[pstack->topIndex];
}


int size()
{
	if (cnt <= 0)
	{
		return 0;
	}
	else
		return cnt;
	
}

int main(void)
{
	int N;
	char arr1[10];
	scanf("%d", &N);
	Stack stack;
	stackinit(&stack);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", arr1);
		if (strcmp(arr1, "push")==0)
		{
			int num;
			scanf("%d", &num);
			push(&stack, num);
		}
		else if (strcmp(arr1, "pop") == 0)
		{
			printf("%d\n",pop(&stack));
		}
		else if (strcmp(arr1, "top") == 0)
		{
			printf("%d\n",top(&stack));
		}
		else if (strcmp(arr1, "size") == 0)
		{
			printf("%d\n",size());
		}
		else if (strcmp(arr1, "empty") == 0)
		{
			printf("%d\n",stackisempty(&stack));
		}
	}

}
