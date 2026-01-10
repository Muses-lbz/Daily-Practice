//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int i = 0, j = 0, n;
//	cout << "请输入一系列数字" << endl;
//	cin >> n;
//	while (n != 0)
//	{
//		if (n > 0)
//		{
//			i++;
//		}
//		if (n < 0)
//		{
//			j++;
//		}
//		cin >> n;
//	}
//	cout << "正数个数" << i << endl;
//	cout << "负数个数" << j << endl;
//	return 0;
//}

//#include <stdlib.h>
//#include <stdio.h>
//
//int main()
//{
//    int id;
//    int a[3] = { 1,2,3 };
//    int au = 0;
//    while (1)
//    {
//        printf("1.剪刀,2.石头,3.布,0.退出\n");
//        scanf_s("%d", &id);
//        if (id == 0)
//            break;
//        au = a[rand() % 3];
//        if (au == 1)
//        {
//            printf("机器：剪刀\t");
//            if (id == 1)
//                printf("玩家:剪刀\t平局\n");
//            else if (id == 2)
//                printf("玩家:石头\t玩家赢\n");
//            else
//                printf("玩家:布\t机器赢\n");
//        }
//        else if (au == 2)
//        {
//            printf("机器：石头\t");
//            if (id == 1)
//                printf("玩家:剪刀\t机器赢\n");
//            else if (id == 2)
//                printf("玩家:石头\t平局\n");
//            else
//                printf("玩家:布\t玩家赢\n");
//        }
//        else
//        {
//            printf("机器：布\t");
//            if (id == 1)
//                printf("玩家:剪刀\t玩家赢\n");
//            else if (id == 2)
//                printf("玩家:石头\t机器赢\n");
//            else
//                printf("玩家:布\t平局\n");
//        }
//    }
//    return 0;
//}

//#include <iostream>
//#include <algorithm>
//#include <stdlib.h>
//using namespace std;
//#define n 10
////一个整数的序列，要求对其重新排序。排序要求:
////1.奇数在前，偶数在后；
////2.奇数按从大到小排序；
////3.偶数按从小到大排序。
////
////输入一行，包含整数个数n， n个整数值，彼此以一个空格分开。
////按照要求排序后输出一行，包含排序后的n个整数。
//bool cmp(int a, int b)
//{
//	int x = a % 2;
//	int y = b % 2;
//	if (x == y)
//		if (x == 0)
//			return a < b;
//		else
//			return a > b;
//	else
//		return x > y;
//}
//int main()
//{
//	int i;
//	int a[n];
//	for (i = 0; i < n; i++)
//		cin >> a[i];
//	sort(a, a + n, cmp);
//	for (i = 0; i < n; i++)
//		cout << a[i] << " ";
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
////一个正整数如果等于组成它的各位数字的阶乘之和，该整数称为阶乘和数。
////例如，145 = 1!+ 4!+ 5!，则145是一个三位阶乘和数。
////请输出所有阶乘数（不会超过十万）
//int b[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };//0-10的阶乘：0的阶乘为1
//
//int main() 
//{
//	int x, sum = 0, a, j;
//	for (j = 1; j <= 100000; j++)
//	{
//		sum = 0;
//		a = j;
//		while (j != 0)
//		{
//			x = j % 10;
//			j /= 10;
//			sum += b[x];
//		}
//		j = a;
//		if (sum == a) 
//		{
//			printf("%d ", j);
//		}
//	}
//	system("pause");
//	return 0;
//}

#include<iostream>
#include<string.h>
using namespace std;

int main(void)
{
    char* p = (char*)"abcba";
    int n = strlen(p);
    bool flag = 1;
    int i;
    for (i = 0; i < n / 2; i++)
    {
        cout << p[i] << "\t" << p[n - 1 - i] << endl;
        if (p[i] != p[n - 1 - i])
        {
            flag = 0;
            cout << "N" << endl; 
            break;
        }
    }
    if (flag == 1)
        cout << "Y" << endl;
    return 0;
}