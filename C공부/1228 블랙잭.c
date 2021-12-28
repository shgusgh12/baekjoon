#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num;
	int max;
	int sum;
	int answer=0;
	scanf("%d", &num);
	scanf("%d", &max);
	int cnt[100];
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &cnt[i]);
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = i+1; j < num; j++)
		{
			for (int k = j+1; k < num; k++)
			{
		 		sum = cnt[i] + cnt[j] + cnt[k];
				if (sum > answer && sum <= max)
				{
					answer = sum;
				}
			}
		}
	}

	printf("%d", answer);


}
	