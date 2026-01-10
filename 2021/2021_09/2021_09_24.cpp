//#include <iostream>
//#include <string>
//using namespace std;
//
//string a[105];
//int b[105], c[105];
//
//int qiujishu(string x)
//{
//	int jishu = 0;
//	for (int i = 0; x.c_str()[i]; i++)
//	{
//		if ((x.c_str()[i] - '0') % 2 == 1) jishu++;
//	}
//	return jishu;
//}
//int qiuoushu(string x)
//{
//	int oushu = 0;
//	for (int i = 0; x.c_str()[i]; i++)
//	{
//		if ((x.c_str()[i] - '0') % 2 == 0) oushu++;
//	}
//	return oushu;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//		b[i] = qiujishu(a[i]);
//		c[i] = qiuoushu(a[i]);
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		cout << b[i] << " " << c[i] << endl;
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main() 
//{
//    int i, max = 0, min = 0;
//    double sum = 0, ave = 0;
//    int a[10];
//    for (i = 0; i < 10; i++)
//    {
//        scanf_s("%d", &a[i]);
//        if (i >= 0)
//            min = a[i];
//        sum += a[i];
//        if (max >= a[i])
//            max = a[i];
//        if (min > a[i])
//            min = a[i];
//    }
//    ave = sum / 10;
//    for (i = 0; i < 5; i++)
//        printf("%d ", a[i]);
//    printf("\n");
//    for (i = 5; i < 10; i++)
//        printf("%d ", a[i]);
//    printf("\n平均成绩%f,最高分%d,最低分%d\n", ave, max, min);
//    system("pause");
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//    int n, m, a[1000] = { 0 };
//    /*一个数组A中存有N（>0）个整数，在不允许使用另外数组的前提下，
//    将每个整数循环向右移M（≥0）个位置（最后M个数循环移至最前面的M个位置）。*/
//    scanf_s("%d %d", &n, &m);
//    m = m % n;
//    int count = m;
//    while (m < n)
//    {
//        scanf_s("%d", &a[m]);
//        m++;
//    }
//    for (int i = 0; i < count; i++)
//        scanf_s("%d", &a[i]);//此处的scanf语句有什么用？？
//    int first = 1;
//    for (int i = 0; i < n; i++)
//    {
//        if (!first)
//            printf(" ");
//        printf("%d", a[i]);
//        first = 0;
//    }
//    system("pause");
//    return 0;
//}

//#include <stdio.h> 
//#include <stdlib.h>
//void butler(void); /* ANSI/ISO C 函数原型 */
//
//int  main(void)
//{
//	printf("I  will  summon  the  butler function.\n");
//	butler();
//	printf("Yes.  Bring  me  some  tea  and  writable DVDs.\n");
//	system("pause");
//	return  0;
//}
//void butler(void)
////函数定义开始 
//{
//	printf("You  rang, sir ? \n");
//}

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, k, count = 1;
	long long c;
	cin >> n;
	while (n--)
	{
		cin >> k >> c;
		int num = k;
		long long sum = k;
		for (long long i = 2; i <= c; i = sum / k + 1)
		{
			int t = num;
			num += (double)ceil((k * i - sum) * 1.0 / i);
			sum += i * ((double)num - t);
		}
		cout << "Case #" << count++ << ": " << num << endl;
	}
	return 0;
}