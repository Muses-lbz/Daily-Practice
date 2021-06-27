//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//int main()
//{
//	srand((unsigned int)time(NULL));
//	int m;
//	scanf_s("%d", &m);
//	if (m == 0)
//	{
//		printf("ERROR!\n");
//	}
//	else
//	{
//		int n = rand() % m;
//		printf("%d\n", n);
//		if (n % 7 == 0)
//		{
//			printf("WINNER!\n");
//		}
//		else
//		{
//			printf("CONTINUE!\n");
//		}
//	}
//
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	clock_t start_time, end_time;
	start_time = clock();   //获取开始执行时间

	int i, j, mul;
	for (i = 1; i <= 9; ++i)
	{
		for (j = 1; j <= 9; ++j)
		{
			mul = i * j;
			printf("%d\t", mul);
			if (j % 9 == 0)
			{
				printf("\n");
			}
		}
	}

	end_time = clock();     //获取结束时间
	double Times = ((double)end_time - (double)start_time) / CLOCKS_PER_SEC;
	printf("%f seconds\n", Times);

	system("pause");
	return 0;
}
