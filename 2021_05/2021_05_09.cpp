#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
	for (int a = 2; a >= 0; a--)
	{
		for (int b = 60; b >= 0; b--)
		{
			system("cls");
			if (a == 2)
			{
				printf("%d:00", a);
				Sleep(500);
				a = a - 1;
			}
			else if (a == 0 && b == 60)
			{
				continue;
			}
			else if ((b <= 9 && b >= 0) && (a == 1 || a == 0))
			{
				printf("%d:0%d", a, b);
				Sleep(500);
			}
			else
			{
				printf("%d:%d", a, b);
				Sleep(500);
			}
		}
	}
	system("cls");
	printf("点火！\n");
	system("pause");
	return 0;
}
