#include <stdio.h>
#include <stdlib.h>

int main()
{
	int h, a[10], i, sum; for (i = 0; i <= 9; i++)
		scanf_s("%d", &a[i]);
	scanf_s("%d", &h); sum = 0;
	for (i = 0; i <= 9; i++)
	{
		if (a[i] <= h + 30)
			sum++;
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}
