//#include <stdio.h>
//int main()
//{
//	int num;
//	scanf("%d", &num);
//	printf("%0x", num);
//	return 0;
//}

//#include<stdio.h>
//#include<Windows.h>
//
//int main()
//{
//
//	printf("------------------------------------\n");
//
//	printf("Province      Area(km2)   Pop.(10K)\n");
//
//	printf("------------------------------------\n");
//
//	printf("Anhui         139600.00   6461.00\n");
//
//	printf("Beijing        16410.54   1180.70\n");
//
//	printf("Chongqing      82400.00   3144.23\n");
//
//	printf("Shanghai        6340.50   1360.26\n");
//
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
//
//	printf("Zhejiang      101800.00   4894.00\n");
//
//	printf("------------------------------------\n");
//
//	return 0;
//
//}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <windows.h>

int main()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//设置当前输出为红色

    printf("这行文字是红色的!\n");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);  //设置当前输出为白色

    printf("这行文字是白色的!\n");  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE); //设置当前输出为蓝色

    printf("这行文字是蓝色的!\n");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);  //设置当前输出为白色

    return 0;
}
