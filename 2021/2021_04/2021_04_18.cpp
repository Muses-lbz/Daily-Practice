#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, count;
	count = 0;
	a = 5;
	if (a % 2 == 0)
		count++; if (a % 3 == 0)
		count++; if (a % 4 == 0)
		count++;
	if (count == 0)
		printf("质数\n");
	else
		printf("合数\n");
	system("pause");
	return 0;
}
