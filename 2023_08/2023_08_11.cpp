//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int a, b, c;
//	printf("请输入三个数字：");
//	scanf_s("%d %d %d", &a, &b, &c);
//	if (a > b)
//	{
//		if (a > c)
//		{
//			if (b > c)
//			{
//				printf("输出结果为：%d %d %d", a, b, c);
//			}
//			else
//			{
//				printf("输出结果为：%d %d %d", a, c, b);
//			}
//		}
//		else
//		{
//			printf("输出结果为：%d %d %d", c, a, b);
//		}
//	}
//	else
//	{
//		if (b > c)
//		{
//			if (a > c)
//			{
//				printf("输出结果为：%d %d %d", b, a, c);
//			}
//			else
//			{
//				printf("输出结果为：%d %d %d", b, c, a);
//			}
//		}
//		else
//		{
//			printf("输出结果为：%d %d %d", c, b, a);
//		}
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//    int i;
//    for (i = 1; i <= 100; i++)
//    {
//        if (i % 3 == 0)
//        {
//            printf("%d ", i);
//        }
//    }
//    printf("\n");
//    system("pause");
//    return 0;
//}

//#include <stdio.h>
//
//int main() {
//    int num1, num2, num3;
//
//    // 输入三个整数
//    printf("输入第一个整数: ");
//    scanf_s("%d", &num1);
//    printf("输入第二个整数: ");
//    scanf_s("%d", &num2);
//    printf("输入第三个整数: ");
//    scanf_s("%d", &num3);
//
//    // 排序（冒泡排序）
//    if (num1 < num2) {
//        int temp = num1;
//        num1 = num2;
//        num2 = temp;
//    }
//    if (num2 < num3) {
//        int temp = num2;
//        num2 = num3;
//        num3 = temp;
//    }
//    if (num1 < num2) {
//        int temp = num1;
//        num1 = num2;
//        num2 = temp;
//    }
//
//    // 输出排序后的结果
//    printf("从大到小排序: %d %d %d\n", num1, num2, num3);
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int numbers[10] = { 0 };
//	int max;
//	printf("请输入 10 个整数：\n");
//	for (int i = 0; i < 10; i++)
//	{
//		scanf_s("%d", &numbers[i]);
//	}
//	max = numbers[0];
//	for (int i = 1; i < 10; i++)
//	{
//		if (numbers[i] > max)
//		{
//			max = numbers[i];
//		}
//	}
//	printf("最大值为：%d\n", max);
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main() 
//{
//    printf("100~200之间的素数：\n");
//    for (int num = 100; num <= 200; num++) 
//    {
//        int is_prime = 1; 
//        for (int i = 2; i * i <= num; i++) 
//        {
//            if (num % i == 0) 
//            {
//                is_prime = 0; 
//                break;
//            }
//        }
//        if (is_prime)
//        {
//            printf("%d ", num);
//        }
//    }
//    printf("\n");
//    system("pause");
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//    for (int year = 1000; year <= 2000; year++)
//    {
//        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
//        {
//            printf("%d ", year);
//        }
//    }
//    printf("\n");
//    system("pause");
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//    float sum = 0.0, sum1 = 0.0, sum2 = 0.0;
//    for (int i = 1; i <= 100; i++)
//    {
//        if (i % 2 == 1)
//        {
//            sum1 += 1.0 / i;
//        }
//        else
//        {
//            sum2 -= 1.0 / i;
//        }
//    }
//    sum = sum1 + sum2;
//    printf("结果为：%f", sum);
//    printf("\n");
//    system("pause");
//    return 0;
//}

//#include <stdio.h>
//int main() {
//	int x = 3;
//	int y = 3;
//	switch (x % 2) {
//	case 1:
//		switch (y)
//		{
//		case 0:
//			printf("first");
//		case 1:
//			printf("second");
//			break;
//		default: printf("hello");
//		}
//		break;
//	case 2:
//		printf("third");
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 0, b = 0;
//	for (a = 1, b = 1; a <= 100; a++)
//	{
//		if (b >= 20) break;
//		if (b % 3 == 1)
//		{
//			b = b + 3;
//			continue;
//		}
//		b = b - 5;
//		printf("%d ", b);
//	}
//	printf("\n%d %d", a, b);
//	int c;
//	c = 1 % 3;
//	printf("%d", c);
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    int num1, num2;
    printf("请输入两个整数：\n");
    scanf_s("%d %d", &num1, &num2);
    int result = gcd(num1, num2);
    printf("最大公约数：%d\n", result);
    system("pause");
    return 0;
}
