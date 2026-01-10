//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//int main()
//{
//	int i, n, a[105], t;
//	scanf_s("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf_s("%d", &a[i]);
//		if (i % 2 == 1)
//		{
//			if ((a[i] % 3 == 0) || (a[i] % 5 == 0) || (a[i - 1] % 3 == 0) || (a[i - 1] % 5 == 0))
//			{
//				t = a[i];
//				a[i] = a[i - 1];
//				a[i - 1] = t;
//			}
//		}
//	}
//	for (i = n - 1; i >= 0; i--)
//	{
//		printf("%d ", a[i]);
//	}
//	system("pause");
//	return 0;
//}

//#include <iostream>
//#include <stdlib.h>
//using namespace std;
//
//int main()
//{
//    int n, i, j, sum, a;
//    cin >> n;
//    a = 0;
//    i = 2;
//    sum = 0;
//    while (a < n)
//    {
//        for (j = 2; j <= i; j++)
//            if (i % j == 0)
//                break;
//        if (j == i)
//        {
//            sum += i;
//            ++a;
//        }
//        ++i;
//    }
//    cout << sum << endl;
//    system("pause");
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>

void print(int x)
{
	if (x == 0)printf("00");
	else if (x < 10)printf("0%d", x);
	else printf("%d", x);
	return;
}

int main()
{
	int n;
	scanf_s("%d", &n);
	int s, f, m;
	s = n / 3600;
	f = n / 60 % 60;
	m = n % 60;
	print(s);
	printf(":");
	print(f);
	printf(":");
	print(m);
	system("pause");
	return 0;
}