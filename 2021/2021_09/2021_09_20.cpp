//#include <stdio.h> 
//#include <stdlib.h> 
//#include <conio.h>
//
//int main()
//{
//	char a;
//	/*a = getchar();*/
//	/*a = _getche();*/
//	a = _getch();
//	printf("你刚才输入的字符是%c\n", a);
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int i;
//	for (i = 0; i <= 127; i++)
//	{
//		printf("%d %c\n", i, i);
//	}
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	char a[11];
//	gets_s(a);//可输入字符数量比定义的N指少1，需要留一个空位
//	printf("%s", a);
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//
//	char a[101], b[101];
//	int x, y; 
//	gets_s(a);
//	scanf_s("%d", &x);
//	while (getchar() != '\n');
//	gets_s(b);
//	scanf_s("%d", &y); 
//	if (x > y)
//	{
//		printf("%s\n", a);
//	}
//	else
//	{
//		if (x < y)
//		{
//			printf("%s\n", b);
//		}
//		else
//		{
//			printf("%s和%s的分数相同\n", a, b);
//		}
//	}
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main()
//{
//	char a[101] = { 0 }, t;
//	int len, i, j;
//	gets_s(a);
//	len = strlen(a);
//	for (i = 0; i <= len - 2; i++)
//	{
//		for (j = i + 1; j <= len - 1; j++)
//		{
//			if (a[i] > a[j])
//			{
//				t = a[i]; a[i] = a[j]; a[j] = t;
//			}
//		}
//	}
//	puts(a);
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main()
//{
//
//	char a[101] = { 0 }, b[101] = { 0 };
//	gets_s(a);
//	gets_s(b);
//	if (strcmp(a, b) <= 0)
//	{
//		puts(a);
//		puts(b);
//	}
//	else
//	{
//		puts(b);
//		puts(a);
//	}
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main()
//{
//	char a[5][11], t[11];
//	int i, j;
//	for (i = 0; i <= 4; i++)
//	{
//		gets_s(a[i]);
//	}
//	for (i = 0; i <= 3; i++)
//	{
//		for (j = i + 1; j <= 4; j++)
//		{
//			if (strcmp(a[i], a[j]) > 0)
//			{
//				strcpy_s(t, a[i]);
//				strcpy_s(a[i], a[j]);
//				strcpy_s(a[j], t);
//			}
//		}
//	}
//	for (i = 0; i <= 4; i++)
//	{
//		puts(a[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

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
	x = 1;
	y = 1;
	p = 1;
	q = 5;
	for (i = 0; i <= 5; i++)
		puts(a[i]);
	while (x != p || y != q)
	{
		ch = _getch();
		if (ch == 's')
		{
			if (a[x + 1][y] != '#')
			{
				a[x][y] = ' ';
				x++;
				a[x][y] = 'O';
			}
		}
		if (ch == 'w')
		{
			if (a[x - 1][y] != '#' && x >= 2)
			{
				a[x][y] = ' ';
				x--;
				a[x][y] = 'O';
			}
		}
		if (ch == 'a')
		{
			if (a[x][y - 1] != '#' && y >= 2)
			{
				a[x][y] = ' ';
				y--;
				a[x][y] = 'O';
			}
		}
		if (ch == 'd')
		{
			if (a[x][y + 1] != '#')
			{
				a[x][y] = ' ';
				y++; a[x][y] = 'O';
			}
		}
		system("cls");
		for (i = 0; i <= 5; i++)
			puts(a[i]);
	}
	system("cls");
	printf("You win! \n");
	Sleep(5000);
	return 0;
}
