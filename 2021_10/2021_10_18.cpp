//#include <stdio.h> 
//
//int main()
//{
//	char  ch;
//	int  i;
//	float  fl;
//	fl = i = ch = 'C';  /* 第 9 行  */
//	printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl);  /* 第 10 行 */
//	ch = ch + 1;    /* 第 11 行 */
//	i = fl + 2 * ch;    /* 第 12 行 */
//	fl = 2.0 * ch + i;  /* 第 13 行 */
//	printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl);  /* 第 14 行 */
//	ch = 1107;  /* 第 15 行 */
//	printf("Now ch = %c\n", ch);    /* 第 16 行 */
//	ch = 80.89; /* 第 17 行 */
//	printf("Now ch = %c\n", ch);    /* 第 18 行 */
//	return  0;
//}

//#include <stdio.h> 
//
//void pound(int n);// ANSI 函数原型声明 
//
//int main()
//{
//	int  times = 5;
//	char ch = '!';     // ASCII码是 33 
//	float  f = 6.2f;
//	pound(times);// int类型的参数 
//	pound(ch);   // 和pound((int)ch); 相同 
//	pound(f);    //和pound((int)f); 相同 
//	return  0;
//}
//
//void pound(int n)      // ANSI 风格函数头
//{                         // 表明该函数接受一个int 类型的参数
//	int m = 0;
//	while (n-- > 0)
//	{
//		printf("#");
//		m++;
//	}
//	printf("%d", m);
//	printf("\n");
//}
//

//#include <stdio.h>
//
//const int S_PER_M = 60;          // 1 分钟的秒数 
//const int S_PER_H = 3600;        // 1 小时的秒钟数 
//const double M_PER_K = 0.62137;  // 1 公里的英里数 
//
//int  main()
//{
//	double distk, distm;  // 跑过的距离（分别以公里和英里为单位） 
//	double rate;          // 平均速度（以英里/小时为单位） 
//	int min, sec;         // 跑步用时（以分钟和秒为单位） 
//	int time;			  // 跑步用时（以秒为单位） 
//	double mtime;         // 跑 1 英里需要的时间，以秒为单位 
//	int mmin, msec;       // 跑 1 英里需要的时间，以分钟和秒为单位
//	printf("This  program  converts  your  time  for  a  metric  race\n");
//	printf("to  a  time  for running  a  mile and to  your average\n");
//	printf("speed  in  miles  per  hour.\n");
//	printf("Please enter,  in  kilometers,  the  distance  run.\n");
//	scanf_s("%lf", &distk);  // %lf 表示读取一个 double 类型的值 
//	printf("Next  enter  the  time  in minutes and seconds.\n");
//	printf("Begin  by  entering  the  minutes.\n");
//	scanf_s("%d", &min);
//	printf("Now  enter  the  seconds.\n");
//	scanf_s("%d", &sec);
//	time = S_PER_M * min + sec;       // 把时间转换成秒 
//	distm = M_PER_K * distk;          // 把公里转换成英里  
//	rate = distm / time * S_PER_H;  //  英里/秒×秒/小时 =  英里/小时  
//	mtime = (double)time / distm;  // 时间/距离 = 跑 1 英里所用的时间 
//	mmin = (int)mtime / S_PER_M;   // 求出分钟数  
//	msec = (int)mtime % S_PER_M;  // 求出剩余的秒数
//	printf("You  ran  %1.2f  km  (%1.2f  miles)  in  %d  min,  %d sec.\n", distk, distm, min, sec);
//	printf("That  pace  corresponds  to  running  a  mile  in  %d min,  ", mmin);
//	printf("%d  sec.\nYour  average  speed  was  %1.2f  mph.\n", msec, rate);
//	return  0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main()
//{
//	int i = 1;
//	float n=20;
//	printf("Watch  out!  Here  come  a  bunch  of fractions!\n");
//	while (i < 30)
//	{
//		n = 1 / i;
//		printf("%f", n);
//	}
//	printf("That's  all,  folks!\n"); 
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main()
//{
//	long num; 
//	long sum = 0L;        /* 把sum 初始化为 0  */
//	int  status; 
//	printf("Please  enter  an  integer  to  be summed  ");
//	printf("(q  to  quit):  ");
//	status = scanf_s("%ld", &num); 
//	while (status == 1)    /* == 的意思是“等于”  */
//	{
//		sum = sum + num;
//		printf("Please  enter  next  integer  (q  to  quit):  ");
//		status = scanf_s("%ld", &num);
//	}
//		printf("Those  integers  sum  to  %ld.\n", sum);
//	system("pause");
//	return 0;
//}

//#include <stdio.h> 
//
//int main()
//{ 
//	int  n = 0; 
//	while (n++ < 3)
//		;/* 第 7 行 */
//	printf("n is %d\n", n); /* 第 8 行*/ 
//	printf("That's  all  this  program does.\n"); 
//	return  0;
//}

//#include <stdio.h> 
//#include <math.h>
//
//int main()
//{
//	const double ANSWER = 3.14159;
//	double response;
//	printf("What  is  the  value of  pi?\n");
//	scanf_s("%lf", &response);
//	while (fabs(response - ANSWER) > 0.0001)
//	{
//		printf("Try  again!\n");
//		scanf_s("%lf", &response);
//	}
//	printf("Close enough!\n");
//	return  0;
//}

//#include <stdio.h> 
//#include <stdbool.h>
//
//int main()
//{  
//	long  num;  
//	long sum = 0L;
//	bool  input_is_good; 
//	printf("Please  enter  an  integer to  be  summed  "); 
//	printf("(q  to  quit): ");
//	input_is_good = (scanf_s("%ld", &num) == 1); 
//	while (input_is_good)
//	{
//		sum = sum + num;
//		printf("Please  enter  next  integer  (q  to  quit):  "); 
//		input_is_good = (scanf_s("%ld", &num) == 1);
//	}      
//	printf("Those  integers  sum  to  %ld.\n", sum); 
//	return  0;
//
//}

//#include <stdio.h>
//
//int main()
//{
//	int  t_ct;	//项计数  
//	double  time, power_of_2;
//	int  limit;
//	printf("Enter  the  number  of   terms  you  want : ");
//	scanf_s("%d", &limit);
//	for (time = 0, power_of_2 = 1, t_ct = 1; t_ct <= limit; t_ct++, power_of_2 *= 2.0)
//	{
//		time += 1.0 / power_of_2;
//		printf("time  =  %f when  terms  =  %d.\n", time, t_ct);
//	}
//	return 0;
//}

//#include <stdio.h> 
//
//int main()
//{
//	const  int  secret_code = 13;
//	int  code_entered;
//	do
//	{
//		printf("To  enter  the  triskaidekaphobia  therapy  club, \n");
//		printf("please  enter  the  secret  code  number : ");
//		scanf_s("%d", &code_entered);
//	} while (code_entered != secret_code);
//	printf("Congratulations!  You  are  cured!\n");
//	return 0;
//}
//

//#include <stdio.h>
//#include <stdlib.h>
//
//double power(double n, int p); // ANSI函数原型 
//
//int main()
//{
//	double  x, xpow;
//	int  exp;
//	printf("Enter  a  number  and  the  positive  integer  power");
//	printf("  to  which\nthe number  will  be  raised.Enter  q");
//	printf("  to  quit.\n");
//	while (scanf_s("%lf %d", &x, &exp) == 2)
//	{
//		xpow = power(x, exp);  // 函数调用 
//		printf("%.3g  to  the  power% d  is % .5g\n", x, exp, xpow);
//		printf("Enter  next pair  of  numbers or q  to  quit.\n");
//	}
//	printf("Hope  you  enjoyed  this  power  trip  -- bye!\n");
//	system("pause");
//	return  0;
//}
//
//double power(double n, int p)  // 函数定义
//{
//	double  pow = 1;
//	int  i;
//	for (i = 1; i <= p; i++)
//		pow *= n;
//	return pow;                   // 返回 pow 的值
//}

#include <stdio.h>
#define SPACE ' '	// SPACE 表示单引号-空格-单引号

int main()
{
	char ch;
	ch = getchar();           // 读取一个字符 
	while (ch != '\n')        // 当一行未结束时
	{
		if (ch == SPACE)      // 留下空格 
			putchar(ch);      // 该字符不变
		else
			putchar(ch + 1);  // 改变其他字符 
		ch = getchar();       // 获取下一个字符
	}
	putchar(ch);                // 打印换行符
	return 0;
}