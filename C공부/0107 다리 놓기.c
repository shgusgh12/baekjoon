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
	int N, M;
	
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d", &N, &M);
		printf("%.lf\n", fact(M) / (fact(M - N) * fact(N)));
		
		
	}
}
