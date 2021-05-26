#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arr1[1000];


int result(int a) {
	int k = 0;
	if (a <= 10) {
		k = a;
	}
	if (a < 100) {
		k = a;
	}
	if (a % 100 % 10 - a % 100 / 10 == a % 100 / 10 - a / 100) {
		k = a;
	}
	return k;
}

int main(void) {
	int x;
	int cnt = 0;
	scanf("%d", &x);
	for (int i = 0; i < 1000; i++) {
		arr1[i] = 0;
	}
	for (int j = 1; j <= 1000; j++) {
		arr1[result(j)] = 1;
	}

	for (int i = 1; i <= x; i++) {
		if (arr1[i] == 1) {
			cnt++;
		}
	}
	printf("%d", cnt);
}

