//#include <stdio.h>
//#include <stdlib.h>
//#include <windows.h>
//
//int main()
//{
//	printf("  O\n");
//	printf(" <H>\n");
//	printf(" I  I\n");
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
	int a = 0;
	while (a <= 2)
	{
		system("cls");
		int b = 1;
		while (b <= a)
		{
			printf(" ");
			b = b + 1;
		}

		int c = 1;
		printf(" O\n");
		while (c <= a)
		{
			printf(" ");
			c = c + 1;
		}

		int d = 1;
		printf("<H>\n");
		while (d <= a)
		{
			printf(" ");
			d = d + 1;
		}
		printf("I I\n");
		Sleep(1000);
		a = a + 1;
	}
	system("pause");
	return 0;
}
