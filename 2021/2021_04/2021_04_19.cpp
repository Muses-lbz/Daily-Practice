#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, count, i;
	count = 0;
	a = 5;
	for (i = 2; i <= 4; i++)
	{
		if (a % i == 0)
			count++;
	}
	if (count == 0)
		printf("质数\n");
	else
		printf("合数\n");
	system("pause");
	return 0;
}
