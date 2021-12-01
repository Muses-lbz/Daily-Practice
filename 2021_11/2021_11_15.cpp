//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//    FILE* fp;
//    errno_t err;                                    //不同点1
//    char ch, filename[10] = { 0 };
//    printf("请输入所用的文件名：");
//    scanf_s("%s", filename, 10);
//    if ((err = fopen_s(&fp, filename, "w")) != 0)    //不同点2
//    {
//        printf("无法打开此文件\n");            //如果打不开，就输出打不开
//        exit(0);                               //终止程序
//    }
//    ch = getchar();                            //用来接收最后输入的回车符
//    printf("请输入一个准备存储到磁盘的字符串（以#结束）：");
//    ch = getchar();                            //用来接收从键盘输入的第一个字符
//    while (ch != '#')                          //当输入“#”时结束循环
//    {
//        fputc(ch, fp);                         //向磁盘输出一个字符
//        putchar(ch);                           //将输出的字符显示在屏幕上
//        ch = getchar();                        //再接收从键盘输入的一个字符
//    }
//    fclose(fp);                                //关闭文件
//    putchar(10);                               //向屏幕输出一个换行符
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//    unsigned int N;
//    cout << "Please enter the value of N: ";
//    cin >> N;
//    if (N % 2 != 0)
//    {
//        cout << "Please enter an even number greater than zero!" << endl;
//        return -1;
//    }
//    int oddCount = 1;
//    int printCount = 0;
//    for (unsigned int i = 2; i <= N; i += 2)
//    {
//        for (int j = 0; j < oddCount; j++)
//        {
//            cout << i << " ";
//            printCount++;
//            if (printCount == N)
//            {
//                cout << "<---这个就是第N = " << N << "个数。" << endl;
//                return 0;
//            }
//        }
//        oddCount += 2;
//    }
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//void merge(int* a1, int m, int* a2, int n)
//{
//    int m1 = m - 1;
//    int n1 = n - 1;
//    for (int i = m + n - 1; i >= 0; i--)
//    {
//        if (m1 < 0) a1[i] = a2[n1--];
//        else if (n1 < 0) a1[i] = a1[m1--];
//        else if (a1[m1] < a2[n1]) a1[i] = a2[n1--];
//        else a1[i] = a1[m1--];
//    }
//}
//
//int main()
//{
//    int m;
//    int n;
//    cin >> m;
//    cin >> n;
//    int a1[201];
//    int a2[101];
//    for (int i = 0; i < m; i++) cin >> a1[i];
//    for (int i = 0; i < n; i++) cin >> a2[i];
//    merge(a1, m, a2, n);
//    for (int i = 0; i < m + n; i++) cout << a1[i] << " ";
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//void revert(int n)
//{
//    if (n >= 0 && n <= 9)
//    {
//        cout << n << endl;
//    }
//    else
//    {
//        cout << n % 10 << endl;
//        revert(n / 10);
//    }
//}
//
//int main()
//{
//    int n = 12345;
//    revert(n);
//}

// 顺序搜索算法（专业外语大作业）

#include <stdio.h>
#include <stdlib.h>

#define N 20     //数据集中的元素个数
//实现顺序查找，arr[N] 为数据集，value 为要查找的目标元素
int linear_search(int arr[N], int value)
{
    int i;
    //从第 1 个元素开始遍历
    for (i = 0; i < N; i++)
    {
        //匹配成功，返回元素所处的位置下标
        if (arr[i] == value)
        {
            return i;
        }
    }
    //匹配失败，返回 -1
    return -1;
}

int main()
{
    int arr[N] = { 10,14,19,26,27,31,33,35,64,42,44,78 };
    int add = linear_search(arr, 64);
    if (add != -1)
    {
        printf("查找成功，为序列中第 %d 个元素\n\n", add + 1);
    }
    else
    {
        printf("查找失败\n\n");
    }
    system("pause");
    return 0;
}