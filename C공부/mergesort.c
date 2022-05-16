#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef struct {
	int key;
}element;
void mergePass(element initList[], element mergeList[], int n, int s);
void mergeSort(element a[], int n);
void merge(element initList[], element mergedList[], int i, int m, int n);

void merge(element initList[], element mergedList[], int i, int m, int n)
{ /* the sorted lists initList[i:m] and initList[m+l:n] are merged to obtain
the sorted list mergedList[i:n] */
	int j, k, t;
	j = m + 1; /* index for the second sublist */
	k = i; /* index for the merged list */
	while (i <= m && j <= n) {
		if (initList[i].key > initList[j].key)
			mergedList[k++] = initList[i++];
		else
			mergedList[k++] = initList[j++];
	}
	if (i > m) /* mergedList[k:n] = initList[j:n] */
		for (t = j; t <= n; t++)
			mergedList[t] = initList[t];
	else /* mergedList[k:n] = initList[i:m] */
		for (t = i; t <= m; t++)
			mergedList[k + t - i] = initList[t];
}
void mergePass(element initList[], element mergedList[], int n, int s)
{
	int i, j;
	for (i = 0;i <= n - 2 * s + 1;i += 2 * s)
		merge(initList, mergedList, i, i + s - 1, i + 2 * s - 1);
	if (i + s - 1 < n)
		merge(initList, mergedList, i, i + s - 1, n);
	else
		for (j = i;j <= n;j++)
			mergedList[j] = initList[j];
}

void mergeSort(element a[], int n)
{
	int s = 1;
	element extra[MAX_SIZE];
	while (s < n)
	{
		mergePass(a, extra, n, s);
		s *= 2;
		mergePass(extra, a, n, s);
		s *= 2;
	}
}

int main()
{
	FILE* fp;
	FILE* fp1;
	fp = fopen("in.txt", "r");
	fp1 = fopen("out.txt", "w");
	element b[100];
	int c = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%c\n", &b[c]);
		c++;
	}
	mergeSort(b, c);
	for (int i = 1;i <= c;i++)
	{
		fprintf(fp1, "%c\n", b[i]);
	}
}