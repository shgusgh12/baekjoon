#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int T = 0;
	int H = 0;
	int W = 0; 
	int N = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d %d", &H, &W, &N);
		if (N % H != 0)
		{
			printf("%d%02d\n", N % H, N / H + 1);
		}
		else
			printf("%d%02d\n", H, N/H);

	}
	return 0;
}
