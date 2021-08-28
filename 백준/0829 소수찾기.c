#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



int main(void)
{
	int N = 0;
	int cnt = 0;
	int n = 0;
	int a;
	scanf("%d", &N);

	for (int j = 0; j < N; j++)
	{
		
		scanf("%d", &n);
		a = 0;
		if (n == 1)
			continue;

		for (int i = 2; i < n; i++) {
			if (n % i == 0)
				a = 1;
		}
		if (a == 0)
			cnt++;
	}
	printf("%d", cnt);
	return 0;
}
