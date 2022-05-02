#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p,s) \
if ((p = malloc(s) == NULL)) {\
		fprintf(stderr, "Insufficient memory"); \
		exit(EXIT_FAILURE); \
}


int main()
{
	FILE* fp;
	fp = fopen("in.txt", "r");
	int n;
	int m;
	int M[6][6];
	for (int i = 1; i < 6; i++)
		for (int j = 1; j < 6; j++)
			M[i][j] = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%d %d", &n, &m);
		M[n][m] = 1;
		M[m][n] = 1;
	}
	for (int i = 1; i < 6; i++)
	{
		for (int j = 1; j < 6; j++)
		{
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
	printf("v1: ");
	for (int i = 1; i < 6; i++)
	{
		for (int j = 1; j < 6; j++)
		{
			if (M[i][j] == 1 && i==1)
			{
				printf("%d ", j);
			}
		}
	}
	printf("\nv2: ");
	for (int i = 1; i < 6; i++)
	{
		for (int j = 1; j < 6; j++)
		{
			if (M[i][j] == 1 && i == 2)
			{
				printf("%d ", j);
			}
		}
	}
	printf("\nv3: ");
	for (int i = 1; i < 6; i++)
	{
		for (int j = 1; j < 6; j++)
		{
			if (M[i][j] == 1 && i == 3)
			{
				printf("%d ", j);
			}
		}
	}
	printf("\nv4: ");
	for (int i = 1; i < 6; i++)
	{
		for (int j = 1; j < 6; j++)
		{
			if (M[i][j] == 1 && i == 4)
			{
				printf("%d ", j);
			}
		}
	}
	printf("\nv5: ");
	for (int i = 1; i < 6; i++)
	{
		for (int j = 1; j < 6; j++)
		{
			if (M[i][j] == 1 && i == 5)
			{
				printf("%d ", j);
			}
		}
	}

}