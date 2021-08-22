//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//int main()
//{
//	char Key[32] = { 0 };
//	printf("请输入注册码:");
//	gets_s(Key);
//	if (strcmp(Key, "abc123456") == 0)
//	{
//		printf("注册成功\n\n");
//	}
//	else
//	{
//		printf("注册失败\n\n");
//	}
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	char iKey[32] = { 0 };
	char Key[32] = { 0 };
	int iID = 0xabc1d3f;
	sprintf_s(Key, "%x", iID * 8 + 123456);
	printf("你的机器码是%x\n", iID);
	printf("请输入注册码:");
	gets_s(iKey);
	if (strcmp(Key, iKey) == 0)
	{
		MessageBoxA(0, "注册成功","", MB_OK);
	}
	else
	{
		MessageBoxA(0, "注册失败","", MB_OK);
	}
	system("pause");
	return 0;
}