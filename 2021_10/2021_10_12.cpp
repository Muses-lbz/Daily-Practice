//#include <stdio.h>
//#include <stdlib.h>
//
//void Sortfun(double a[], int n)
//{
//    int i, j;
//    double tmp;
//    for (i = 0; i < n - 1; i++)
//    {
//        for (j = 0; j < n - 1 - i; j++)
//        {
//            if (a[j] > a[j + 1])
//            {
//                tmp = a[j];
//                a[j] = a[j + 1];
//                a[j + 1] = tmp;
//            }
//        }
//    }
//}
//
//int main()
//{
//    int i;
//    double a[10];
//    printf("请输入10个数:");
//    for (i = 0; i < 10; i++)
//        scanf_s("%lf", &a[i]);
//    printf("原顺序:\n");
//    for (i = 0; i < 10; i++)
//        printf("%g ", a[i]);
//    printf("\n");
//    Sortfun(a, 10);
//    printf("排序后:\n");
//    for (i = 0; i < 10; i++)
//        printf("%g ", a[i]);
//    printf("\n");
//    system("pause");
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int m, n;
    scanf_s("%d %d", &n, &m);
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            /*printf("%c", 65 + abs(i - j));*/
            printf("%d", abs(i - j));
        }
        printf("\n");
    }
    system("pause");
    return 0;
}