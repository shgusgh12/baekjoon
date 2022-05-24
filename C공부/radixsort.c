#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int arr1[1002];
int arr2[1002];
int m;
int radixSort(int a[], int link[], int d, int r, int n)
{
    int front[10], rear[10];
    int i, bin, current, first, last;

    first = 1;
    for (i = 1; i < n; i++)
        link[i] = i + 1;
    link[n] = 0;

    for (i = d - 1; i >= 0; i--)
    {
        for (bin = 0; bin < r; bin++)
            front[bin] = 0; //front 초기화
        for (current = first; current; current = link[current])
        {
            int t = (int)pow(10, (d - i));
            bin = a[current] % (t);   //1의자리수 bin에 저장
            for (int k = 1; k < d - i; k++) bin = bin / 10;
            if (front[bin] == 0)
                front[bin] = current;
            else
                link[rear[bin]] = current;
            rear[bin] = current;
        }
        for (bin = 0; !front[bin]; bin++);
        first = front[bin];
        last = rear[bin];

        for (bin++; bin < r; bin++)
        {
            if (front[bin])
            {
                link[last] = front[bin];
                last = rear[bin];
            }
        }
        link[last] = 0;
    }
    return first;
}
int main() {
    FILE* fp;
    fp = fopen("in.txt","r");
    int n, cnt = 1;
    while (!feof(fp))
    {
        fscanf(fp, "%04d\n", &m);
        arr1[cnt++] = m;  //cnt ==7
    }
    n = cnt - 1;

    int i = radixSort(arr1, arr2, 4, 8, n);
    while (i != 0) {
        printf("%04d\n", arr1[i]);
        i = arr2[i];
    }
    fclose(fp);
    return 0;
}