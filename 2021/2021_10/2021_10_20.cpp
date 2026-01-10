//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string temp = "";
//	cout << "请输入字符串：";
//	cin >> temp;
//	string str = "";
//	string str1 = "";
//	for (unsigned int i = 0; i < temp.length(); i++)
//	{
//		string tempSub = temp.substr(i, 1);
//		int b = temp.rfind(tempSub);
//		if (i == b && str1.find(tempSub) == -1)
//			str += temp.substr(i, 1);
//		else if (str1.find(tempSub) == -1)
//			str1 += temp.substr(i, 1);
//	}
//	cout << "只出现一次的字符：" << str << endl;
//	cout << "重复出现的字符的字符：" << str1 << endl;
//	system("pause");
//	return 0;
//}

//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <cstdio>
//#include <math.h>
//#include <stack>
//#include <queue>
//using namespace std;
//
//int main()
//{
//    int i, j, k = 1;
//    int n, m;
//    int num[10] = { 0 };
//    int num_cmp = 0;
//    int flag = 1;
//    int led[15][15];
//    cin >> n >> m;
//    for (i = 1; i <= n; i++) 
//    {
//        for (j = 1; j <= m; j++) 
//        {
//            cin >> led[i][j];
//            if (led[i][j] == 1)  num[k]++;
//        }
//        if (num[k] != 0)k++;
//    }
//    num_cmp = num[k - 1];
//    for (i = k - 1; i > 0; i--)
//    {
//        if (num[i] < num_cmp)
//        {
//            flag++;
//            num_cmp = num[i];
//        }
//    }
//    if (flag == 1)
//        cout << "1" << endl;
//    else if (flag == 2) 
//        cout << "8" << endl;
//    else  
//        cout << "6" << endl;
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//void paixu(float* p, int n);
//
//int main()
//{
//    float f[10];
//    int i;
//    for (i = 0; i < 10; i++)
//        scanf_s("%f", &f[i]);
//    paixu(f, 10);
//    for (i = 0; i < 10; i++)
//        printf("%.2f ", f[i]);
//    system("pause");
//    return 0;
//}
//
//void paixu(float* p, int n)
//{
//    int i, j;
//    for (i = 0; i < n - 1; i++)
//    {
//        for (j = 0; j < n - 1 - i; j++)
//        {
//            if (fabs(p[j]) < fabs(p[j + 1]))
//            {
//                float tmp;
//                tmp = p[j];
//                p[j] = p[j + 1];
//                p[j + 1] = tmp;
//            }
//        }
//    }
//}

//#include <stdio.h>
//
//void display(char cr, int lines, int width);
//
//int main()
//{
//	int ch;		/* 待打印字符 */
//	int rows, cols;		/* 行数和列数 */
//	printf("Enter  a  character  and  two  integers:\n");
//	while ((ch = getchar()) != '\n')
//	{
//		scanf_s("%d  %d", &rows, &cols);
//		display(ch, rows, cols);
//		printf("Enter  another  character  and  two integers; \n");
//		printf("Enter  a  newline  to  quit.\n");
//	}
//	printf("Bye.\n");
//	return  0;
//}
//
//void display(char cr, int lines, int width)
//{
//	int  row, col;
//	for (row = 1; row <= lines; row++)
//	{
//		for (col = 1; col <= width; col++)
//			putchar(cr);
//		putchar('\n');/* 结束一行并开始新的一行 */
//	}
//}

#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

long get_long(void);// 验证输入是一个整数
bool bad_limits(long  begin, long  end, long  low, long  high);// 验证范围的上下限是否有效
double  sum_squares(long  a, long  b);// 计算 a～b 之间的整数平方和

int main()
{
	const long MIN = -10000000L;    // 范围的下限 
	long MAX = +10000000L;    // 范围的上限
	long start;// 用户指定的范围最小值
	long stop; // 用户指定的范围最大值 
	double answer;
	printf("This  program  computes  the  sum  of the  squares  of  " "integers  in  a  range.\nThe  lower  bound  should  not  " "be  less  than  -10000000  and\nthe  upper  bound  " "should  not be  more  than + 10000000.\nEnter  the  " "limits(enter  0  forboth  limits  to  quit) :\n""lower  limit:  ");
	start = get_long();
	printf("upper  limit:  ");
	stop = get_long();
	while (start != 0 || stop != 0)
	{
		if (bad_limits(start, stop, MIN, MAX))
			printf("Please  try  again.\n");
		else
		{
			answer = sum_squares(start, stop);
			printf("The  sum  of  the squares  of  the  integers  ");
			printf("from %ld  to %ld  is %g\n", start, stop, answer);
		}
		printf("Enter  the  limits  (enter  0  for  both " "limits  to  quit):\n");
		printf("lower  limit:  ");
		start = get_long();
		printf("upper  limit:   ");
		stop = get_long();
	}
	printf("Done.\n");
	system("pause");
	return  0;
}

long get_long(void)
{
	long input;
	char ch;
	while (scanf_s("%ld", &input) != 1)
	{
		while ((ch = getchar()) != '\n')
			putchar(ch);	// 处理错误输入
		printf("  is  not  an  integer.\nPlease  enter  an  ");
		printf("integer  value,  such  as  25, - 178, or 3:  ");
	}
	return input;
}

double sum_squares(long a, long b)
{
	double total = 0;
	long i;
	for (i = a; i <= b; i++)
		total += (double)i * (double)i;
	return total;
}

bool bad_limits(long begin, long end, long low, long high)
{
	bool not_good = false;
	if (begin > end)
	{
		printf("%ld  isn't  smaller  than  %ld.\n", begin, end);
		not_good = true;
	}
	if (begin < low || end < low)
	{
		printf("Values  must  be  %ld  or  greater.\n", low);
		not_good = true;
	}
	if (begin > high || end > high)
	{
		printf("Values  must  be  %ld  or  less.\n", high);
		not_good = true;
	}
	return not_good;
}