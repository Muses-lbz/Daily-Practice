//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int i, sum = 1;
//	for (i = 1; i <= 10; i++)
//	{
//		sum = sum * i;
//	}
//	printf("%d\n", sum);
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int a, count;
//	count = 0;
//	a = 5;
//	if (a % 2 == 0)
//		count++; if (a % 3 == 0)
//		count++; if (a % 4 == 0)
//		count++;
//	if (count == 0)
//		printf("质数\n");
//	else
//		printf("合数\n");
//	system("pause");
//	return 0;
//}
//
//	

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int a, count, i;
//	count = 0;
//	a = 5;
//	for (i = 2; i <= 4; i++)
//	{
//		if (a % i == 0)
//			count++;
//	}
//	if (count == 0)
//		printf("质数\n");
//	else
//		printf("合数\n");
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int k, a, b, i, count1, count2;
//	for (k = 4; k <= 100; k = k + 2)
//	{
//		for (a = 2; a <= k / 2; a++)
//		{
//			//判断a是否为质数
//			count1 = 0;
//			for (i = 2; i <= a - 1; i++)
//			{
//				if (a % i == 0)
//				{
//					count1++;
//					continue;
//				}
//			}
//			if (count1 == 0) //如果a为质数
//			{
//				b = k - a;
//				//判断b是否为质数 
//				count2 = 0;
//				for (i = 2; i <= b - 1; i++)
//				{
//					if (b % i == 0)
//					{
//						count2++;
//						continue;
//					}
//				}
//				if (count2 == 0) //如果b也是质数
//				{
//					printf("%d=%d+%d\n", k, a, b); break; //打印这个解并跳出循环
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
//	int m,x,y,z;
//	for (m = 100; m <= 999; m++)
//	{
//		x = m / 100;
//		y = m / 10 % 10;
//		z = m % 100 % 10;
//		if (m == x * x * x + y * y * y + z * z * z)
//		{
//			printf("%d\n", m);
//			continue;
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
//	int i, j, k;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 0; j <= 9; j++)
//		{
//			for (k = 0; k <= 9; k++)
//			{
//				if (i * 100 + j * 10 + k == i * i * i + j * j * j + k * k * k)
//				{
//					printf("%d ", i * 100 + j * 10 + k);
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
//	int a, b, c, d, e; for (a = 0; a <= 9; a++)
//	{
//		for (b = 0; b <= 9; b++)
//		{
//			for (c = 0; c <= 9; c++)
//			{
//				for (d = 0; d <= 9; d++)
//				{
//					for (e = 0; e <= 9; e++)
//					{
//						if (a != b && a != c && a != d && a != e && b != c && b != d && b != e && c != d && c != e && d != e)
//						{
//							if ((a * 1000 + b * 100 + c * 10 + d) * e ==
//								(d * 1000 + c * 100 + b * 10 + a))
//							{
//								printf("%d%d%d%d\n", a, b, c, d);
//								printf("*  %d\n", e);
//								printf("----\n");
//								printf("%d%d%d%d\n", d, c, b, a);
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
//    int n = 0, i;
//    for (i = 1; i <= 200; i++)
//    {
//        if ((i % 2 == 1) && (i % 3 == 1) && (i % 5 == 1))
//        {
//            n++;
//            if (n < 10)
//                printf("%d ", i);
//            if (n == 10)
//                break;
//        }
//    }
//    system("pause");
//    return 0;
//}

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
	int result[12] = { 0 };
	int gold;
	while (cin >> gold)
	{
		if (gold < 0)
		{
			break;
		}
		int code = gold / 10;
		if (code < 4)
		{
			result[3] ++;
		}
		else if (code == 10)
		{
			result[9] ++;
		}
		else
		{
			result[code] ++;
		}
	}
	string word[] = { "0~39", "40~49", "50~59","60~69","70~79", "80~89","90~100" };
	for (int i = 0; i < 7; i++)
	{
		cout << word[i] << " " << result[i + 3] << endl;
	}
	system("pause");
	return 0;
}