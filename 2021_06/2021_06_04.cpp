//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	printf("hello world.\n");
//	system("pause");
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//	int year, month, day;
//	while (scanf("%d %d %d", &year,&month,&day) != EOF)
//	{
//		if (month == 1 || month == 2)//判断month是否为1或2　
//			year--, month += 12;
//		int c = year / 100;
//		int y = year - c * 100;
//		int week = y + y / 4 + c / 4 - 2 * c + 26 * (month + 1) / 10 + day - 1;
//		while (week < 0)
//			week += 7;
//		week %= 7;
//		switch (week)
//		{
//		case 1:printf("Monday\n"); break;
//		case 2:printf("Tuesday\n"); break;
//		case 3:printf("Wednesday\n"); break;
//		case 4:printf("Thursday\n"); break;
//		case 5:printf("Friday\n"); break;
//		case 6:printf("Saturday\n"); break;
//		case 0:printf("Sunday\n"); break;
//		}
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int year, month, day;
//	while (cin >> year >> month >> day)
//	{
//		if (month < 3)
//		{
//			year -= 1;
//			month += 12;
//		}
//		char b[7][10] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
//		int c = int(year / 100), y = year - 100 * c;
//		int w = int(c / 4) - 2 * c + y + int(y / 4) + (26 * (month + 1) / 10) + day - 1;
//		w = (w % 7 + 7) % 7;
//		cout << b[w] << endl;
//	}
//	return 0;
//}

#include <iostream>
#include <cstdio>
using namespace std;

// 根据 年-月-日 通过蔡勒公式计算当前星期几
int day_of_week(int year, int month,int day)
{
    if (month == 1 || month == 2) 
    {
        month += 12;
        year -= 1;
    }
    int century = year / 100;
    year %= 100;
    int week = century / 4 - 2 * century + year + year / 4 + (13 * (month + 1)) / 5 + day - 1;
    week = (week % 7 + 7) % 7;
    if (week == 0) 
    {
        week = 7;
    }
    return week;
}
// 给定年月和第几周的星期几，求出是该月的几号几号
int day_of_demand(int year, int month, int count, int d_of_week) 
{
    int week = day_of_week(year, month, 1);// 计算该月1号是星期几
    // 1 + 7(n - 1) + (所求星期数 + 7 - 1号星期数) % 7
    int day = 1 + (count - 1) * 7 + (7 + d_of_week - week) % 7;
    return day;
}
// 元旦
void new_year_day(int year)
{
    printf("%d-01-01\n", year);
}
// 马丁·路德·金纪念日（1月的第三个星期一）
void martin_luther_king_day(int year) 
{
    printf("%d-01-%02d\n", year, day_of_demand(year, 1, 3, 1));
}
// 总统日（2月的第三个星期一）
void president_day(int year) 
{
    printf("%d-02-%02d\n", year, day_of_demand(year, 2, 3, 1));
}
// 阵亡将士纪念日（5月的最后一个星期一）
void memorial_day(int year) 
{
    // 从 6 月往前数
    int week = day_of_week(year, 6, 1);
    // 星期一的话，从 31 号往前数 6 天，否则，数 week - 2 天
    int day = 31 - ((week == 1) ? 6 : (week - 2));
    printf("%d-05-%02d\n", year, day);
}
// 国庆
void independence_day(int year)
{
    printf("%d-07-04\n", year);
}
// 劳动节（9月的第一个星期一）
void labor_day(int year)
{
    printf("%d-09-%02d\n", year, day_of_demand(year, 9, 1, 1));
}
// 感恩节（11月的第四个星期四）
void thanks_giving_day(int year) 
{
    printf("%d-11-%02d\n", year, day_of_demand(year, 11, 4, 4));
}
// 圣诞节
void christmas(int year) 
{
    printf("%d-12-25\n\n", year);
}
// 美国节日
void holiday_of_usa(int year) 
{
    new_year_day(year);
    martin_luther_king_day(year);
    president_day(year);
    memorial_day(year);
    independence_day(year);
    labor_day(year);
    thanks_giving_day(year);
    christmas(year);
}
int main()
{
    int year;
    while (cin >> year) 
    {
        holiday_of_usa(year);
    }
    return 0;
}
