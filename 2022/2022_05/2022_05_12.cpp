#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define y2 2022
#define m2 12
#define d2 05

int Deadline(int y, int m, int d);
int Islove();

int main()
{
	int y, m, d;
	cin >> y >> m >> d;
	cout << endl << "You have " << Deadline(y, m, d) << " days!" << endl;
	Islove();
	system("pause");
	return 0;
}

int Deadline(int y, int m, int d)
{
	int num = 1;
	while (y * 10000 + m * 100 + d < y2 * 10000 + m2 * 100 + d2)
	{
		if (m == 12 && d == 32)//一年的最后一天
		{
			y++;
			m = 1;
			d = 1;
			continue;
		}
		if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10) && d == 32)//大月的最后一天
		{
			d = 1;
			m++;
			continue;
		}
		if ((m == 4 || m == 6 || m == 9 || m == 11) && d == 31)//小月的最后一天
		{
			d = 1;
			m++;
			continue;
		}
		if (m == 2 && (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) && d == 30)//闰年2月的最后一天
		{
			d = 1;
			m++;
			continue;
		}
		if (m == 2 && !(y % 4 == 0 && y % 100 != 0 || y % 400 == 0) && d == 29)//平年2月的最后一天
		{
			d = 1;
			m++;
			continue;
		}
		d++;
		num++;
	}
	return num - 1;
}

int Islove()
{
	srand((unsigned int)time(NULL));
	int love = rand() % 2;
	if (love == 1)
	{
		cout << endl << "Lbz, I Love You! But I can't." << endl;
	}
	else
	{
		while (love != 1)
		{
			int i = 1;
			love = rand() % 2;
			if (love == 1)
			{
				cout << endl << "Lbz, I Love You! But I can't." << endl;
			}
			i++;
			cout << i << endl;
		}
	}
	return 0;
}