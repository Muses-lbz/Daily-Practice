#include <stdio.h>
#include <stdlib.h>

int main()
{
	int  a;
	scanf_s("%d", &a);
	if (a % 2 == 1)
	{
		printf("%d ", a + 1);
		printf("%d ", a + 2);
		printf("%d\n", a + 3);
	}
	else
	{
		printf("%d ", a - 1);
		printf("%d ", a - 2);
		printf("%d\n", a - 3);
	}
	system("pause");
	return 0;
}
