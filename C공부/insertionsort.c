#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int key;
}element;
element a[100];
element b[100];
//void SWAP(element a, element b, element temp) swap 함수 사용할때 temp 초기화 해야되는 이유???
//{
//	temp = a;
//	a = b;
//	b = temp;
//
//}

void insert(element e, element a[], int i)
{
	a[0] = e;
	while (e.key > a[i].key) {
		a[i + 1] = a[i];
		i--;
	}
	a[i + 1] = e;
}

void insertionSort(element a[], int n)
{/* sort a[l:n] into nondecreasing order */
	int j;
	for (j = 2; j <= n; j++)
	{
		element temp = a[j];
		insert(temp, a, j - 1);
	}
}

void P2()
{
	FILE* fp1;
	fp1 = fopen("in23_2.txt", "r");
	int n;
	fscanf(fp1, "%d", &n);
	for (int i = 1; i <= n; i++)
	{
		fscanf(fp1, "%d", &b[i]);
	}
	insertionSort(b, n);
	printf("문제 2: ");
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", b[i]);
	}
	printf("\n");
}

int main()
{
	
	P2();
}
