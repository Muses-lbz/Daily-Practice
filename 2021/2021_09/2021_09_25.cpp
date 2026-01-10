//#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <cmath>
//#include <queue>
//using namespace std;
//
//int a[100100];
//int people[500100];
//
//struct node
//{
//	int country;
//	int time;
//};
//
//queue<node>q;
//
//int main()
//{
//	int n, sum = 0;
//	scanf_s("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		int t, p;
//		scanf_s("%d%d", &t, &p);
//		node temp;
//		temp.time = t;
//		for (int i = 1; i <= p; i++)
//		{
//			int cty;
//			scanf_s("%d", &cty);
//			temp.country = cty;
//			q.push(temp);
//			if (!people[cty]) sum++;
//			people[cty]++;
//		}
//		while (1) {
//			node old;
//			old = q.front();
//			if (temp.time - 86400 >= old.time)
//			{
//				int tc = old.country;
//				people[tc]--;
//				if (!people[tc]) sum--;
//				q.pop();
//			}
//			else break;
//		}
//		cout << sum << endl;
//	}
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

double fun(int n)
{
    double sum = 1.0;
    int i;
    for (i = 1; i < n; i++)
        sum *= i;
    return sum;
}
int main()
{
    int i, mark = 1;
    double sum = 0, item = 1;
    for (i = 1; i <= 10; i++)
    {
        item = mark * fun(i);
        sum += item;
        mark = -mark;
    }
    printf("1!-2!+3!-4!+5!-6!+7!-8!+9!-10!=%.0lf\n", sum);
    system("pause");
    return 0;
}
