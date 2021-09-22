#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

int main()
{
	char box[50][50] = { "   ###     ",
					   "   #*#     ",
					   "   # #     ",
					   "####O######",
					   "#*  OS O *#",
					   "#####O#####",
					   "    # #    ",
					   "    #*#    ",
					   "    ###    " };
	char ch;
	int x = 4, y = 5;//x,y坐标表示人所在的位置
	int a1 = 3, b1 = 4, a2 = 4, b2 = 4, a3 = 4, b3 = 7, a4 = 5, b4 = 5;//a,b坐标表示箱子初始位置
	int m1 = 1, n1 = 4, m2 = 4, n2 = 1, m3 = 4, n3 = 9, m4 = 7, n4 = 5;//m,n坐标表示箱子目标位置
	for (int i = 0; i <= 8; i++)
		puts(box[i]);
	while (a1 != m1 || b1 != n1 || a2 != m2 || b2 != n2 || a3 != m3 || b3 != n3 || a4 != m4 || b4 != n4)
	{
		ch = _getch();
		if (ch == 's')
		{
			if (x == 6 && y == 5)
			{
				continue;
			}
			else if (box[x + 1][y] == 'O')
			{
				box[x][y] = ' ';
				x++;
				box[x][y] = 'S';
				a4++;
				box[a4][b4] = 'O';
			}
			else if (box[a4 + 1][b4] == '*')
			{
				box[x - 1][y] = ' ';
				box[a4][b4] = ' ';
				a4++;
				box[x][y] = 'S';
				box[a4][b4] = '0';
			}
			else if (box[x + 1][y] != '#')
			{
				box[x][y] = ' ';
				x++;
				box[x][y] = 'S';
			}
		}
		if (ch == 'w')
		{
			if (x == 2 && y == 4)
			{
				continue;
			}
			else if (box[x - 1][y] == 'O')
			{
				box[x][y] = ' ';
				x--;
				box[x][y] = 'S';
				a1--;
				box[a1][b1] = 'O';
			}
			else if (box[a1 - 1][b1] == '*')
			{
				box[x + 1][y] = ' ';
				box[a1][b1] = ' ';
				a1--;
				box[x][y] = 'S';
				box[a1][b1] = '0';
			}
			else if (box[x - 1][y] != '#' && x >= 2)
			{
				box[x][y] = ' ';
				x--;
				box[x][y] = 'S';
			}
		}
		if (ch == 'a')
		{
			if (x == 4 && y == 2)
			{
				continue;
			}
			else if (box[x][y - 1] == 'O')
			{
				box[x][y] = ' ';
				y--;
				box[x][y] = 'S';
				b2--;
				box[a2][b2] = 'O';
			}
			else if (box[a2][b2 - 1] == '*')
			{
				box[x][y + 1] = ' ';
				box[a2][b2] = ' ';
				a2--;
				box[x][y] = 'S';
				box[a2][b2] = '0';
			}
			else if (box[x][y - 1] != '#' && y >= 2)
			{
				box[x][y] = ' ';
				y--;
				box[x][y] = 'S';
			}
		}
		if (ch == 'd')
		{
			if (x == 4 && y == 8)
			{
				continue;
			}
			else if (box[x][y + 1] == 'O')
			{
				box[x][y] = ' ';
				y++;
				box[x][y] = 'S';
				b3++;
				box[a3][b3] = 'O';
			}
			else if (box[a3][b3 + 1] == '*')
			{
				box[x][y - 1] = ' ';
				box[a3][b3] = ' ';
				a3--;
				box[x][y] = 'S';
				box[a3][b3] = '0';
			}
			else if (box[x][y + 1] != '#')
			{
				box[x][y] = ' ';
				y++;
				box[x][y] = 'S';
			}
		}
		system("cls");
		for (int i = 0; i <= 8; i++)
			puts(box[i]);
	}
	system("cls");
	printf("You win! \n");
	Sleep(5000);
	return 0;
}
