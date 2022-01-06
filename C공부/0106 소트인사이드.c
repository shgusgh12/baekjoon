#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	int N;
	char str[10];
	gets(str);

	for (int i = 0; i < strlen(str); i++)
	{
		for (int j = i+1; j < strlen(str); j++)
		{
			if (str[i] < str[j])
			{
				int tmp;
				tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}
		}
		
	}
	puts(str);

}
