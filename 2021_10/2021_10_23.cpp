//#include <stdio.h>
//#include <stdlib.h>
//
//int imin(int, int);
//
//int main()
//{
//	int  evil1, evil2;
//	printf("Enter a pair of integers (q to quit):\n");
//	while (scanf_s("%d %d", &evil1, &evil2) == 2)
//	{
//		printf("The lesser of %d and %d is %d.\n", evil1, evil2, imin(evil1, evil2));
//		printf("Enter a pair of integers (q to quit):\n");
//	}
//	printf("Bye.\n");
//	system("pause");
//	return 0;
//}
//
//int  imin(int n, int m)
//{
//	int min;
//	if (n < m)
//		min = n;
//	else
//		min = m;
//	return  min;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//void up_and_down(int);
//
//int main()
//{
//	up_and_down(1);
//	/*printf("1\n\n");*/
//	system("pause");
//	return  0;
//}
//
//void up_and_down(int n)
//{
//	printf("Level %d: n location %p\n", n, &n);  // #1 
//	/*printf("2\n\n");*/
//	if (n < 4)
//	{
//		up_and_down(n + 1);
//		/*printf("3\n\n");*/
//	}
//	printf("LEVEL %d: n location %p\n", n, &n);  // #2
//	/*printf("4\n\n");*/
//}

//#include <stdio.h> 
//#include <stdlib.h>
//
//long fact(int n);
//long rfact(int n);
//
//int main()
//{
//	int num;
//	printf("This program calculates factorials.\n");
//	printf("Enter a value in the range 0-12 (q to quit):\n");
//	while (scanf_s("%d", &num) == 1)
//	{
//		if (num < 0)
//			printf("No negative numbers, please.\n");
//		else if (num > 12)
//			printf("Keep input under 13.\n");
//		else
//		{
//			printf("loop: %d factorial = %ld\n", num, fact(num));
//			printf("recursion: %dfactorial = %ld\n", num, rfact(num));
//		}
//		printf("Enter a value in the range 0-12 (q to quit):\n");
//	}
//	printf("Bye.\n");
//	system("pause");
//	return 0;
//}
//
//long fact(int n)    // 使用循环的函数
//{
//	long ans;
//	for (ans = 1; n > 1; n--)
//		ans *= n;
//	return  ans;
//}
//
//long rfact(int n)    // 使用递归的函数
//{
//	long ans;
//	if (n > 0)
//		ans = n * rfact(n - 1);
//	else
//		ans = 1;
//	return  ans;
//}

//#include <stdio.h>
//
//int main()
//{
//    int n;
//    printf("请输入n的值：");
//    scanf_s("%d", &n);
//    if (n == 1)
//    {
//        printf("第1项为1\n");
//    }
//    else if (n == 2)
//    {
//        printf("第2项为2\n");
//    }
//    else if (n == 3)
//    {
//        printf("第3项为3\n");
//    }
//    else 
//    {
//        int f1 = 1, f2 = 2, f3 = 3;
//        int i, fn = 0;
//        for (i = 4; i <= n; i++)
//        {
//            fn = f1 + f2 + f3;
//            f1 = f2;
//            f2 = f3;
//            f3 = fn;
//        }
//        printf("第%d项为%d\n", n, fn);
//    }
//    return 0;
//}

//#include <iostream>
//#include <cstring>
//#include <cstdio>
//#include <cstdlib>
//#include <cmath>
//#include <iomanip>
//#include <algorithm>
//#include <set>
//using namespace std;
//#define NUM 10000
//
//long long dp[1000000];
//
//int main()
//{
//	int n;
//	cin >> n;
//	dp[1] = 1;
//	dp[2] = 1;
//	dp[3] = 1;
//	for (int i = 4; i <= n; i++) {
//		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
//	}
//	cout << dp[n] << endl;
//	long long x = dp[n]%NUM + 90000;
//	cout << x;
//	system("pause");
//	return 0;
//}

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int ai[100010], qi[100010];

int main()
{
	int a, q;
	while (cin >> a >> q)
	{
		for (int i = 0; i < a; i++)cin >> ai[i];
		for (int i = 0; i < q; i++)cin >> qi[i];
		for (int i = 0; i < q; i++)
		{
			int left = 0, right = a - 1, mid;
			while (left < right)
			{
				mid = (left + right) >> 1;
				if (ai[mid] <= qi[i])left = mid + 1;
				else right = mid;
			}
			if (left - 1 < 0 || ai[left] < qi[i])left++;
			i ? cout << " " << ai[left - 1] : cout << ai[left - 1];
		}
		cout << endl;
	}
	return 0;
}