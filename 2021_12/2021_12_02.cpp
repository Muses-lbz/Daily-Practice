//#include <stdio.h>
//#include <stdlib.h>
//
//int print()
//{
//	int num = 0;
//	for (int a = 0; a <= 9; a++)
//	{
//		for (int b = 0; b <= 9; b++)
//		{
//			for (int c = 0; c <= 9; c++)
//				if (a != 0 && b != 0 && c != 0 && a + b + c == 6)
//				{
//					printf("%d%d%d\t", a, b, c);
//					num++;
//				}
//		}
//	}
//	printf("\n");
//	printf("这样的数字共有%d个。", num);
//	return 0;
//}
//
//int main()
//{
//	printf("这样的数字为:");
//	print();
//	printf("\n");
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	long long n;
//	int count = 0;
//	printf("输入一个整数: ");
//	scanf_s("%lld", &n);
//	while (n <= 0)
//	{
//		printf("错误！\n请重新输入一个数字：");
//		scanf_s("%lld", &n);
//	}
//	while (n > 0)
//	{
//		n /= 10;
//		++count;
//	}
//	printf("数字是 %d 位数。\n", count);
//	system("pause");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main() 
//{
//    double n, A, B;
//    cin >> n;
//    B = 12 * 0.7 * n;
//    if (n <= 10)
//    {
//        A = 10 * n;
//    }
//    else if (n > 10 && n <= 20)
//    {
//        A = (double)10 * 10 + (n - 10) * 8.2;
//    }
//    else 
//    {
//        A = 10 * 8.2 + (n - 20) * 7.5 + (double)10 * 10;
//    }
//    if (A < B) 
//    {
//        cout << "A " << A;
//    }
//    else
//    {
//        cout << "B " << B;
//    }
//    return 0;
//}

#include <stdio.h>
#include <iostream>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - i; j++) printf(" ");
        for (int j = 0; j < i; j++) printf("%c", (char)(j + 'A'));
        for (int j = i; j >= 0; j--) printf("%c", (char)(j + 'A'));
        printf("\n");
    }
    return 0;
}