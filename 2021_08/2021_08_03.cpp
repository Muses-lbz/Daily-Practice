#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

int oneNum(int x)
{
    int cnt = 0;
    while (x)
    {
        cnt++;
        x = x & (x - 1);
    }
    return cnt;
}

int cmp(const void* a, const void* b)
{
    int al, bl;
    int ret;
    al = *(int*)a;
    bl = *(int*)b;
    ret = oneNum(al) - oneNum(bl);
    return  ret ? ret : al - bl;
}

int main()
{
    int s[] = { 1,2,3,5,6,7,8 }, i;
    int len = sizeof(s) / sizeof(*s);
    qsort(s, len, 4, cmp);
    for (i = 0; i < len; i++)
    {
        printf("%d\n", s[i]);
    }
    system("pause");
    return 0;
}
