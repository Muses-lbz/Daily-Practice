//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//    int ma, mi, a;
//    cin >> a;
//    mi = ma = a;
//    for (int i = 1; i < n; i++)
//    {
//        cin >> a;
//        if (ma < a) ma = a;
//        if (mi > a) mi = a;
//    }
//    cout << ma << endl << mi << endl;
//}

//#include <string>
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    string s1, s2;
//    cout << "请输入第一个字符串：";
//    cin >> s1;
//    cout << "请输入第二个字符串：";
//    cin >> s2;
//    if (s1.find(s2) != -1)
//        cout << s1.find(s2) << endl;
//    else
//        cout << "没有找到该字符串" << endl;
//    system("pause");
//    return 0;
//}

//#include <stdio.h>   
//#include <stdlib.h>
//
//void to_binary(unsigned long n);
//
//int main()
//{
//	unsigned long number;
//	printf("Enter  an integer  (q  to  quit):\n");
//	while (scanf_s("%lu", &number) == 1)
//	{
//		printf("Binary  equivalent: ");
//		to_binary(number);
//		putchar('\n');
//		printf("Enter  an  integer  (q  to  quit):\n");
//	}
//	printf("Done.\n");
//	system("pause");
//	return  0;
//}
//
//void to_binary(unsigned long n)  /* 递归函数 */
//{
//	int r;
//	r = n % 2;
//	if (n >= 2)
//		to_binary(n / 2);
//	/*putchar(r == 0 ? '0' : '1');*/
//	if (r == 0)
//		putchar('0');
//	else if (r == 1)
//		putchar('1');
//	return;
//}
//

//#include <stdio.h>
//#include <stdlib.h>
//
//void mikado(int);  /* 函数原型 */
//
//int main()
//{
//	int pooh = 2, bah = 5; /* main()的局部变量 */
//	printf("In  main(),  pooh  =  %d  and  &pooh  =  %p\n", pooh, &pooh);
//	printf("In  main(),  bah  =   %d  and  &bah   =  %p\n", bah, &bah);
//	mikado(pooh);
//	return  0;
//}
//
//void mikado(int bah)	/* 定义函数 */
//{
//	int pooh = 10;	/* mikado()的局部变量*/
//	printf("In  mikado(),  pooh  =  %d  and  &pooh  =  %p\n", pooh, &pooh);
//	printf("In  mikado(),  bah   =  %d  and  &bah   =  %p\n", bah, &bah);
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int interchange(int u, int v); /* 声明函数 */
//
//int main(void)
//{
//	int  x = 5, y = 10;
//	printf("Originally  x  =  %d  and  y  =  %d.\n", x, y);
//	x = interchange(x, y);
//	printf("Now  x  =  %d  and  y  =  %d.\n", x, y);
//	return  0;
//}
//
//int interchange(int u, int v)  /*定义函数*/
//{
//	int  temp;
//	temp = u;
//	u = v;
//	v = temp;
//	return(u);
//}

#include <stdio.h>
#include <stdlib.h>

void interchange(int* u, int* v);

int  main()
{
	int  x = 5, y = 10;
	printf("Originally  x  =  %d  and  y  =  %d.\n", x, y);
	interchange(&x, &y);   // 把地址发送给函数
	printf("Now  x  =  %d  and  y  =  %d.\n", x, y);
	system("pause");
	return  0;
}

void interchange(int* u, int* v)
{
	int temp;
	temp = *u;    // temp 获得 u 所指向对象的值
	*u = *v;
	*v = temp;
}
