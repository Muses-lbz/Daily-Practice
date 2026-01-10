//#include<stdio.h>
//
//int main()
//{
//	int a = 1;
//	int b = 2;
//	int c = 3;
//	int* parr[3] = { &a,&b,&c };
//	for (int i = 0; i < 3; i++)
//	{
//		printf("%d", *(parr[i]));
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//    const char* parr[3] = { "abcdef","zhang","wang" };
//    for (int i = 0; i < 3; i++)
//    {
//        printf("%s ", parr[i]);
//    }
//    return 0;
//}

//int main()
//{
//	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
//	int* p = arr;//arr是首元素的地址
//	int(*parr)[10] = &arr;//&arr是整个数组的地址，存放在指针数组里
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
//	printf("%p\n", arr);
//	printf("%p\n", &arr[0]);
//	printf("%p\n\n", &arr);
//
//	printf("%p\n", arr + 1);
//	printf("%p\n", &arr[0] + 1);
//	printf("%p\n\n", &arr + 1);
//	return 0;
//}

//#include<stdio.h>
//void Print(int arr[])
//{
//	//或者void Print(int arr[5])
//	//或者void Print(int* parr)
//	//
//}
//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//	Print(arr);
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

int main()
{
	char str[50][50] = { "*蔺******","**兵*****","***姿****","****我***","*****想**","******你*" };
	int love = 10;
	for (int i = 0; i <= 5; i++)
		puts(str[i]);
	char ch;
	while (love)
	{
		ch = _getch();
		if (ch == 'y')
		{
			printf("汉语言文学\n");
		}
		else if (ch == 'n')
		{
			printf("失败\n");
			love = 0;
		}
		else
		{
			printf("未知\n");
			love = 0;
		}
	}
	system("pause");
	return 0;
}
