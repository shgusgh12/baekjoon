#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	int N;
	int arr[50];
	int max = 0;
	int min = 1000000;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	

	for (int i = 0; i < N; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		if (min > arr[i])
		{
			min = arr[i];
		}
	}
	int sum = max * min;
	printf("%d", sum);
	
}
