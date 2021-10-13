#include <stdio.h>
#include <malloc.h>

int main()
{
	int* p = (int*)malloc(40);
	//开辟内存空间
	if (p == NULL)//开辟失败
	{
		return -1;
	}
	for (int i = 0; i < 10; i++)
	{
		*(p + i) = i;
	}
	free(p);
	//释放内存空间
	return 0;
}
