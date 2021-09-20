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
