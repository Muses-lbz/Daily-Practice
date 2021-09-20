#include <stdio.h>
#include <stdlib.h>

int main()
{

	int a[10], i, t; 
	for (i = 0; i <= 9; i++)
		a[i] = 0; //初始化每个小房间为0
	for (i = 1; i <= 5; i++)
	{
		scanf_s("%d", &t); //依次读入5个数
		a[t]=1;         //把对应的小房间改为1
	}
	for (i = 0; i <= 9; i++)
		if (a[i] == 0)     //输出没有出现过的数
			printf("%d ", i);
	system("pause");
	return 0;
}
