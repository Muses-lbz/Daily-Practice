//#include <stdio.h>
//#include <stdlib.h>
//
//int isPrime(int n)
//{
//    int i = 2;
//    if (n < 2) return 0;
//    for (i = 2; i < n; i++)
//    {
//        if (n % i == 0)
//            return 0;
//    }
//    return 1;
//}
//
//int CountPrime(int a[], int size)
//{
//    int i = 0, count = 0;
//    for (i = 0; i < size; i++)
//    {
//        if (isPrime(a[i]))
//        {
//            printf("%d ", a[i]);
//            count++;
//            if (count % 10 == 0)
//                printf("\n");
//        }
//    }
//    printf("\n");
//    return count;
//}
//
//int main()
//{
//    int a[100], i, count = 0;
//    for (i = 0; i < 100; i++)
//        a[i] = rand() % 1000;
//    printf("素数的个数:%d\n", CountPrime(a, 100));
//    return 0;
//}

//#include <iostream>
//#include <time.h>
//#include <stdlib.h>
//using namespace std;
//
//void InsertSort(int a[], int n)
//{
//    for (int i = 1; i < n; i++)
//    {
//        if (a[i] < a[i - 1])
//        {
//            int j = i - 1;
//            int x = a[i];
//            a[i] = a[i - 1];
//            while (x < a[j])
//            {
//                a[j + 1] = a[j];
//                j--;
//            }
//            a[j + 1] = x;
//        }
//    }
//}
//int main()
//{
//    cout << "请输入产生多个随机数：";
//    int ranNum[100], num = 0;
//    srand((unsigned)time(NULL));
//    cin >> num;
//    cout << "随机数组：";
//    for (int i = 0; i < num; i++)
//    {
//        ranNum[i] = 10 + (rand() % 80);
//        cout << " " << ranNum[i];
//    }
//    cout << endl;
//    InsertSort(ranNum, num);
//    cout << "排序后整数序列：";
//    for (int j = num - 1; j >= 0; j--)
//    {
//        cout << ranNum[j] << " ";
//    }
//    cout << endl;
//    system("pause");
//    return 0;
//}

#include <iostream>
#include <string>
using namespace std;

string a[1000];
int main()
{
    int i, n;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[i] > a[j])
                swap(a[i], a[j]);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << endl;
    return 0;
}