#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	int cnt = 0;
	int tmp = 0;
	
	for (int i= 2; i <= N; i++)
	{
		while (N % i == 0)
		{
			printf("%d\n", i);
			N /= i;
		}
	}
}
