#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 1;
	while (i <= 10)
	{
		int j = 1;
		while (j <= i)
		{
			printf("OK ");
			j = j + 1;
		}
		i = i + 1;
	}
	system("pause");
	return 0;
}
