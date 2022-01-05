#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	int x, y;
	int sum = 1;
	int sum1 = 1;
	scanf("%d %d", &x, &y);
	if (x > y)
	{
		for (int i = 2; i <= y; i++)
		{
			while (x % i == 0 && y % i == 0)
			{
				sum *= i;
				sum1 *= i;
				x /= i;
				y /= i;

			}
		}
		sum1 *= x;
		sum1 *= y;
	}
	else
	{
		for (int i = 2; i <= x; i++)
		{
			while (x % i == 0 && y % i == 0)
			{
				sum *= i;
				sum1 *= i;
				x /= i;
				y /= i;
			}
			
		}
		sum1 *= x;
		sum1 *= y;
	}
	printf("%d\n", sum);
	printf("%d", sum1);
	
	
}
