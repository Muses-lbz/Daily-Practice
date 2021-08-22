#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char Key[32] = { 0 };
	printf("请输入注册码:");
	gets_s(Key);
	if (strcmp(Key, "abc123456") == 0)
	{
		printf("注册成功\n\n");
	}
	else
	{
		printf("注册失败\n\n");
	}
	system("pause");
	return 0;
}
