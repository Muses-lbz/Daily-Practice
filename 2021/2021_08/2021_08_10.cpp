#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x, y, z;
	scanf_s("%d %d %d", &x, &y, &z);
	if (x > y)
	{
		if (x > z)
			printf("%d", x);
		else
			printf("%d", z);
	}
	else
	{
		if (y > z)
			printf("%d", y);
		else
			printf("%d", z);
	}
	printf("\n");
	system("pause");
	return 0;
}

