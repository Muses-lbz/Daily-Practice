#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<string.h>
#include<stdlib.h> 

void func(char* p)
{
	strcpy(p, "hello world");
}

void test01()
{
	//在test01中分配了内存，分配在栈上
	char buf[1024] = { 0 };
	func(buf);
	printf("%s\n", buf);
}

void printString(char* str)
{
	printf("%s\n", str);
}

void test02()
{
	char* p = (char*)malloc(sizeof(char) * 64);
	if (p == 0)
	{
		printf("error!");
	}
	else
	{
		memset(p, 0, 64);//将内存块清零
		strcpy(p, "hello world");
		printString(p);
	}

}

int main()
{
	test02();
	system("pause");
	return 0;
}

