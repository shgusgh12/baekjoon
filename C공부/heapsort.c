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

void adjust(element a[], int root, int n)
{
	int child, rootkey;
	element temp;
	temp = a[root];
	rootkey = a[root].key;
	child = 2 * root;
	while (child <= n)
	{
		if ((child < n) && (a[child].key > a[child + 1].key))
			child++;
		if (rootkey < a[child].key)
			break;
		else
		{
			a[child / 2] = a[child];
			child *= 2;
		}
	}
	a[child / 2] = temp;
}

void heapSort(element a[], int n)
{
	int i, j;
	element temp;

	for (i = n / 2; i > 0; i--)
		adjust(a, i, n);
	for (i = n - 1; i > 0; i--)
	{
		temp = a[1];
		a[1] = a[i+1];
		a[i + 1] = temp;	
		adjust(a, 1, i);
	}
}

void P1()
{
	
	FILE* fp;
	fp = fopen("in23_2.txt", "r");
	int n;
	fscanf(fp, "%d", &n);
	for (int i = 1; i <= n; i++)
	{
		fscanf(fp, "%d", &a[i]);
	}
	heapSort(a, n);
	printf("문제 1: ");
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}


int main()
{
	
	P1();
}
