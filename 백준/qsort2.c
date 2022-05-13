#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
long arr[1000000];

int compare(const void* a, const void* b)
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;
	if (num1 < num2)
		return -1;
	if (num1 > num2)
		return 1;
	return 0;
}

int main()
{
	
	int N;
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	qsort(arr, N, sizeof(long), compare);


	for (int i = 0; i < N; i++)
	{
		printf("%d\n", arr[i]);
	}
	
	

}