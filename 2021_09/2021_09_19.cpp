//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int a, b, c, d, e, f;
//	int i = 1;
//	for (a = 1; a < 7; a++)
//	{
//		for (b = 1; b < 7; b++)
//		{
//			for (c = 1; c < 7; c++)
//			{
//				for (d = 1; d < 7; d++)
//				{
//					for (e = 1; e < 7; e++)
//					{
//						for (f = 1; f < 7; f++)
//						{
//							if (a != b && a != c && a != d && a != e && a != f && b != c && b != d && b != e && b != f && c != d && c != e && c != f && d != e && d != f && e != f)
//							{
//								if (a + b + d == a + c + f && a + c + f == d + e + f)
//								{
//									printf("第%2d种情况：%d %d %d %d %d %d\n", i, a, b, c, d, e, f);
//									i++;
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int i = 1;
//	int k = 0;
//	while (i <= 10)
//	{
//		int j = 1;
//		while (j <= i)
//		{
//			printf("OK\t");
//			j = j + 1;
//			k = k + 1;
//			if (k % 11 == 0)
//				printf("\n");
//		}
//		i = i + 1;
//	}
//	printf("一共有%d个OK输出\n\n", k);
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
	for (int a = 2; a >= 0; a--)
	{
		for (int b = 60; b >= 0; b--)
		{
			system("cls");//清屏命令
			if (a == 2)
			{
				printf("%d:00", a);
				Sleep(500);
				a = a - 1;
			}
			else if (a == 0 && b == 60)
			{
				continue;
			}
			else if ((b <= 9 && b >= 0) && (a == 1 || a == 0))
			{
				printf("%d:0%d", a, b);
				Sleep(500);
			}
			else
			{
				printf("%d:%d", a, b);
				Sleep(500);
			}
		}
	}
	system("cls");
	printf("点火！\n");
	system("pause");
	return 0;
}
