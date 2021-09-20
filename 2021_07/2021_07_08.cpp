#include <stdio.h>
#include <stdlib.h>

int main()
{
	char a[11];
	gets_s(a);//可输入字符数量比定义的N指少1，需要留一个空位
	printf("%s", a);
	system("pause");
	return 0;
}
