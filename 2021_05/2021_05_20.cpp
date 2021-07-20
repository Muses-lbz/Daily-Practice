//#include<stdio.h>
//
//int main()
//{
//	char str[][10] = { "China","Beijing" };
//	char *p = (char*)str;
//	printf("%s\n", p + 10);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h> 
//#include <windows.h> 
//
//int main()
//{
//	system("cls");
//	printf("H");
//	Sleep(1000);
//	system("cls");
//	printf(" H");
//	Sleep(1000);
//	system("cls");
//	printf("  H");
//	system("pause");
//	return 0;
//}

#include <stdio.h> 
#include <stdlib.h> 
#include <conio.h>
#include <windows.h>

int main()
{
	char a[50][50] = { "######",

   "#O #  ",

   "# ## #",

   "#  # #",

   "##   #",

   "######",

	};

	int i, x, y, p, q;
	char ch;

	x = 1; y = 1; p = 1; q = 5;

	for (i = 0; i <= 5; i++) puts(a[i]);

	ch = _getch(); if (ch == 's')
	{
		if (a[x + 1][y] != '#')
		{
			a[x][y] = ' '; x++; a[x][y] = 'O';
		}
	}
	system("cls");
	for (i = 0; i <= 5; i++)
		puts(a[i]);

	Sleep(5000); return 0;

}




