#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[6][6];
	int m, n;
	int i, j;
	int max = 0;
	int indexx = 0, indexy = 0;
	scanf_s("%d %d", &m, &n);
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf_s("%d", &a[i][j]);
			if (i == 0 && j == 0)
			{
				max = a[i][j];
				indexx = 0;
				indexy = 0;
			}
			else
			{
				if (a[i][j] > max)
				{
					max = a[i][j];
					indexx = i;
					indexy = j;
				}
			}
		}
	}
	printf("%d,%d,%d\n", max, indexx, indexy);
	//PS:输出最大值及其所在位置的行列下标值
	system("pause");
	return 0;
}
