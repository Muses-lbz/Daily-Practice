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

