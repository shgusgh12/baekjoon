#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int division(int key, int b, int i)
{
	return (key+i) % b;
}

int main()
{
	int num = 0;
	int key;
	int b, s;
	FILE* fp;
	fp = fopen("in22_2.txt", "r");
	fscanf(fp, "%d %d", &b, &s);
	int** arr = malloc(sizeof(int*) * b);
	int** cnt = malloc(sizeof(int*) * b);
	for (int i = 0; i < b; i++)
	{
		arr[i] = malloc(sizeof(int) * s);
		cnt[i] = malloc(sizeof(int) * s);
	}
	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < s; j++)
		{
			arr[i][j] = 0;
			cnt[i][j] = 0;
		}
	}
	
	while (!feof(fp))
	{
		int i = 0;
		fscanf(fp, "%d", &key);
		for (int k = 0; k < s; k++)
		{
			if (cnt[division(key, b, i)][k] == 0)
			{
				arr[division(key, b, i)][k] = key;
				cnt[division(key, b, i)][k] = 1;
				break;
			}
			if( cnt[division(key, b, i)][s-1]!=0)
			{
				i++;
				continue;
			}
		}

	}
	printf("Hash table\n");
	for (int i = 0; i < b; i++)
	{
		printf("%d: ", i);
		for (int j = 0; j < s; j++)
		{
			if (arr[i][j] != 0)
			{
				printf("%d ", arr[i][j]);
			}
		}
		printf("\n");
	}
	while (1)
	{
		int c = 0;
		int a = -1;
		scanf("%d", &num);
		if (num == -999)
		{
			break;
		}
		for (int i = 0; i < b; i++)
		{
			for (int j = 0; j < s; j++)
			{
				if (num == arr[i][j])
				{
					a = i;
					break;
				}
			}
		}	
		if (a == -1)
			printf("-1\n");
		else
			printf("%d\n", a);
	}

}
