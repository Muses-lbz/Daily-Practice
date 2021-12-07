//#include <iostream>
//#include <string>
//using namespace std;
//
//string a[1000];
//
//int main()
//{
//	int i, n;
//	cin >> n;
//	for (i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//	}
//	for (i = 1; i <= n; i++)
//	{
//		for (int j = i + 1; j <= n; j++)
//		{
//			if (a[i] > a[j])
//				swap(a[i], a[j]);
//		}
//	}
//	for (int i = 1; i <= n; i++)
//		cout << a[i] << endl;
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int i, n, a[11] = { 0 }, x;
//    scanf_s("%d", &n);
//    for (i = 0; i < n; i++)
//    {
//        scanf_s("%d", &x);
//        if (x <= 9)
//            a[1]++;
//        else if (x > 9 && x <= 19)
//            a[2]++;
//        else if (x > 19 && x <= 29)
//            a[3]++;
//        else if (x > 29 && x <= 39)
//            a[4]++;
//        else if (x > 39 && x <= 49)
//            a[5]++;
//        else if (x > 49 && x <= 59)
//            a[6]++;
//        else if (x > 59 && x <= 69)
//            a[7]++;
//        else if (x > 69 && x <= 79)
//            a[8]++;
//        else if (x > 79 && x <= 89)
//            a[9]++;
//        else
//            a[10]++;
//    }
//    for (i = 1; i <= 10; i++)
//    {
//        if (a[i] > 0)
//        {
//            printf("%d-%d:%d\n", i * 10 - 10, i * 10 - 1, a[i]);
//        }
//    }
//}

#include <stdio.h>
#include <stdlib.h>

int imin(int, int);

int main()
{
	int  evil1, evil2;
	printf("Enter a pair of integers (q to quit):\n");
	while (scanf_s("%d %d", &evil1, &evil2) == 2)
	{
		printf("The lesser of %d and %d is %d.\n", evil1, evil2, imin(evil1, evil2));
		printf("Enter a pair of integers (q to quit):\n");
	}
	printf("Bye.\n");
	system("pause");
	return 0;
}

int imin(int n, int m)
{
	int min;
	if (n < m)
		min = n;
	else
		min = m;
	return  min;
}
