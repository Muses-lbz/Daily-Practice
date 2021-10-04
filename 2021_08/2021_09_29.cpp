//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//
//int main()
//{
//	char str[50];
//	srand((unsigned int)time(NULL));
//	int seed = rand()%2;
//	if (seed == 0)
//	{
//		char str[50] = {"不要和愚蠢的人发生争执！" };
//	}
//	else
//	{
//		char str[50] = {};
//	}
//	printf("seed=%d\n", seed);
//	if (str == "不要和愚蠢的人发生争执！")
//	{
//		printf("你是聪明的！\n\n");
//	}
//	else
//	{
//		printf("你是愚笨的！\n\n");
//	}
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

int fun(int n, int* x, int* y)
{
    int sum = 0, i;
    int size = 0;
    int dd = 1;
    for (i = 1; i <= (*x); i++)
    {
        sum += (2 * i - 1);
    }
    if (sum == n)
    {
        *y = 2 * (*x) - 1;
        return (*x);
    }
    else if (sum > n)
    {
        (*y) = n - (sum - (2 * (*x) - 1));
        size = 2 * (*x) - 1;
        dd = (*x);
        for (i = 2; i <= (*y); i++)
        {
            if (i <= (*x))
                dd *= 2;
            else
                dd /= 2;
        }
        return dd;
    }
    else
    {
        (*x)++;
        return fun(n, x, y);
    }
}

int main()
{
    int n;
    int row = 1, col = 0;
    int val;
    row = 1;
    col = 0;
    printf("请输入n：");
    scanf_s("%d", &n);
    val = fun(n, &row, &col);
    printf("第%d项是：%d\n", n, val);
    system("pause");
    return 0;
}