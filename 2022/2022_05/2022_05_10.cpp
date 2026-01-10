#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Time
{
public:

	Time(int h, int m, int s)
	{
		hours = h;
		minutes = m;
		seconds = s;
	}
	void display()
	{
		cout << "出生时间:" << hours << "时" << minutes << "分" << seconds << "秒" << endl;
	}
protected:
	int hours;
	int minutes;
	int seconds;
};


class Date
{
public:
	Date(int y, int mon, int d)
	{
		year = y;
		month = mon;
		day = d;
	}
	~Date()
	{
		cout << "**********************" << endl;
	}
	void display()
	{
		cout << "出生年月:" << year << "年" << month << "月" << day << "日" << endl;
	}
protected:
	int year;
	int month;
	int day;
};

class BirthTime : public Time, Date
{
private:
	string childname;
public:
	BirthTime(string name, int hour, int minute, int second, int year, int month, int day) :Time(hour, minute, second), Date(year, month, day)
	{
		childname = name;
	}
	void display()
	{
		cout << "**********************" << endl;
		cout << "" << childname << endl;
		cout << "======================" << endl;
		Date::display();
		cout << "======================" << endl;
		Time::display();
	}
};


int main()
{
	BirthTime bet("李小丫", 12, 45, 10, 1999, 4, 19);
	bet.display();
	system("pause");
	return 0;
}
