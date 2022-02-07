#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char stack[1000];
int topidx = 0;


void push(char data)
{
	stack[++topidx] = data;
}


char top()
{
	return stack[topidx];
}

char pop()
{
	int rdx;
	rdx = topidx;
	topidx -= 1;

	return stack[rdx];

}



int main(void)
{
	
	char K[100];
	
	
	while (1)
	{
		int cnt = 0;
		gets(K);
		if (strcmp(K, ".") == 0)
		{
			break;
		}
		for (int i = 0; i < strlen(K); i++)
		{
			if (K[i] == '(' || K[i] == ')'||K[i]=='['||K[i]==']')
			{
				if (topidx == 0)
				{
					push(K[i]);
				}
				else
				{
					if (K[i] == ')' && top() == '(')
					{
						pop();
					}
					else if (K[i] == ']' && top() == '[')
						pop();
					else
						push(K[i]);
				}
			}
		}	
		if (topidx == 0)
			printf("yes\n");
		else
			printf("no\n");

		topidx = 0;
	}

	
}
