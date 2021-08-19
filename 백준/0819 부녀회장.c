#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int T = 0;
	int k = 0;
	int n = 0;
	
	
	int arr[15][15] = { 0, };
	for (int i = 0; i < 15; i++)
	{
		arr[0][i] = i + 1;
		arr[i][0] = 1;
	}
	for (int a = 1; a < 15; a++) 
	{
		for (int b = 1; b < 15; b++) {
			arr[a][b] = arr[a][b - 1] + arr[a - 1][b];
		}
	}
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &k);
		scanf("%d", &n);
		printf("%d\n", arr[k][n-1]);
	}



	return 0;
}
