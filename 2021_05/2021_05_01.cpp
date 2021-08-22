#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <math.h>

int main()
{
	char iKey[32] = { 0 };
	char Key[32]  = { 0 };
	int iID = 0xabc1d3f;
	sprintf_s(Key, "%x", iID * 8 + 123456);
	printf("你的机器码是%x\n", iID);
	printf("请输入注册码:");
	gets_s(iKey);
	if (strcmp(Key, iKey) == 0)
	{
		printf("注册成功");
	}
	else
	{
		exit(0);
	}
	if (strcmp(Key, iKey) == 0)
	{
		printf("注册成功");
	}
	else
	{
		exit(0);
	}
	if (strcmp(Key, iKey) == 0)
	{
		printf("注册成功");
	}
	else
	{
		exit(0);
	}
	if (strcmp(Key, iKey) == 0)
	{
		printf("注册成功");
	}
	else
	{
		exit(0);
	}
	if (strcmp(Key, iKey) == 0)
	{
		printf("注册成功");
	}
	else
	{
		exit(0);
	}
	if (strcmp(Key, iKey) == 0)
	{
		printf("注册成功");
	}
	else
	{
		exit(0);
	}
	if (strcmp(Key, iKey) == 0)
	{
		printf("注册成功");
	}
	else
	{
		exit(0);
	}
	if (strcmp(Key, iKey) == 0)
	{
		printf("注册成功");
	}
	else
	{
		exit(0);
	}
	return 0;
}
