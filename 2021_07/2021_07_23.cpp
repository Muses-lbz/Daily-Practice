#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int i, max = 0, min = 0;
    double sum = 0, ave = 0;
    int a[10];
    for (i = 0; i < 10; i++)
    {
        scanf_s("%d", &a[i]);
        if (i >= 0)
            min = a[i];
        sum += a[i];
        if (max >= a[i])
            max = a[i];
        if (min > a[i])
            min = a[i];
    }
    ave = sum / 10;
    for (i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\n");
    for (i = 5; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n平均成绩%f,最高分%d,最低分%d\n", ave, max, min);
    system("pause");
    return 0;
}

