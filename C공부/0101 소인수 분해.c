#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	int cnt = 0;
	int tmp = 0;
	int temp = 0;
	if (N == 1)
	{
		N = -1;
	}
	if (N == 2)
	{
		printf("%d", N);
		N = -1;
	}


	while (N > 0)
	{
		for (int i = 2; i < N; i++)
		{
			if (N % i == 0)
			{
				N /= i;
				printf("%d\n", i);
				
				if (N % i == 0)
				{
					break;
				}
				else
				{
					cnt = 1;
				}
			}
			else
			{
				tmp = 1;
			}
		}
		if (tmp == 1|| N==2)
		{
			printf("%d", N);
			break;
		}


	}
}
