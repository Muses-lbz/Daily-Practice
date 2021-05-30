//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//union myun
//{
//	struct { int x, y, z; } u;
//	int k;
//} a;
//
//int main()
//{
//	a.u.x = 4; a.u.y = 5; a.u.z = 6;
//	a.k = 0;
//	printf("%d\n", a.u.x);
//	system("pause");
//	return 0;
//}

//#include<iostream> 
//using namespace std;
//
//int main()
//{
//	int sum;
//	for (int i = 0; i < 6; i += 2)
//	{
//		sum = i;
//		for (int j = i; j < 6; j++)
//		{
//			if (i + j > 5) continue;
//			sum += j;
//		}
//	}
//	cout << sum << endl;
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int t1 = 2, t2 = 3, t3;
//	t3 = t1 < t2 ? t1 : (t2 + t1);
//	printf("%d", t3);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//
//void abc(char* str)
//{
//	int a, b;
//	for (a = b = 0; str[a] != '\0'; a++)
//		if (str[a] != 'c')
//			str[b++] = str[a];
//	str[b] = '\0';
//}
//
//int main()
//{
//	char str[] = "abcdef";
//	abc(str);
//	printf("str[] = % s", str);
//	return 0;
//}

//#include<stdio.h>
//
//char fun(char ch)
////int fun(char ch)
//{
//    if (ch >= '0' && ch<='9')
//        return '9' - (ch - '0');
//    return ch;
//}
//
//int main()
//{
//    char c1, c2;
//    printf("\nThe result:\n");
//    c1 = '2';
//    c2 = fun(c1);
//    printf("c1=%c c2=%c\n", c1, c2);
//    c1 = '8';
//    c2 = fun(c1);
//    printf("c1=%c c2=%c\n", c1, c2);
//    c1 = 'a';
//    c2 = fun(c1);
//    printf("c1=%c c2=%c\n", c1, c2);
//    return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//int a = 3;
//int main()
//{
//	int s = 0;
//	{
//		int a = 5; s += a++;
//	}
//	s += a++; printf("%d\n", s);
//	system("pause");
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void func(int* p)
{
	static int num = 4;
	p = &num;
	(*p)--;
}

int main()
{
	int i = 5;
	int* p = &i;
	func(p);
	printf("%d", *p);
	return 0;
}