#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, a[1000] = { 0 };
    /*一个数组A中存有N（>0）个整数，在不允许使用另外数组的前提下，
    将每个整数循环向右移M（≥0）个位置（最后M个数循环移至最前面的M个位置）。*/
    scanf_s("%d %d", &n, &m);
    m = m % n;
    int count = m;
    while (m < n)
    {
        scanf_s("%d", &a[m]);
        m++;
    }
    for (int i = 0; i < count; i++)
        scanf_s("%d", &a[i]);//此处的scanf语句有什么用？？
    int first = 1;
    for (int i = 0; i < n; i++)
    {
        if (!first)
            printf(" ");
        printf("%d", a[i]);
        first = 0;
    }
    system("pause");
    return 0;
}
