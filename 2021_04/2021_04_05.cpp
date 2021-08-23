#include <stdio.h> 
#include <stdlib.h> 

int main()
{
	int a, count, i;
	count = 0;
	scanf_s("%d", &a);
	for (i = 2; i <= a - 1; i++)
	{
		if (a % i == 0)
			count++;
	}
	if (count == 0)
	{
		printf("质数\n\n");
	}
	else
	{
		printf("合数\n\n");
	}
	system("pause");
	return 0;
}

