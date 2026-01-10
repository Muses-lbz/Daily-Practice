//#include <cstdio>
//#include <exception>
//
//int MinInOrder(int* numbers, int index1, int index2);
//
//int Min(int* numbers, int length)
//{
//    if (numbers == nullptr || length <= 0)
//        throw new std::exception("Invalid parameters");
//
//    int index1 = 0;
//    int index2 = length - 1;
//    int indexMid = index1;
//    while (numbers[index1] >= numbers[index2])
//    {
//        // 如果index1和index2指向相邻的两个数，
//        // 则index1指向第一个递增子数组的最后一个数字，
//        // index2指向第二个子数组的第一个数字，也就是数组中的最小数字
//        if (index2 - index1 == 1)
//        {
//            indexMid = index2;
//            break;
//        }
//
//        // 如果下标为index1、index2和indexMid指向的三个数字相等，
//        // 则只能顺序查找
//        indexMid = (index1 + index2) / 2;
//        if (numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1])
//            return MinInOrder(numbers, index1, index2);
//
//        // 缩小查找范围
//        if (numbers[indexMid] >= numbers[index1])
//            index1 = indexMid;
//        else if (numbers[indexMid] <= numbers[index2])
//            index2 = indexMid;
//    }
//
//    return numbers[indexMid];
//}
//
//int MinInOrder(int* numbers, int index1, int index2)
//{
//    int result = numbers[index1];
//    for (int i = index1 + 1; i <= index2; ++i)
//    {
//        if (result > numbers[i])
//            result = numbers[i];
//    }
//
//    return result;
//}
//
//// ====================测试代码====================
//void Test(int* numbers, int length, int expected)
//{
//    int result = 0;
//    try
//    {
//        result = Min(numbers, length);
//
//        for (int i = 0; i < length; ++i)
//            printf("%d ", numbers[i]);
//
//        if (result == expected)
//            printf("\tpassed\n");
//        else
//            printf("\tfailed\n");
//    }
//    catch (...)
//    {
//        if (numbers == nullptr)
//            printf("Test passed.\n");
//        else
//            printf("Test failed.\n");
//    }
//}
//
//int main(int argc, char* argv[])
//{
//    // 典型输入，单调升序的数组的一个旋转
//    int array1[] = { 3, 4, 5, 1, 2 };
//    Test(array1, sizeof(array1) / sizeof(int), 1);
//
//    // 有重复数字，并且重复的数字刚好的最小的数字
//    int array2[] = { 3, 4, 5, 1, 1, 2 };
//    Test(array2, sizeof(array2) / sizeof(int), 1);
//
//    // 有重复数字，但重复的数字不是第一个数字和最后一个数字
//    int array3[] = { 3, 4, 5, 1, 2, 2 };
//    Test(array3, sizeof(array3) / sizeof(int), 1);
//
//    // 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
//    int array4[] = { 1, 0, 1, 1, 1 };
//    Test(array4, sizeof(array4) / sizeof(int), 0);
//
//    // 单调升序数组，旋转0个元素，也就是单调升序数组本身
//    int array5[] = { 1, 2, 3, 4, 5 };
//    Test(array5, sizeof(array5) / sizeof(int), 1);
//
//    // 数组中只有一个数字
//    int array6[] = { 2 };
//    Test(array6, sizeof(array6) / sizeof(int), 2);
//
//    // 输入nullptr
//    Test(nullptr, 0, 0);
//
//    return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//int fun(int x)
//{
//    int countx = 0;
//    while (x)
//    {
//        countx++;
//        x = x & (x - 1);
//    }
//    printf("%d\n", countx);
//    return countx;
//}
//int main()
//{
//    fun(500);
//    system("pause");
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	char a = '\oxa';
//	printf("%d\n", a);
//	system("pause");
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	char a = '\72';
//	printf("%c\n", a);
//	printf("%d\n", sizeof(a));
//	system("pause");
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int a, b, result;
//	a = 5;
//	b = 2;
//	a = a + 1;
//	result = a + b;
//	printf("%d\n", a);
//	system("pause");
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//	A():m_iVal(0)
//	{
//		test();
//	}
//	virtual void func()
//	{
//		cout << m_iVal << endl;
//	}
//	void test()
//	{
//		func();
//	}
//public:
//	int m_iVal;
//};
//
//class B : public A
//{
//public:
//	B()
//	{
//		test();
//	}
//	virtual void func()
//	{
//		++m_iVal;
//		cout << m_iVal << endl;
//	}
//};
//
//int main()
//{
//	A* p = new B;
//	p->test();
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//void print_value(int* x)
//{
//	printf("%x\n", ++ * x);
//}
//
//int main()
//{
//	int a = 25;
//	print_value(&a);
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<stdio.h>
//using namespace std;
//
//int main()
//{
//	int m = 0123, n = 123;
//	printf("%o %o\n", m, n);
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//char* getMem(void)
//{
//    char p[] = "hello world";
//    p[5] = 0x0;
//    return p;
//}
//
//int test() 
//{
//    char* s = 0x0;
//    s = getMem();
//    printf(s);
//    return 0;
//}
//
//int main()
//{
//    test();
//	system("pause");
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int a[4][4] = { {1,2,3,4},{5,6,7,8},{11,12,13,14},{15,16,17,18} };
//	int i = 0, j = 0, s = 0;
//	while (i++ < 4)
//	{
//		if (i == 2 || i == 4) 
//			continue;
//		j = 0;
//		do 
//		{ 
//			s += a[i][j]; j++; 
//		} while (j < 4);
//	}
//	printf("%d\n", s);
//	system("pause");
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//static int calc(int a, int b)
//{
//    int c;
//    if (a >= b)
//        c = (a == b) ? a : b;
//    else
//        c = a + b + calc(a + 2, b - 1);
//    printf("%d\n", c);
//    return 0;
//}
//
//int main()
//{
//    calc(2, 7);
//	system("pause");
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int b = 2, c;
//	c = (b << 2) / (3 || b);
//	printf("%d\n", c);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	char a = 0, ch;
//	while ((ch = getchar()) != '\n')
//	{
//		if (a % 2 != 0 && (ch >= 'a' && ch <= 'z'))
//			ch = ch - 'a' + 'A';
//		a++;
//		putchar(ch);
//	}
//	printf("\n");
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int a;
//	a = 7 & 3 + 12;
//	printf("%d\n", a);
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("hello world\n");
	system("pause");
	return 0;
}
