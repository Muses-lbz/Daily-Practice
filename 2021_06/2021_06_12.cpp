#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[5], i;
	for (i = 0; i <= 4; i++)
	{
		scanf_s("%d", &a[i]);
	}
	for (i = 4; i >= 0; i--)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}
