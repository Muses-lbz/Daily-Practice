#include <stdio.h>
#include <stdlib.h>

double fun(int n)
{
    double sum = 1.0;
    int i;
    for (i = 1; i < n; i++)
        sum *= i;
    return sum;
}
int main()
{
    int i, mark = 1;
    double sum = 0, item = 1;
    for (i = 1; i <= 10; i++)
    {
        item = mark * fun(i);
        sum += item;
        mark = -mark;
    }
    printf("1!-2!+3!-4!+5!-6!+7!-8!+9!-10!=%.0lf\n", sum);
    system("pause");
    return 0;
}
