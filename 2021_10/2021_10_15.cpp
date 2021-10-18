//#include <iostream>
//using namespace std;
////CSDN的垃圾代码无法运行
//int main() 
//{
//    while (1)
//    {
//        int a;
//        cin >> a;
//        int* ptr = new int[a][a];
//        for (int i = 0; i < a; i++)
//            for (int j = 0; j < a; j++)
//            {
//                if (j < i)
//                    ptr[i][j] = i + 1 - j;
//                else
//                    ptr[i][j] = 1;
//            }
//        cout << "Generated matrix:" << endl;
//        for (int i = 0; i < a; i++)
//        {
//            for (int j = 0; j < a; j++)
//            {
//                cout << ptr[i][j];
//            }
//            cout << endl;
//        }
//        cout << "del the elements on the side:" << endl;
//        for (int i = 1; i < a - 1; i++)
//        {
//            for (int j = 1; j < a - 1; j++)
//            {
//                cout << ptr[i][j];
//            }
//            cout << endl;
//        }
//        int sum = 0;
//        int i, j;
//        for (i = a - 2, j = 1; i >= 1; i--, j++)
//        {
//            sum += ptr[i][j];
//        }
//        cout << "The sum of the diagonal:" << sum << endl;
//    } 
//    delete []ptr;
//    ptr = nullptr;
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int* ptr = new int[n];
//	for (auto i = 0; i < n; i++)
//	{
//		cin >> ptr[i];
//	}
//	int x = 0;
//	cin >> x;
//	auto j = 0;
//	auto status = 0;
//	for (; j < n; ++j)
//	{
//		if (ptr[j] == x)
//		{
//			status = 1;
//			break;
//		}
//	}
//	if (status == 0)
//	{
//		j = -1;
//	}
//	cout << j << endl;
//	delete[] ptr;
//	cin.get();
//	cin.get();
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int cnt = 0;
    scanf_s("%d", &n);
    for (int a = 1; a < n; a++)
        for (int b = a; b < n - a; b++)
            for (int c = 1; c < n; c++)
            {
                if ((a + b) * (a + b) + c * c == n * n)
                {
                    printf("a=%d b=%d c=%d\n", a, b, c);
                    cnt++;
                }
            }
    printf("一共有%d种方案", cnt);
    system("pause");
    return 0;
}