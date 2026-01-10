#include <stdio.h>
#include <stdlib.h>
//用有序表表示静态查找表时，通常检索函数可以用折半查找来实现。
//折半查找的查找过程是：首先确定待查记录所在的范围，然后逐步缩小范围直到找到或者确定找不到相应的记录为止。
//而每次需要缩小的范围均为上一次的一半，这样的查找过程可以被称为折半查找。
//第二行包含n个用空格隔开的正整数，表示n个有序的整数。输入保证这n个整数是从小到大递增的。
//第三行包含k个用空格隔开的正整数，表示k次查询的目标。
//输出：
//只有1行，包含k个整数，分别表示每一次的查询结果。如果在查询中找到了对应的整数，则输出其相应的位置，否则输出 - 1。
//请在每个整数后输出一个空格，并请注意行尾输出换行。
int binary(int* a, int key, int n)
{
    int left = 0, right = n - 1, mid = 0;
    mid = (left + right) / 2;
    while (left < right && a[mid] != key)
    {
        if (a[mid] < key)
            left = mid + 1;
        else if (a[mid] > key)
            right = mid - 1;
        mid = (left + right) / 2;
    }
    if (a[mid] == key)   return mid;
    return -1;
}

int main()
{
	int Base_a[20] = { 1,3,5,8,9,40,120,123,125,150,199,200,1250,1255,1900,2000,2001,3000,3950,5000 };
	int Search_a[5] = { 12,199,9,2001,3500 };
	int result = 0x00;
	for (int i = 0; i < sizeof(Search_a) / sizeof(Search_a[0]); i++)
	{
		result = binary(Base_a, Search_a[i], sizeof(Base_a) / sizeof(Base_a[0]));
		printf("[%d %d] ", Search_a[i], result);
	}
	printf("\n");
	system("pause");
	return 0;
}
