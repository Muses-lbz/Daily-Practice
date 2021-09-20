#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int a, b, sum = 6;
	srand((unsigned)time(NULL));
	a = rand() % 100;
	while (1)
	{
		sum--;
		scanf_s("%d", &b);
		if (b > a)
			printf("大了，请继续\n");
		if (b < a)
			printf("小了，请继续\n");
		if (b == a)
		{
			printf("恭喜你答对了\n");
			break;
		}
		if (sum == 0)
		{
			printf("LOSE!");
			break;
		}
	}
	system("pause");
	return 0;
}
