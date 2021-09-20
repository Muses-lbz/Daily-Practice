#include <stdio.h>
#include <stdlib.h>

int main()
{
	char a[11];
	gets_s(a);//可输入字符数量比定义的N指少1，最后一个需要用来存储字符串的结束标记‘\0'。
	printf("%s", a);
	system("pause");
	return 0;
}
