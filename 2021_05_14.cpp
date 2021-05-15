//#include<stdio.h>
//
//int exchange(int centimeter);
//
//int main()
//{
//	int centimeter;
//	scanf("%d",&centimeter);
//	exchange(centimeter);
//	return 0;
//}
//
//int exchange(int centimeter)
//{
//	int foot, inch;
//	foot = centimeter / 30.48;
//	inch = 12 * (centimeter / 30.48 - foot);
//	printf("%d %d", foot,inch);
//	return 0;
//}

//#include<stdio.h>
//
//int output(int nowtime,int second);
//
//int main()
//{
//	int nowtime,second;
//	scanf("%d %d", &nowtime,&second);
//	output(nowtime, second);
//	return 0;
//}
//
//int output(int nowtime, int second)
//{
//	int n, m, p, q;
//	n = nowtime % 100;
//	m = n + second;
//	if (second >= 0 || m >= 0)
//	{
//		p = m / 60;
//		q = (nowtime / 100) + p;
//		printf("%03d", q * 100 + m % 60);
//	}
//	else
//	{
//		m = m + 60;
//		p = m / 60;
//		q = (nowtime / 100) - 1 + p;
//		printf("%03d", q * 100 + m % 60);
//
//	}
//	return 0;
//}

//#include<stdio.h>
//
//int output(int num);
//
//int main()
//{
//	int num;
//	scanf("%d", &num);
//	output(num);
//	return 0;
//}
//
//int output(int num)
//{
//	int n, m, p;
//	n = num % 10;
//	m = (num % 100 - n) / 10;
//	p = (num - 10 * m - n) / 100;
//	if (n != 0)
//	{
//		printf("%d%d%d", n, m, p);
//	}
//	else if (n == 0, m != 0)
//	{
//		printf("%d%d", m, p);
//	}
//	else
//	{
//		printf("%d", p);
//	}
//	return 0;
//
//}

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(){
    int t1,t2,h1,h2,m1,m2;
    scanf("%d %d",&t1,&t2);
    h1=t1/100;
    m1=t1%100;
    
    if(t2>=0){
        h1=h1+(m1+t2)/60;
        m1=(m1+t2)%60; 
    }
    else{ 
        int con=h1*60+m1+t2;
        h1=con/60;
        m1=con%60;
    }
    printf("%d%02d",h1,m1);//重要的部分 %02d……
    return 0;
}