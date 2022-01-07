#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>

double fact(int r)
{
	if (r == 0)
		return 1;
	
	return r* fact(r-1);
}

int main()
{
	int T;
	int A, B;
	int max = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d", &A, &B);
		if (A > B)
		{
			for (int j = 1; j <= B; j++)
			{
				if (A % j == 0 && B % j == 0)
				{
					if (j > max)
					{
						max = j;
					}
				}
			}
		}
		else
		{
			for (int j = 1; j <= A; j++)
			{
				if (A % j == 0 && B % j == 0)
				{
					if (j > max)
					{
						max = j;
					}
				}
			}
		}
		printf("%d\n", A * B / max );
		max = 1;
		
	}
}
