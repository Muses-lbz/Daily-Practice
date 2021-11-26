// 顺序搜索算法（专业外语大作业）

#include <stdio.h>
#include <stdlib.h>

#define N 10     //数据集中的元素个数
//实现顺序查找，arr[N] 为数据集，value 为要查找的目标元素
int linear_search(int arr[N], int value)
{
    int i;
    //从第 1 个元素开始遍历
    for (i = 0; i < N; i++)
    {
        //匹配成功，返回元素所处的位置下标
        if (arr[i] == value) 
        {
            return i;
        }
    }
    //匹配失败，返回 -1
    return -1;
}

int main()
{
    int arr[N] = { 10,14,19,26,27,31,33,35,42,44 };
    int add = linear_search(arr, 33);
    if (add != -1) 
    {
        printf("查找成功，为序列中第 %d 个元素\n", add + 1);
    }
    else 
    {
        printf("查找失败\n");
    }
    system("pause");
    return 0;
}