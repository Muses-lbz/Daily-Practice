#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* a, n;
	scanf_s("%d", &n);
	a = (int*)malloc(sizeof(int) * n);
	if (a == NULL)
	{
		printf("内存分配不成功！\n");
	}
	else
	{
		for (int i = 0; i <= n - 1; i++)
		{
			scanf_s("%d", a);
		}
	}
	if (a != NULL)
	{
		for (int i = 0; i <= n - 1; i++)
		{
			printf("num:%d", *a);
		}
	}

	system("pause");
	return 0;
}

