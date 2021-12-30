#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int sum = 0;
	int M, N, i;
	int cnt = 0;
	int min = 10001;
	scanf("%d\n%d", &M, &N);
	for (int i = M; i <= N; i++)
	{
		for (int k = 2; k < i; k++)
		{
			if (i % k == 0)
			{
				cnt = 1;
			}	//63 % 2 0이 아니라서 if 문 통과하면안뎀
		}

		if (cnt == 0 && i != 1)
		{
			sum += i;
			if (i < min)
			{
				min = i;
			}
		}
		cnt = 0;
	}


	if (sum == 0)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n%d", sum, min);
	}
}
